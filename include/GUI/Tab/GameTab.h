/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose:  Tab that handle game option and create game
 *
 ****************************************************************************/

#ifndef GAMETAB_H
#define GAMETAB_H

#include <QDialog>
#include <QtGui>
#include <QImage>
#include <QWidget>
#include "GUI/Tab/GenericTab.h"
#include "InOut/InputStream.h"
#include "InOut/UDPOutputStream.h"
#include "Simulator/SimulatorCore.h"



class GameTab : public GenericTab {
    Q_OBJECT
public:
    GameTab();
    virtual ~GameTab();

private slots:
    void startGame();
    void endGame();

signals:
    void startGameButtonPressed(int iTeam,int iPlayer);
    void endGameButtonPressed();

private:

    QLabel *mPlayerLabel;
    QLabel *mTeamLabel;

    QLineEdit *mPlayerEdit;
    QLineEdit *mTeamEdit;

    QPushButton *mStartButton;
    QPushButton *mEndButton;

    QHBoxLayout *mPlayerLayout;
    QHBoxLayout *mTeamLayout;

    QVBoxLayout *mTabLayout;

};

#endif // GAMETAB_H
