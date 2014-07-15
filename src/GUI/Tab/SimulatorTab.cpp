#include "GUI/Tab/SimulatorTab.h"

SimulatorTab::SimulatorTab():GenericTab(),
    mSimulatorCore(NULL){

    //******************Camera LABEL/EDIT*************************

    mCameraInLabel = new QLabel(tr("Input"));
    mCameraInPortLabel = new QLabel(tr("Port:"));
    mCameraInAdressLabel = new QLabel(tr("Adress:"));
    mCameraOutLabel = new QLabel(tr("Output"));
    mCameraOutPortLabel = new QLabel(tr("Port:"));
    mCameraOutAdressLabel = new QLabel(tr("Adress:"));

    mCameraInPortEdit = new QLineEdit("10020", this);
    mCameraInAdressEdit = new QLineEdit("224.5.23.2", this);
    mCameraOutPortEdit = new QLineEdit("20009", this);
    mCameraOutAdressEdit = new QLineEdit("127.0.0.1", this);

    //******************Command LABEL/EDIT*************************

    mCommandInLabel = new QLabel(tr("Input"));
    mCommandInPortLabel = new QLabel(tr("Port:"));
    mCommandInAdressLabel = new QLabel(tr("Adress:"));
    mCommandOutLabel = new QLabel(tr("Output"));
    mCommandOutPortLabel = new QLabel(tr("Port:"));
    mCommandOutAdressLabel = new QLabel(tr("Adress:"));
    mCommandInPortEdit = new QLineEdit("20006", this);
    mCommandInAdressEdit = new QLineEdit("127.0.0.1", this);
    mCommandOutPortEdit = new QLineEdit("20011", this);
    mCommandOutAdressEdit = new QLineEdit("127.0.0.1", this);

    //*********************BUTTON*********************************
    mCameraConfigButton = new QPushButton("Camera Option", this);
    connect(mCameraConfigButton, SIGNAL(clicked()), this, SLOT(throwCameraConfigBox()));

    mRobotConfigButton = new QPushButton("Robot Option", this);
    connect(mRobotConfigButton, SIGNAL(clicked()), this, SLOT(throwRobotConfigBox()));


    //*********************CONFIGBOX******************************
    mCameraConfig = new ConfigBox(8, this );
    mCameraConfig->setTexts("X Mean:",           0);
    mCameraConfig->setTexts("X Variance:",       1);
    mCameraConfig->setTexts("Y Mean:",           2);
    mCameraConfig->setTexts("Y Variance:",       3);
    mCameraConfig->setTexts("Theta Mean:",       4);
    mCameraConfig->setTexts("Theta Variance:",   5);
    mCameraConfig->setTexts("FPS(ms):",          6);
    mCameraConfig->setTexts("Vanishing Prob:",   7);
    connect(mCameraConfig,SIGNAL(returnValues(std::vector<double> )),
            this,SLOT(camConfigAccepted(std::vector<double>)));

    mRobotConfig = new ConfigBox(6, this );
    mRobotConfig->setTexts("Speed X Mean:",           0);
    mRobotConfig->setTexts("Speed X Variance:",       1);
    mRobotConfig->setTexts("Speed Y Mean:",           2);
    mRobotConfig->setTexts("Speed Y Variance:",       3);
    mRobotConfig->setTexts("Speed Theta Mean:",       4);
    mRobotConfig->setTexts("Speed Theta Variance:",   5);
    connect(mRobotConfig,SIGNAL(returnValues(std::vector<double>  )),
            this,SLOT(robotConfigAccepted(std::vector<double>)));

    //**********************GROUP**********************************

    mCameraGroup = new QGroupBox(tr("Camera"));
    mCommandGroup = new QGroupBox(tr("Command"));

    //***********************CAMERA LAYOUT********************************

    mCameraInLayout = new QHBoxLayout;
    mCameraOutLayout = new QHBoxLayout;
    mCameraButtonLayout = new QHBoxLayout;

    mCameraInLayout->addWidget(mCameraInLabel);
    mCameraInLayout->addStretch(0);
    mCameraInLayout->addWidget(mCameraInPortLabel);
    mCameraInLayout->addWidget(mCameraInPortEdit);
    mCameraInLayout->addWidget(mCameraInAdressLabel);
    mCameraInLayout->addWidget(mCameraInAdressEdit);

    mCameraOutLayout->addWidget(mCameraOutLabel);
    mCameraOutLayout->addStretch(0);
    mCameraOutLayout->addWidget(mCameraOutPortLabel);
    mCameraOutLayout->addWidget(mCameraOutPortEdit);
    mCameraOutLayout->addWidget(mCameraOutAdressLabel);
    mCameraOutLayout->addWidget(mCameraOutAdressEdit);

    mCameraLayout = new QVBoxLayout;
    mCameraLayout->addLayout(mCameraInLayout);
    mCameraLayout->addLayout(mCameraOutLayout);
    mCameraLayout->addLayout(mCameraButtonLayout);

    mCameraGroup->setLayout(mCameraLayout);

    //***********************COMMAND LAYOUT********************************

    mCommandInLayout = new QHBoxLayout;
    mCommandOutLayout = new QHBoxLayout;
    mCommandButtonLayout = new QHBoxLayout;

    mCommandInLayout->addWidget(mCommandInLabel);
    mCommandInLayout->addStretch(0);
    mCommandInLayout->addWidget(mCommandInPortLabel);
    mCommandInLayout->addWidget(mCommandInPortEdit);
    mCommandInLayout->addWidget(mCommandInAdressLabel);
    mCommandInLayout->addWidget(mCommandInAdressEdit);

    mCommandOutLayout->addWidget(mCommandOutLabel);
    mCommandOutLayout->addStretch(0);
    mCommandOutLayout->addWidget(mCommandOutPortLabel);
    mCommandOutLayout->addWidget(mCommandOutPortEdit);
    mCommandOutLayout->addWidget(mCommandOutAdressLabel);
    mCommandOutLayout->addWidget(mCommandOutAdressEdit);

    mCommandLayout = new QVBoxLayout;
    mCommandLayout->addLayout(mCommandInLayout);
    mCommandLayout->addLayout(mCommandOutLayout);
    mCommandLayout->addLayout(mCommandButtonLayout);

    mCommandGroup->setLayout(mCommandLayout);


    //***********************LAYOUT IN/OUT********************************

    mTabLayout = new QVBoxLayout;
    mTabLayout->addWidget(mCameraGroup);
    mTabLayout->addWidget(mCommandGroup);
    mTabLayout->addWidget(mCameraConfigButton);
    mTabLayout->addWidget(mRobotConfigButton);

    mGenericLayout->addLayout(mTabLayout);

}

SimulatorTab::~SimulatorTab(){


    delete mCameraInLabel;
    delete mCameraInAdressLabel;
    delete mCameraInPortLabel;
    delete mCameraOutLabel;
    delete mCameraOutAdressLabel;
    delete mCameraOutPortLabel;

    delete mCommandInLabel;
    delete mCommandInAdressLabel;
    delete mCommandInPortLabel;
    delete mCommandOutLabel;
    delete mCommandOutAdressLabel;
    delete mCommandOutPortLabel;

    delete mCameraInPortEdit;
    delete mCameraInAdressEdit;
    delete mCameraOutPortEdit;
    delete mCameraOutAdressEdit;

    delete mCommandInPortEdit;
    delete mCommandInAdressEdit;
    delete mCommandOutPortEdit;
    delete mCommandOutAdressEdit;

    delete mCameraInLayout;
    delete mCameraOutLayout;
    delete mCameraButtonLayout;
    delete mCommandInLayout;
    delete mCommandOutLayout;
    delete mCommandButtonLayout;

    delete mCameraLayout;
    delete mCommandLayout;

    delete mTabLayout;

    delete mCameraGroup;
    delete mCommandGroup;

    delete mCameraConfigButton;
    delete mRobotConfigButton;

    delete mCameraConfig;
    delete mRobotConfig;

}

void SimulatorTab::setSimulator(SimulatorCore * iSim){
    mSimulatorCore = iSim;
}

void SimulatorTab::createSimulatorConnections(){
    QString lInAdressCam = mCameraInAdressEdit->text();
    int lInPortCam = mCameraInPortEdit->text().toInt();
    QString lOutAdressCam = mCameraOutAdressEdit->text();
    int lOutPortCam = mCameraOutPortEdit->text().toInt();
    //mSimulatorCore->setCameraUDPConfiguration(lInAdressCam,lInPortCam,
                                              //lOutAdressCam,lOutPortCam);

    QString lInAdressCommand = mCommandInAdressEdit->text();
    int lInPortCommand = mCommandInPortEdit->text().toInt();
    QString lOutAdressCommand = mCommandOutAdressEdit->text();
    int lOutPortCommand = mCommandOutPortEdit->text().toInt();
    //mSimulatorCore->setCommandUDPConfiguration(lInAdressCommand,lInPortCommand,
    //                                          lOutAdressCommand,lOutPortCommand);

}

void SimulatorTab::camConfigAccepted(std::vector<double> iData){

    CameraModel *lCamera = mSimulatorCore->getCamera();
    lCamera->setGaussX(GaussianModel(iData[0],iData[1]));
    lCamera->setGaussY(GaussianModel(iData[2],iData[3]));
    lCamera->setGaussTheta(GaussianModel(iData[4],iData[5]));
    lCamera->setFps(iData[6]);
    lCamera->setVanishingProbability(iData[7]);
}

void SimulatorTab::robotConfigAccepted(std::vector<double> iData){

    mSimulatorCore->setRobotsConfig(GaussianModel(iData[0],iData[1]),
            GaussianModel(iData[2],iData[3]),
            GaussianModel(iData[4],iData[5]));
}

void SimulatorTab::throwCameraConfigBox(){
    CameraModel *lCamera = mSimulatorCore->getCamera();
    GaussianModel lX = lCamera->getGaussX();
    GaussianModel lY = lCamera->getGaussY();
    GaussianModel lTheta = lCamera->getGaussTheta();

    mCameraConfig->setData(lX.Mean,                             0);
    mCameraConfig->setData(lX.Variance,                         1);
    mCameraConfig->setData(lY.Mean,                             2);
    mCameraConfig->setData(lY.Variance,                         3);
    mCameraConfig->setData(lTheta.Mean,                         4);
    mCameraConfig->setData(lTheta.Variance,                     5);
    mCameraConfig->setData(lCamera->getFps(),                   6);
    mCameraConfig->setData(lCamera->getVanishingProbability(),  7);
    mCameraConfig->exec();
}

void SimulatorTab::throwRobotConfigBox(){
    GaussianModel lX = mSimulatorCore->getRobotGaussX();
    GaussianModel lY = mSimulatorCore->getRobotGaussY();
    GaussianModel lTheta = mSimulatorCore->getRobotGaussTheta();

    mRobotConfig->setData(lX.Mean,                             0);
    mRobotConfig->setData(lX.Variance,                         1);
    mRobotConfig->setData(lY.Mean,                             2);
    mRobotConfig->setData(lY.Variance,                         3);
    mRobotConfig->setData(lTheta.Mean,                         4);
    mRobotConfig->setData(lTheta.Variance,                     5);
    mRobotConfig->exec();
}
