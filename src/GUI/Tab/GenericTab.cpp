#include "GUI/Tab/GenericTab.h"

GenericTab::GenericTab(){

    mGenericLoadButton = new QPushButton("Load", this);
    mGenericSaveButton = new QPushButton("Save", this);

    mGenericMainLayout = new QVBoxLayout;
    mGenericLayout = new QVBoxLayout;
    mGenericButtonLayout = new QHBoxLayout;
    mGenericButtonLayout->addStretch(1);
    mGenericButtonLayout->addWidget(mGenericLoadButton);
    mGenericButtonLayout->addWidget(mGenericSaveButton);

    mGenericMainLayout->addLayout(mGenericLayout);
    mGenericMainLayout->addLayout(mGenericButtonLayout);
    setLayout(mGenericMainLayout);


}

GenericTab::~GenericTab(){
    delete mGenericLoadButton;
    delete mGenericSaveButton;
    delete mGenericLayout;
    delete mGenericButtonLayout;
    delete mGenericMainLayout;
}

