#include <gtest/gtest.h>

#include <math.h>

#include "Utils/Pose.h"

class PoseTest : public testing::Test{

};

TEST_F(PoseTest, it_is_initializable_with_no_arguments){
    Pose aPose;
    Orientation aNullOrientation;
    Vector2d aNullVector;

    ASSERT_EQ(aPose.Angle, aNullOrientation);
    ASSERT_EQ(aPose.Position, aNullVector);
}

TEST_F(PoseTest, it_is_initializable_with_a_vector_and_orientation_argument){
    Orientation anOrientation(0.50);
    Vector2d aVector(12,45);
    Pose aPose(aVector,anOrientation);

    ASSERT_EQ(aPose.Angle, anOrientation);
    ASSERT_EQ(aPose.Position, aVector);
}

TEST_F(PoseTest, it_is_initializable_with_a_vector_and_double_argument){
    Orientation anOrientation(0.50);
    Vector2d aVector(12,45);
    Pose aPose(aVector,0.50);

    ASSERT_EQ(aPose.Angle, anOrientation);
    ASSERT_EQ(aPose.Position, aVector);
}

TEST_F(PoseTest, it_is_initializable_with_two_double_and_orientation_argument){
    Orientation anOrientation(0.50);
    Vector2d aVector(12,45);
    Pose aPose(12,45,anOrientation);

    ASSERT_EQ(aPose.Angle, anOrientation);
    ASSERT_EQ(aPose.Position, aVector);
}

TEST_F(PoseTest, it_is_initializable_with_three_double_argument){
    Orientation anOrientation(0.50);
    Vector2d aVector(12,45);
    Pose aPose(12,45,0.50);

    ASSERT_EQ(aPose.Angle, anOrientation);
    ASSERT_EQ(aPose.Position, aVector);
}

TEST_F(PoseTest, it_is_initializable_with_pose_argument){
    Orientation anOrientation(0.50);
    Vector2d aVector(12,45);
    Pose aPose(aVector,anOrientation);
    Pose aCopyPose(aPose);

    ASSERT_EQ(aCopyPose.Angle, aPose.Angle);
    ASSERT_EQ(aCopyPose.Position, aPose.Position);
}

TEST_F(PoseTest, it_should_be_the_same_as_another_Pose_with_same_attribute){
    double x = -4;
    double y = 12;
    double theta = 0.12;
    Pose aPose(x,y,theta);
    Pose anotherPose(x,y,theta);

    ASSERT_EQ(aPose,anotherPose);
}

TEST_F(PoseTest, it_should_be_different_than_another_Pose_with_different_attribute){
    double x = -4;
    double y = 12;
    double theta = 0.12;
    Pose aPose(x,y,theta);
    Pose anotherPose;

    ASSERT_NE(aPose,anotherPose);
}
