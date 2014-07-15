/***********************************************************************
 * CONFIG BOX
 ***********************************************************************/


#include "GUI/ConfigBox.h"



ConfigBox::ConfigBox(int numOfEditBox,QWidget *parent) :
    QDialog(parent)
{
    mEditBoxSize = abs(numOfEditBox); //abs pour eviter les erreur avec < 0
    setUpGUI();
    setWindowTitle( tr("Configuration") );
    setModal( true );
}

ConfigBox::~ConfigBox(){
    delete mMainText;
    delete mButtons;
    for(int i = 0; i < mEditBoxSize; ++i){
        delete mLabelsVector[i];
        delete mEditsVector[i];
    }

}

void ConfigBox::setUpGUI(){

    for(int i = 0; i < mEditBoxSize; ++i){
        mLabelsVector.push_back(new QLabel(this));
        mLabelsVector[i]->setText( tr( "unset" ) );
        mEditsVector.push_back(new QLineEdit(this));
    }




    // initialize the labels
    mMainText = new QLabel( this );
    mMainText->setText( tr( "Camera Model noise" ) );


    // initialize buttons
    mButtons = new QDialogButtonBox( this );
    mButtons->addButton( QDialogButtonBox::Ok );
    mButtons->addButton( QDialogButtonBox::Cancel );
    mButtons->button( QDialogButtonBox::Ok )->setText( tr("Accept") );
    mButtons->button( QDialogButtonBox::Cancel )->setText( tr("Abort") );

    // connects slots
    connect( mButtons->button( QDialogButtonBox::Cancel ),
             SIGNAL(clicked()),
             this,
             SLOT(close())
             );

    connect( mButtons->button( QDialogButtonBox::Ok ),
             SIGNAL(clicked()),
             this,
             SLOT(acceptConfig()) );

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget( mMainText);
    std::vector<QHBoxLayout*> layouts;

    for(int i = 0; i < mEditBoxSize; ++i){
        layouts.push_back(new QHBoxLayout);
        layouts[i]->addWidget( mLabelsVector[i]);
        layouts[i]->addStretch(1);
        layouts[i]->addWidget( mEditsVector[i]);

        mainLayout->addLayout(layouts[i]);
    }

    mainLayout->addWidget( mButtons);
    setLayout(mainLayout);

}


void ConfigBox::acceptConfig(){
    std::vector<double> data;
    for(int i = 0; i < mEditBoxSize; ++i){
        data.push_back(mEditsVector[i]->text().toDouble());
    }

    emit returnValues( data);

    // close this dialog
    close();
}
