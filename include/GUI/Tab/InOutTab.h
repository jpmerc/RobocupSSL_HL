/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Tab that handle input stream of the "AI" and its output stream
 *
 ****************************************************************************/

#ifndef INOUTTAB_H
#define INOUTTAB_H

#include <QDialog>
#include <QtGui>
#include <QImage>
#include <QWidget>
#include "GUI/Tab/GenericTab.h"
#include "InOut/InputStream.h"
#include "InOut/UDPOutputStream.h"
#include "InOut/SerialOutputStream.h"
#include <QCoreApplication>
#include "boost/filesystem.hpp"
#include "SoccerGame/SoccerGame.h"


class InOutTab : public GenericTab {
    Q_OBJECT
public:
    InOutTab();
    virtual ~InOutTab();

    void setGame(SoccerGame *iGame);
    void createVisionConnection();
    void createRefConnection();

private slots:
    void connectToVision();
    void connectToRef();
    void createUDPOutput();
    void createSerialOutput();
    void sendPacket();
    void refreshSerialPortComboBox();

signals:
    void makeSimulatorConnection();
private:

    QLabel *mVisionLabel;
    QLabel *mVisionAdressLabel;
    QLabel *mVisionPortLabel;
    QLabel *mRefLabel;
    QLabel *mRefAdressLabel;
    QLabel *mRefPortLabel;
    QLabel *mSimulatorLabel;
    QLabel *mSimulatorPortLabel;
    QLabel *mSimulatorAdressLabel;
    QLabel *mSerialLabel;
    QLabel *mSerialPortLabel;
    QLabel *mSerialBaudLabel;
    QLabel *mVisionConnectedLabel;
    QLabel *mSerialConnectedLabel;
    QLabel *mRefConnectedLabel;
    QLabel *mSimulatorConnectedLabel;

    QPushButton *mVisionButton;
    QPushButton *mRefButton;
    QPushButton *mSimulatorButton;
    QPushButton *mSerialButton;
    QPushButton *mSerialRefreshButton;

    QLineEdit *mVisionPortEdit;
    QLineEdit *mVisionAdressEdit;
    QLineEdit *mRefPortEdit;
    QLineEdit *mRefAdressEdit;
    QLineEdit *mSimulatorPortEdit;
    QLineEdit *mSimulatorAdressEdit;

    QComboBox *mPortComboBox;
    QComboBox *mBaudComboBox;

    QHBoxLayout *mVisionLayout;
    QHBoxLayout *mRefLayout;
    QHBoxLayout *mSimulatorLayout;
    QHBoxLayout *mSerialLayout;
    QVBoxLayout *mInputLayout;
    QVBoxLayout *mOuputLayout;
    QVBoxLayout *mTabLayout;

    SoccerGame *mGame;


    QGroupBox *mInputGroup;
    QGroupBox *mOutputGroup;

};


#endif // INOUTTAB_H
