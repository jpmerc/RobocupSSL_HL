/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Map object to draw current state of the field
 *
 ****************************************************************************/

#ifndef MINIMAP_H
#define MINIMAP_H
#include <QPainter>
#include <QImage>
#include <QPen>
#include <QLabel>
#include <QWidget>
#include "Utils/Pose.h"

static const QVector<QRgb> COLORS = QVector<QRgb>()  //minimap color vector
<< qRgb( 0, 0, 0)
<< qRgb(255, 69, 0)
<< qRgb( 25, 104, 0)
<< qRgb(255, 255, 0)
<< qRgb( 0, 0, 255)
<< qRgb(255, 0, 255)
<< qRgb( 0, 255, 255)
<< qRgb(255, 255, 255);

#define COLOR_BLACK   0  //color defines for minimap
#define COLOR_RED     1
#define COLOR_GREEN   2
#define COLOR_YELLOW  3
#define COLOR_BLUE    4
#define COLOR_PURPLE  5
#define COLOR_CYAN    6
#define COLOR_WHITE   7





class MiniMap: public QImage{
public:
    MiniMap(int x, int y,QImage::Format format);
    virtual ~MiniMap();

    void drawRobot(Pose iPosition,int color);
    void drawBall(Pose iPosition);
    void paint();
    void drawField();


    void setRefreshRate(int rr);
    int getRefreshRate();
    QLabel* getLabelptr();

private:

    bool _pixelIsOutOfScreen(int iX, int iY, int iOffset = 0);

    QLabel* mLabel;
    int mRefreshRate,mRefreshCount;



};

inline void MiniMap::setRefreshRate(int rr){
    mRefreshRate = rr;
}

inline int MiniMap::getRefreshRate(){
    return mRefreshRate;
}

inline QLabel* MiniMap::getLabelptr(){
    return mLabel;
}

#endif
