/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose:  Tab that handle simulator options and configurations
 *
 ****************************************************************************/

#ifndef SIMULATORTAB_H
#define SIMULATORTAB_H

#include <QDialog>
#include <QtGui>
#include <QImage>
#include <QWidget>
#include "GUI/Tab/GenericTab.h"
#include "InOut/InputStream.h"
#include "InOut/UDPOutputStream.h"
#include "Simulator/SimulatorCore.h"
#include "GUI/ConfigBox.h"



class SimulatorTab : public GenericTab {
    Q_OBJECT
public:
    SimulatorTab();
    virtual ~SimulatorTab();

    void setSimulator(SimulatorCore * iSim);

private slots:
    void createSimulatorConnections();

    void camConfigAccepted(std::vector<double> iData);
    void robotConfigAccepted(std::vector<double> iData);
    void throwCameraConfigBox();
    void throwRobotConfigBox();

private:

    QLabel *mCameraInLabel;
    QLabel *mCameraInAdressLabel;
    QLabel *mCameraInPortLabel;
    QLabel *mCameraOutLabel;
    QLabel *mCameraOutAdressLabel;
    QLabel *mCameraOutPortLabel;

    QLabel *mCommandInLabel;
    QLabel *mCommandInAdressLabel;
    QLabel *mCommandInPortLabel;
    QLabel *mCommandOutLabel;
    QLabel *mCommandOutAdressLabel;
    QLabel *mCommandOutPortLabel;

    QCheckBox *mCameraCheck;

    QLineEdit *mCameraInPortEdit;
    QLineEdit *mCameraInAdressEdit;
    QLineEdit *mCameraOutPortEdit;
    QLineEdit *mCameraOutAdressEdit;

    QLineEdit *mCommandInPortEdit;
    QLineEdit *mCommandInAdressEdit;
    QLineEdit *mCommandOutPortEdit;
    QLineEdit *mCommandOutAdressEdit;

    QHBoxLayout *mCameraInLayout;
    QHBoxLayout *mCameraOutLayout;
    QHBoxLayout *mCameraButtonLayout;
    QHBoxLayout *mCommandInLayout;
    QHBoxLayout *mCommandOutLayout;
    QHBoxLayout *mCommandButtonLayout;

    QVBoxLayout *mCameraLayout;
    QVBoxLayout *mCommandLayout;

    QVBoxLayout *mTabLayout;

    QGroupBox *mCameraGroup;
    QGroupBox *mCommandGroup;

    QPushButton *mCameraConfigButton;
    QPushButton *mRobotConfigButton;

    ConfigBox *mCameraConfig;
    ConfigBox *mRobotConfig;


    SimulatorCore *mSimulatorCore;

};

#endif // SIMULATORTAB_H
