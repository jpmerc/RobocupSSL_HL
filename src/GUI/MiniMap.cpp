

#include "GUI/MiniMap.h"


MiniMap::MiniMap(int x, int y,QImage::Format format ):QImage(x,y,format),mRefreshRate(0),
    mRefreshCount(0){
    this->setColorTable(COLORS); //set color vector
    this->fill(COLOR_GREEN);     //draw background
    mLabel = new QLabel();
    mLabel->setPixmap(QPixmap::fromImage(*this));
}

MiniMap::~MiniMap(){
    delete mLabel;
}


void MiniMap::drawRobot(Pose iPosition,int iColor){
        double lX = iPosition.Position.x;
        double lY = iPosition.Position.y;
        lX = (lX+3000)/10;
        lY = (lY-2000)/-10;
        if(!_pixelIsOutOfScreen(lX,lY,2)){
            this->setPixel(lX, lY, iColor);
            this->setPixel(lX+1, lY, COLOR_BLACK);
            this->setPixel(lX+2, lY, COLOR_BLACK);
            this->setPixel(lX-1, lY, COLOR_BLACK);
            this->setPixel(lX-2, lY, COLOR_BLACK);
            this->setPixel(lX, lY+1, COLOR_BLACK);
            this->setPixel(lX, lY+2, COLOR_BLACK);
            this->setPixel(lX, lY-1, COLOR_BLACK);
            this->setPixel(lX, lY-2, COLOR_BLACK);

            this->setPixel(lX+1, lY-1, COLOR_BLACK);
            this->setPixel(lX+1, lY+1, COLOR_BLACK);
            this->setPixel(lX-1, lY-1, COLOR_BLACK);
            this->setPixel(lX-1, lY+1, COLOR_BLACK);
        }

}

void MiniMap::drawBall(Pose iPosition){
        double lX = iPosition.Position.x;
        double lY = iPosition.Position.y;
        lX = (lX+3000)/10;
        lY = (lY-2000)/-10;
        if(!_pixelIsOutOfScreen(lX,lY,1)){
            this->setPixel(lX, lY, COLOR_RED);
            this->setPixel(lX+1, lY, COLOR_RED);
            this->setPixel(lX-1, lY, COLOR_RED);
            this->setPixel(lX, lY+1, COLOR_RED);
            this->setPixel(lX, lY-1, COLOR_RED);
        }


}

void MiniMap::paint(){
    mLabel->setPixmap(QPixmap::fromImage(*this));
    mLabel->repaint();
    ++mRefreshCount;
    if(mRefreshCount > mRefreshRate){
        this->fill(COLOR_GREEN);
        mRefreshCount = 0;
    }
    drawField();
}

void MiniMap::drawField(){
}

bool MiniMap::_pixelIsOutOfScreen(int iX, int iY,int iOffset){
    if(iX - iOffset <= 0 || iX + iOffset >= this->width()){
        return true;
    }
    if(iY - iOffset <= 0 || iY + iOffset >= this->height()){
        return true;
    }

    return false;
}



