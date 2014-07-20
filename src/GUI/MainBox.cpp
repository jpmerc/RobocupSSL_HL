
#include "GUI/MainBox.h"
#include <QMenu>
#include <QMenuBar>


MainBox::MainBox(QWidget *parent)
    : QDialog(parent),mGame(NULL),
      mSimulatorCore(NULL){

    createGUI();
}

MainBox::~MainBox() {
    delete mQuitButton;
    delete mTestButton;

    delete mTabLayout;
    delete mMainLayout;

    delete mRobocupLabel;
    delete mInOutLabel;
    delete mControlLabel;
    delete mAILabel;
    delete mSimulatorLabel;

    delete mGameTab;
    delete mInOutTab;
    delete mControlTab;
    delete mAITab;
    delete mSimulatorTab;

    delete mMiniMap;
    delete mRefreshTimer;

    if(mGame){
        delete mGame;
    }

    delete mSimulatorCore;

    delete mMainTabWidget;
}

void MainBox::createGUI(){

    setWindowTitle(tr("Robocup Ulaval"));

    /*************************Buttons**********************************/

    mQuitButton = new QPushButton(tr("&Quit"));
    connect(mQuitButton, SIGNAL(clicked()), this, SLOT(close()));

    /*************************Label**********************************/

    mRobocupLabel = new QString("Robocup");
    mInOutLabel = new QString("In/Out");
    mControlLabel = new QString("Control");
    mAILabel = new QString("AI");
    mSimulatorLabel = new QString("Simulator");

    /*************************Menu**********************************/

    mMainTabWidget = new QTabWidget;

    /*************************TAB**********************************/

    mGameTab = new GameTab;
    mInOutTab = new InOutTab;
    mControlTab = new GenericTab;
    mAITab = new GenericTab;
    mSimulatorTab = new SimulatorTab;

    mMainTabWidget->addTab(mGameTab, *mRobocupLabel);
    mMainTabWidget->addTab(mInOutTab, *mInOutLabel);
    mMainTabWidget->addTab(mControlTab, *mControlLabel);
    mMainTabWidget->addTab(mAITab, *mAILabel);
    mMainTabWidget->addTab(mSimulatorTab, *mSimulatorLabel);

    mInOutTab->setEnabled(false);
    mControlTab->setEnabled(false);
    mAITab->setEnabled(false);
    mSimulatorTab->setEnabled(false);

    /*************************MAP**********************************/
    mMiniMap =new MiniMap( 600, 400,QImage::Format_Indexed8 );
    mRefreshTimer = new QTimer(this);
    connect(mRefreshTimer, SIGNAL(timeout()), this, SLOT(refreshScreen()));

    /*************************Layout**********************************/
    mTabLayout = new QHBoxLayout;
    mMainLayout = new QVBoxLayout;
    mTabLayout->addWidget(mMainTabWidget);
    mMainLayout->addLayout(mTabLayout);
    mMainLayout->addWidget(mMiniMap->getLabelptr());
    mMainLayout->addWidget(mQuitButton);
    setLayout(mMainLayout);

    /******************************TABCONNECTIONS********************************/
    connect(mInOutTab, SIGNAL(makeSimulatorConnection()),
            mSimulatorTab, SLOT(createSimulatorConnections()));
    connect(mGameTab,SIGNAL(startGameButtonPressed(int,int)),
            this,SLOT(startGame(int,int)));
    connect(mGameTab,SIGNAL(endGameButtonPressed()),
            this,SLOT(finishGame()));
}

//for test purpose
void MainBox::mousePressEvent(QMouseEvent *event){
    if(mGame){
        if (event->button() == Qt::LeftButton) {
            QPoint pos = event->pos();
            int x = pos.x()-mMiniMap->getLabelptr()->x();
            int y = pos.y()-mMiniMap->getLabelptr()->y();
            if(mMiniMap->valid(x,y)){
                mMiniMap->drawBall(Pose(x,y,0));
                Pose setNav((x*10)-3000,(y*-10)+2000,0);
                mGame->updatePlayerGoal(setNav);
            }
        }
    }
}

//********************SLOTS**************************

void MainBox::startGame(int iTeam,int iPlayer){
    mInOutTab->setEnabled(true);
    mControlTab->setEnabled(true);
    mAITab->setEnabled(true);
    mSimulatorTab->setEnabled(true);

    PlayEngine *lPlayEngine = new PlayEngine();
    Navigator *lNavigator = new Navigator;
    mSimulatorCore = new SimulatorCore(iPlayer);
    mGame = new SoccerGame(lPlayEngine, lNavigator, iTeam, iPlayer);
    GameFactory lFactory;
    mGame->createGame(lFactory);

    mSimulatorTab->setSimulator(mSimulatorCore);
    mInOutTab->setGame(mGame);

    //connect(mGame->getInputStream(), SIGNAL(visionPacketReady(SSL_WrapperPacket)), this,
    //        SLOT(updateGameData(SSL_WrapperPacket)));

    mRefreshTimer->start(100);
}

void MainBox::updateGameData(SSL_WrapperPacket iPacket){
    mGame->unwrapVisionPacket(iPacket);
    this->updateGame();
}

void MainBox::updateGame(){
    mGame->updateNavigator();
}

void MainBox::refreshScreen(){
    if(mGame){
        std::map<PlayerId, Pose> lBluePosition = mGame->getTeamPositions(TeamId(0));
        std::map<PlayerId, Pose> lYellowPosition = mGame->getTeamPositions(TeamId(1));

        for (std::map<PlayerId, Pose>::const_iterator it = lBluePosition.begin();
             it != lBluePosition.end(); it++) {
            mMiniMap->drawRobot(it->second,COLOR_BLUE);
        }
        for (std::map<PlayerId, Pose>::const_iterator it = lYellowPosition.begin();
             it != lYellowPosition.end(); it++) {
            mMiniMap->drawRobot(it->second,COLOR_YELLOW);
        }

        mMiniMap->drawBall(mGame->getBallPosition());

        mMiniMap->paint();
    }
}

void MainBox::finishGame(){
    mInOutTab->setEnabled(false);
    mControlTab->setEnabled(false);
    mAITab->setEnabled(false);
    mSimulatorTab->setEnabled(false);

    mRefreshTimer->stop();

    delete mSimulatorCore;
    delete mGame;
    mSimulatorCore = NULL;
    mGame = NULL;
    mSimulatorTab->setSimulator(mSimulatorCore);
    mInOutTab->setGame(mGame);
}
