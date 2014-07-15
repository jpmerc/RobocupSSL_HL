#include <gtest/gtest.h>

#include "SoccerGame/Ball/Ball.h"

#include "Utils/Orientation.h"
#include "Utils/Vector2d.h"

class BallTest : public testing::Test{
protected:
    Ball* aBall;

    virtual void SetUp(){
        BallId aBallId(0);
        aBall = new Ball(aBallId);
    }

    virtual void TearDown(){
        delete aBall;
    }
};

TEST_F(BallTest, it_should_have_a_zero_orientation_by_default){
    ASSERT_EQ(aBall->getOrientation(), Orientation::ZERO);
    Orientation aNullOrientation = Orientation::ZERO;
}

TEST_F(BallTest, it_should_have_a_zero_position_by_default){
    ASSERT_EQ(aBall->getPosition(), Vector2d::ZERO);
}

TEST_F(BallTest, it_should_have_a_zero_velocity_by_default){
    ASSERT_EQ(aBall->getVelocity(), Vector2d::ZERO);
}

TEST_F(BallTest, it_is_equivalent_to_another_ball_with_the_same_id){
    BallId anotherBallId(0);
    Ball* anotherBall = new Ball(anotherBallId);

    EXPECT_EQ(*aBall, *anotherBall);

    delete anotherBall;
}
