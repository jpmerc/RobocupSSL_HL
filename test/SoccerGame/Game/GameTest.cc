#include <gtest/gtest.h>

#include "SoccerGame/Game/Game.h"
#include "SoccerGame/Field/FieldMock.h"
#include "SoccerGame/Ball/BallMock.h"

class GameTest : public testing::Test{
protected:
    Game* aGame;

    FieldMock* aField;
    BallMock* aBall;

    virtual void SetUp(){
        aField = new FieldMock;
        BallId aBallId(0);
        aBall = new BallMock(aBallId);

        aGame = new Game(aBall, aField);
    }

    virtual void TearDown(){
        //aBall and aField are destroyed by aGame
        delete aGame;
    }
};

TEST_F(GameTest, it_should_have_a_field_by_default){
    ASSERT_TRUE(aGame->getField());
}

TEST_F(GameTest, it_should_have_a_ball_by_default){
    ASSERT_TRUE(aGame->getBall());
}

TEST_F(GameTest, it_should_not_have_teams_by_default){
    ASSERT_EQ(aGame->getTeams().size(), 0);
}

TEST_F(GameTest, it_can_be_added_a_team){
    TeamId aTeamId(0);
    Team* aTeam = new Team(aTeamId);

    ASSERT_TRUE(aGame->addTeam(aTeam));
}

TEST_F(GameTest, it_can_not_be_added_two_teams_with_the_same_teamId){
    TeamId aTeamId(3);
    Team* aTeam = new Team(aTeamId);
    Team* anotherTeam = new Team(aTeamId);

    aGame->addTeam(aTeam);

    ASSERT_FALSE(aGame->addTeam(anotherTeam));
}
