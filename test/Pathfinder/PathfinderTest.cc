#include <gtest/gtest.h>

#include "Pathfinder/Pathfinder.h"

#include "SoccerGame/Player/PlayerMock.h"
#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"
#include "SoccerGame/Ball/BallMock.h"

class PathfinderTest : public testing::Test{
protected:
    Pathfinder *aPathfinder;
    Ball *aBall;

    virtual void SetUp(){
        BallId aBallId(0);
        aBall = new Ball(aBallId);

        aPathfinder = new Pathfinder(*aBall);
    }

    virtual void TearDown(){
        delete aPathfinder;
    }
};

TEST_F(PathfinderTest, it_is_initializable){

}

TEST_F(PathfinderTest, it_can_be_added_a_player_as_obstacle){
    PlayerId aPlayerId(0);
    TeamId aTeamId(0);
    Navigator aNavigator;
    PlayerMock aPlayer(aPlayerId, aTeamId,&aNavigator);

    EXPECT_TRUE(aPathfinder->addObstacle(aPlayer));
}

TEST_F(PathfinderTest, it_can_not_be_added_as_obstacle_a_player_that_has_already_been_added){
    PlayerId aPlayerId(0);
    TeamId aTeamId(0);
    Navigator aNavigator;
    PlayerMock aPlayer(aPlayerId, aTeamId,&aNavigator);

    aPathfinder->addObstacle(aPlayer);

    EXPECT_FALSE(aPathfinder->addObstacle(aPlayer));
}
