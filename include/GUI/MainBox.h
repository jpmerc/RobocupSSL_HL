/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Main box that handle all tabs and functions
 *
 ****************************************************************************/

#ifndef MAINBOX_H
#define MAINBOX_H

#include <QDialog>
#include <QHostAddress>
#include <QtGui>
#include <QtNetwork>
#include <QImage>
#include <QTabWidget>

#include <cstring>
#include <cmath>
#include <QTextStream>
#include <vector>

#include "proto/pb/messages_robocup_ssl_wrapper.pb.h"
#include "proto/pb/messages_robocup_ssl_detection.pb.h"
#include "proto/pb/messages_robocup_ssl_geometry.pb.h"
#include "proto/pb/grSim_Packet.pb.h"
#include "proto/pb/grSim_Commands.pb.h"
#include "proto/pb/grSim_Replacement.pb.h"
#include "GUI/MiniMap.h"
#include "GUI/ConfigBox.h"
#include "GUI/Tab/GenericTab.h"
#include "GUI/Tab/InOutTab.h"
#include "GUI/Tab/SimulatorTab.h"
#include "GUI/Tab/GameTab.h"
#include "InOut/InputStream.h"
#include "Simulator/SimulatorCore.h"
#include "SoccerGame/SoccerGame.h"


class QLabel;
class QPushButton;
class QUdpSocket;



class MainBox : public QDialog
{
    Q_OBJECT

public:
    MainBox(QWidget *parent = 0);
    virtual ~MainBox();
    void createGUI();

    void mousePressEvent(QMouseEvent *event);

private slots:
    void startGame(int,int);
    void updateGameData(SSL_WrapperPacket iPacket);
    void updateGame();
    void refreshScreen();
    void finishGame();

private:

    QPushButton *mQuitButton;
    QPushButton *mTestButton;

    QHBoxLayout *mTabLayout;
    QVBoxLayout *mMainLayout;

    QTabWidget *mMainTabWidget;

    QString *mRobocupLabel;
    QString *mInOutLabel;
    QString *mControlLabel;
    QString *mAILabel;
    QString *mSimulatorLabel;

    GameTab *mGameTab;
    InOutTab *mInOutTab;
    GenericTab *mControlTab;
    GenericTab *mAITab;
    SimulatorTab *mSimulatorTab;

    MiniMap *mMiniMap;
    QTimer *mRefreshTimer;

    SoccerGame *mGame;
    SimulatorCore *mSimulatorCore;

};




#endif
