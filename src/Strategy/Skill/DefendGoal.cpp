#include "Strategy/Skill/DefendGoal.h"

DefendGoal::DefendGoal(){
}

CommandStruct DefendGoal::update(ParameterStruct iParam){

    Line lSegment = GameEvaluator::getLineBetweenBallAndCoord(Vector2d(-3025,0));
    Vector2d lCoord = lSegment.getCoordOnLine(350);
    iParam.positionTarget = Pose(lCoord,Orientation::ZERO);
    mCurrentSkill = new Move();
    return (*mCurrentSkill)(iParam);
}
