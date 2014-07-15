/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose:  General form of a tab
 *
 ****************************************************************************/

#ifndef GENERICTAB_H
#define GENERICTAB_H

#include <QDialog>
#include <QtGui>
#include <QImage>
#include <QWidget>
#include "GUI/MiniMap.h"
#include <iostream>
#include <sstream>

//class QVBoxLayout;
//class QPushButton;



class GenericTab : public QWidget {
    Q_OBJECT
public:
    GenericTab();
    virtual ~GenericTab();

protected:
    QVBoxLayout *mGenericLayout;        //class's childrens layout for there widgets
private:
    QPushButton *mGenericSaveButton;
    QPushButton *mGenericLoadButton;
    QHBoxLayout *mGenericButtonLayout;
    QVBoxLayout *mGenericMainLayout;
};

#endif // GENERICTAB_H
