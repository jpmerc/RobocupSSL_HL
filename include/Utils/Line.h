/****************************************************************************
 *Author :  Mathieu Garon <mathieu.garon.2@ulaval.ca>
 *
 *Purpose:  This module is a model of a line segment on plan defined by two vectors
 *
 ****************************************************************************/
#ifndef LINE_H
#define LINE_H

#include "Utils/Vector2d.h"
#include "Logger/Logging.h"

struct Line {
    Line(const Line &other);
    Line(Vector2d iStart = Vector2d::ZERO, Vector2d iEnd = Vector2d::ZERO);
    virtual ~Line();

    double length(void) const;
    double angleHypothenuseX(void) const;
    Vector2d getCoordOnLine(double distanceFromStart) const;

    Vector2d start;
    Vector2d end;

};


#endif
