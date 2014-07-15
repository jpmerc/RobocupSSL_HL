#include "GUI/Tab/InOutTab.h"

InOutTab::InOutTab():
    GenericTab(){

    //******************INPUT LABEL/EDIT*************************

    mVisionLabel = new QLabel(tr("Vision"));
    mVisionPortLabel = new QLabel(tr("Port:"));
    mVisionAdressLabel = new QLabel(tr("Adress:"));
    mRefLabel = new QLabel(tr("Ref"));
    mRefPortLabel = new QLabel(tr("Port:"));
    mRefAdressLabel = new QLabel(tr("Adress:"));
    mSerialLabel = new QLabel(tr("Serial:"));
    mSerialPortLabel = new QLabel(tr("Port:"));
    mSerialBaudLabel = new QLabel(tr("BaudRate:"));
    mVisionConnectedLabel = new QLabel(tr("Not Connected"));
    mVisionConnectedLabel->setStyleSheet("QLabel {color : red; }");
    mRefConnectedLabel = new QLabel(tr("Not Connected"));
    mRefConnectedLabel->setStyleSheet("QLabel {color : red; }");

    mVisionPortEdit = new QLineEdit("20009", this);
    mVisionAdressEdit = new QLineEdit("127.0.0.1", this);
    mRefPortEdit = new QLineEdit("10001", this);
    mRefAdressEdit = new QLineEdit("224.5.23.1", this);



    //******************OUTPUT LABEL/EDIT*************************

    mSimulatorLabel = new QLabel(tr("Simulator"));
    mSimulatorPortLabel = new QLabel(tr("Port:"));
    mSimulatorAdressLabel = new QLabel(tr("Adress:"));

    mSimulatorPortEdit = new QLineEdit("20006", this);
    mSimulatorAdressEdit = new QLineEdit("127.0.0.1", this);
    mSimulatorConnectedLabel = new QLabel(tr("Not Connected"));
    mSimulatorConnectedLabel->setStyleSheet("QLabel {color : red; }");

    //*********************BUTTON*********************************
    mVisionButton = new QPushButton("Connect", this);
    connect(mVisionButton, SIGNAL(clicked()), this, SLOT(connectToVision()));
    mRefButton = new QPushButton("Connect", this);
    connect(mRefButton, SIGNAL(clicked()), this, SLOT(connectToRef()));

    mSimulatorButton = new QPushButton("Connect", this);
    connect(mSimulatorButton, SIGNAL(clicked()), this, SLOT(createUDPOutput()));

    mSerialButton = new QPushButton("Connect", this);
    connect(mSerialButton, SIGNAL(clicked()), this, SLOT(createSerialOutput()));
    mSerialRefreshButton = new QPushButton(this);
    mSerialRefreshButton->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/../hl-game/images/gtk_refresh.png"));
    connect(mSerialRefreshButton, SIGNAL(clicked()), this, SLOT(refreshSerialPortComboBox()));
    mSerialConnectedLabel = new QLabel(tr("Not Connected"));
    mSerialConnectedLabel->setStyleSheet("QLabel {color : red; }");


    //***********************COMBOBOX******************************

    mPortComboBox = new QComboBox(this);
    refreshSerialPortComboBox();

    mBaudComboBox = new QComboBox(this);
    mBaudComboBox->addItem("4800");
    mBaudComboBox->addItem("9600");
    mBaudComboBox->addItem("19200");
    mBaudComboBox->addItem("38400");
    mBaudComboBox->addItem("57600");
    mBaudComboBox->addItem("115200");
    mBaudComboBox->addItem("230400");
    mBaudComboBox->setCurrentIndex(5);
    //connect( mBaudComboBox, SIGNAL( currentIndexChanged(int) ), this, SLOT( UpdateBaudRate(int) ) );


    //**********************GROUP**********************************

    mInputGroup = new QGroupBox(tr("Input"));
    mOutputGroup = new QGroupBox(tr("Output"));

    //***********************LAYOUT INPUT********************************

    mVisionLayout = new QHBoxLayout;
    mRefLayout = new QHBoxLayout;

    mVisionLayout->addWidget(mVisionLabel);
    mVisionLayout->addStretch(1);
    mVisionLayout->addWidget(mVisionPortLabel);
    mVisionLayout->addWidget(mVisionPortEdit);
    mVisionLayout->addWidget(mVisionAdressLabel);
    mVisionLayout->addWidget(mVisionAdressEdit);
    mVisionLayout->addWidget(mVisionButton);

    mRefLayout->addWidget(mRefLabel);
    mRefLayout->addStretch(1);
    mRefLayout->addWidget(mRefPortLabel);
    mRefLayout->addWidget(mRefPortEdit);
    mRefLayout->addWidget(mRefAdressLabel);
    mRefLayout->addWidget(mRefAdressEdit);
    mRefLayout->addWidget(mRefButton);

    mInputLayout = new QVBoxLayout;
    mInputLayout->addLayout(mVisionLayout);
    mInputLayout->addWidget(mVisionConnectedLabel);
    mInputLayout->addLayout(mRefLayout);
    mInputLayout->addWidget(mRefConnectedLabel);

    mInputGroup->setLayout(mInputLayout);

    //***********************LAYOUT OUPUT********************************
    mSimulatorLayout = new QHBoxLayout;
    mSerialLayout = new QHBoxLayout;

    mSimulatorLayout->addWidget(mSimulatorLabel);
    mSimulatorLayout->addStretch(1);
    mSimulatorLayout->addWidget(mSimulatorPortLabel);
    mSimulatorLayout->addWidget(mSimulatorPortEdit);
    mSimulatorLayout->addWidget(mSimulatorAdressLabel);
    mSimulatorLayout->addWidget(mSimulatorAdressEdit);
    mSimulatorLayout->addWidget(mSimulatorButton);

    mSerialLayout->addWidget(mSerialLabel);
    mSerialLayout->addStretch(1);
    mSerialLayout->addWidget(mSerialPortLabel);
    mSerialLayout->addWidget(mPortComboBox);
    mSerialLayout->addWidget(mSerialRefreshButton);
    mSerialLayout->addStretch(1);
    mSerialLayout->addWidget(mSerialBaudLabel);
    mSerialLayout->addWidget(mBaudComboBox);
    mSerialLayout->addWidget(mSerialButton);

    mOuputLayout = new QVBoxLayout;
    mOuputLayout->addLayout(mSimulatorLayout);
    mOuputLayout->addWidget(mSimulatorConnectedLabel);
    mOuputLayout->addLayout(mSerialLayout);
    mOuputLayout->addWidget(mSerialConnectedLabel);

    mOutputGroup->setLayout(mOuputLayout);


    //***********************LAYOUT IN/OUT********************************

    mTabLayout = new QVBoxLayout;
    mTabLayout->addWidget(mInputGroup);
    mTabLayout->addWidget(mOutputGroup);

    mGenericLayout->addLayout(mTabLayout);

    //*********************CONNECTION*************************************
    //CreateVisionConnection();
    //CreateRefConnection();

}

InOutTab::~InOutTab(){
    delete mVisionLabel;
    delete mVisionAdressLabel;
    delete mVisionPortLabel;
    delete mRefLabel;
    delete mRefAdressLabel;
    delete mRefPortLabel;
    delete mSimulatorLabel;
    delete mSimulatorPortLabel;
    delete mSimulatorAdressLabel;
    delete mSerialLabel;
    delete mSerialPortLabel;
    delete mSerialBaudLabel;
    delete mVisionConnectedLabel;
    delete mSerialConnectedLabel;
    delete mRefConnectedLabel;
    delete mSimulatorConnectedLabel;

    delete mVisionButton;
    delete mRefButton;
    delete mSimulatorButton;
    delete mSerialButton;
    delete mSerialRefreshButton;

    delete mVisionPortEdit;
    delete mVisionAdressEdit;
    delete mRefPortEdit;
    delete mRefAdressEdit;
    delete mSimulatorPortEdit;
    delete mSimulatorAdressEdit;

    delete mPortComboBox;
    delete mBaudComboBox;

    delete mVisionLayout;
    delete mRefLayout;
    delete mSimulatorLayout;
    delete mSerialLayout;
    delete mInputLayout;
    delete mOuputLayout;
    delete mTabLayout;

    delete mInputGroup;
    delete mOutputGroup;

}

void InOutTab::setGame(SoccerGame *iGame){
    mGame = iGame;
}

void InOutTab::createVisionConnection(){
    QString lAdress = mVisionAdressEdit->text();
    int lPort = mVisionPortEdit->text().toInt();
    //mGame->getInputStream()->createVisionUDPSocket(lAdress,lPort);
}

void InOutTab::createRefConnection(){
    QString lAdress = mRefAdressEdit->text();
    int lPort = mRefPortEdit->text().toInt();
    //mGame->getInputStream()->createRefboxUDPSocket(lAdress,lPort);
}

//************************SLOTS************************************

void InOutTab::connectToVision(){
    //mGame->getInputStream()->closeVision();
    createVisionConnection();
    mVisionConnectedLabel->setText("Connected");
    mVisionConnectedLabel->setStyleSheet("QLabel {color : green; }");
}

void InOutTab::connectToRef(){
    //mGame->getInputStream()->closeRef();
    //createVisionConnection();
    mRefConnectedLabel->setText("Connected");
    mRefConnectedLabel->setStyleSheet("QLabel {color : green; }");
}

void InOutTab::createUDPOutput(){
    //mGame->setOuputStream(new UDPOutputStream(mSimulatorAdressEdit->text().toStdString(),mSimulatorPortEdit->text().toInt()));
    //mGame->getOutputStream()->SetConnection(lAdress.toStdString());
    //mGame->getOutputStream()->SetData(lPort);

    //emit this->makeSimulatorConnection();  //Make connection with simulatorTab's data

    mSimulatorConnectedLabel->setText("Connected");
    mSimulatorConnectedLabel->setStyleSheet("QLabel {color : green; }");
    mSerialConnectedLabel->setText("Not Connected");
    mSerialConnectedLabel->setStyleSheet("QLabel {color : red; }");

}

void InOutTab::createSerialOutput(){
    /*try {
        mGame->setOuputStream(new SerialOutputStream(mPortComboBox->currentText().toStdString(),
                                                     mBaudComboBox->currentText().toInt()));
    }
    catch(boost::system::system_error& e){
        QMessageBox messageBox;
        messageBox.critical(0,"Error",e.what());
        return;
    }*/
    mSerialConnectedLabel->setText("Connected");
    mSerialConnectedLabel->setStyleSheet("QLabel {color : green; }");
    mSimulatorConnectedLabel->setText("Not Connected");
    mSimulatorConnectedLabel->setStyleSheet("QLabel {color : red; }");

}

void InOutTab::sendPacket(){

    //mGame->getOutputStream()->SendCommand(1,0,5,0);
}

void InOutTab::refreshSerialPortComboBox(){
    mPortComboBox->clear();
    namespace fs = boost::filesystem;
    fs::path someDir("/dev");
    fs::directory_iterator end_iter;

    bool flag = false;
    if(fs::exists(someDir) && fs::is_directory(someDir)){
        for( fs::directory_iterator dir_iter(someDir) ; dir_iter != end_iter ; ++dir_iter){
           std::string filename = dir_iter->path().filename().string();
           if(filename.find("ttyUSB") == 0){//USB
                flag = true;
                mPortComboBox->addItem("/dev/" + QString::fromStdString(filename));
           }
        }
    }
    if(!flag)
        mPortComboBox->addItem("No Port");
}

