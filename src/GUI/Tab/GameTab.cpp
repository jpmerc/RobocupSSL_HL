#include "GUI/Tab/GameTab.h"

GameTab::GameTab():GenericTab(){

    //******************Camera LABEL/EDIT*************************

    mPlayerLabel = new QLabel(tr("Number of Player: "));
    mTeamLabel = new QLabel(tr("Number of Team: "));

    //*********************BUTTON*********************************
    mStartButton = new QPushButton("Start Game", this);
    connect(mStartButton, SIGNAL(clicked()), this, SLOT(startGame()));
    mEndButton = new QPushButton("End Game", this);
    connect(mEndButton, SIGNAL(clicked()), this, SLOT(endGame()));

    mEndButton->setEnabled(false);

    //***************************EDIT********************************
    mPlayerEdit = new QLineEdit("6", this);
    mTeamEdit = new QLineEdit("2", this);

    //***********************LAYOUT********************************

    mPlayerLayout = new QHBoxLayout;
    mTeamLayout = new QHBoxLayout;

    mPlayerLayout->addWidget(mPlayerLabel);
    mPlayerLayout->addStretch(1);
    mPlayerLayout->addWidget(mPlayerEdit);
    mPlayerLayout->addStretch(1);

    mTeamLayout->addWidget(mTeamLabel);
    mTeamLayout->addStretch(1);
    mTeamLayout->addWidget(mTeamEdit);
    mTeamLayout->addStretch(1);


    //***********************GENERAL LAYOUT********************************

    mTabLayout = new QVBoxLayout;
    mTabLayout->addLayout(mPlayerLayout);
    mTabLayout->addLayout(mTeamLayout);
    mTabLayout->addStretch(0);
    mTabLayout->addWidget(mStartButton);
    mTabLayout->addWidget(mEndButton);

    mGenericLayout->addLayout(mTabLayout);

}

GameTab::~GameTab(){
    delete mPlayerLabel;
    delete mTeamLabel;
    delete mStartButton;
    delete mEndButton;
    delete mPlayerEdit;
    delete mTeamEdit;
    delete mPlayerLayout;
    delete mTeamLayout;
    delete mTabLayout;

}

void GameTab::startGame(){
    mStartButton->setEnabled(false);
    mEndButton->setEnabled(true);
    mPlayerEdit->setEnabled(false);
    mTeamEdit->setEnabled(false);


    emit startGameButtonPressed(mTeamEdit->text().toInt(),
                                 mPlayerEdit->text().toInt());
}

void GameTab::endGame(){
    mStartButton->setEnabled(true);
    mEndButton->setEnabled(false);
    mPlayerEdit->setEnabled(true);
    mTeamEdit->setEnabled(true);

    emit endGameButtonPressed();
}
