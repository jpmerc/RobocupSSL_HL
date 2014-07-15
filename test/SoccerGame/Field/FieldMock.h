#ifndef FIELD_MOCK_H
#define FIELD_MOCK_H

#include <gmock/gmock.h>

#include "SoccerGame/Field/Field.h"
#include "Utils/Vector2d.h"

class FieldMock : public Field{
public:
    MOCK_METHOD0(getWidth, double());
    MOCK_METHOD0(getHeight, double());
    MOCK_METHOD0(getPlayableWidth, double());
    MOCK_METHOD0(getPlayableHeight, double());
    MOCK_METHOD1(isInPlayableArea, bool(const Vector2d &iCoordinate));
};

#endif
