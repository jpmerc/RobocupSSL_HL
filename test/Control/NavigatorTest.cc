#include <gtest/gtest.h>

#include <math.h>

#include "Control/Navigator.h"

class NavigatorTest : public testing::Test{

};

TEST_F(NavigatorTest, it_should_have_a_null_actualposition_by_default){
    Navigator aNavigator;
    Pose aNullPose(Pose::ZERO);

    ASSERT_EQ(aNavigator.getActualPose(), aNullPose);
}

TEST_F(NavigatorTest, it_should_have_a_null_goalposition_by_default){
    Navigator aNavigator;
    Pose aNullPose(Pose::ZERO);

    ASSERT_EQ(aNavigator.getGoalPose(), aNullPose);
}


TEST_F(NavigatorTest, it_should_have_a_false_isNewGoalReady_by_default){
    Navigator aNavigator;

    ASSERT_EQ(aNavigator.getIsNewGoalReady(), false);
}


TEST_F(NavigatorTest, it_should_return_true_if_distance_is_lower_than_waypointRadius){
    Navigator aNavigator(100);
    Pose actualPosition(10,11,0.5);
    Pose goalPosition(0,0,0);
    aNavigator.setActualPose(actualPosition);
    aNavigator.setGoalPose(goalPosition);

    ASSERT_TRUE(aNavigator.isPositionGoalReached());
}

TEST_F(NavigatorTest, it_should_return_false_if_distance_is_higher_than_waypointRadius){
    Navigator aNavigator(100);
    Pose actualPosition(231,1541,1);
    Pose goalPosition(0,0,0);
    aNavigator.setActualPose(actualPosition);
    aNavigator.setGoalPose(goalPosition);

    ASSERT_FALSE(aNavigator.isPositionGoalReached());
}

TEST_F(NavigatorTest, it_should_return_true_if_angle_is_lower_than_waypointAngle){
    Navigator aNavigator(100,0.1);
    Pose actualPosition(0,0,0.05);
    Pose goalPosition(0,0,0);
    aNavigator.setActualPose(actualPosition);
    aNavigator.setGoalPose(goalPosition);

    ASSERT_TRUE(aNavigator.isAngleGoalReached());
}

TEST_F(NavigatorTest, it_should_return_false_if_Angle_is_higher_than_waypointAngle){
    Navigator aNavigator(100,0.1);
    Pose actualPosition(0,0,0.2);
    Pose goalPosition(0,0,0);
    aNavigator.setActualPose(actualPosition);
    aNavigator.setGoalPose(goalPosition);

    ASSERT_FALSE(aNavigator.isAngleGoalReached());
}

TEST_F(NavigatorTest, it_should_return_a_correct_speed_command){
    Navigator aNavigator;
    Pose actualPosition(1005,0,0);
    Pose goalPosition(0,0,0);
    aNavigator.setActualPose(actualPosition);
    aNavigator.setGoalPose(goalPosition);

    ASSERT_EQ(aNavigator.calculateNewVector(),Vector2d(-1,0));
}

TEST_F(NavigatorTest, it_should_return_a_correct_Speedangle_command){
    Navigator aNavigator;
    Pose actualPosition(1,0,0);
    Pose goalPosition(0,0,0.5);
    aNavigator.setActualPose(actualPosition);
    aNavigator.setGoalPose(goalPosition);

    ASSERT_EQ(aNavigator.calculateNewOrientation(),Orientation(1.5));
}

