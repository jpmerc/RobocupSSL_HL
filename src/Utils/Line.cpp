#include "Utils/Line.h"

#include <math.h>

Line::Line(const Line &other) :
    start(other.start),
    end(other.end){
}

Line::~Line(){
}

Line::Line(Vector2d iStart, Vector2d iEnd) :
    start(iStart),
    end(iEnd){
}


double Line::length(void) const{
    return start.distanceFromCoordinate(end);
}

//Angle between hypothenuse and x
double Line::angleHypothenuseX(void) const{
    //double hypothenuse = this->length();
    double lnormX = (end.x - start.x);//hypothenuse;
    double lnormY = (end.y - start.y);//hypothenuse;
    return atan(lnormY/lnormX);
}

Vector2d Line::getCoordOnLine(double distanceFromStart) const{
    double lAngle = this->angleHypothenuseX();
    double newY = sin(lAngle)*distanceFromStart;
    double newX = cos(lAngle)*distanceFromStart;
    INFO << "lAngle :" << lAngle;
    INFO << "X :" << start.x + newX;
    INFO << "Y :" << start.y + newY;
    return Vector2d(start.x + newX,start.y + newY);
}
