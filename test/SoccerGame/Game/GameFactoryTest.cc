#include <gtest/gtest.h>

#include "SoccerGame/Game/GameFactory.h"

#include "SoccerGame/Ball/BallMock.h"
#include "SoccerGame/Field/FieldMock.h"

class GameFactoryTest : public testing::Test{
protected:
    GameFactory aGameFactory;

    FieldMock* aField;
    BallMock* aBall;

    virtual void SetUp(){
        aField = new FieldMock;

        BallId aBallId(0);
        aBall = new BallMock(aBallId);
    }

    virtual void TearDown(){
        delete aField;
        delete aBall;
    }
};

TEST_F(GameFactoryTest, it_creates_a_field){
    ASSERT_TRUE(dynamic_cast<Field*>(aGameFactory.createField()));
}

TEST_F(GameFactoryTest, it_creates_a_ball){
    BallId aBallId(0);
    ASSERT_TRUE(dynamic_cast<Ball*>(aGameFactory.createBall(aBallId)));
}

TEST_F(GameFactoryTest, it_creates_a_team){
    TeamId aTeamId(0);

    ASSERT_TRUE(dynamic_cast<Team*>(aGameFactory.createTeam(aTeamId)));
}

TEST_F(GameFactoryTest, it_creates_a_player){
    TeamId aTeamId(1);
    PlayerId aPlayerId(3);
    Navigator aNavigator;

    ASSERT_TRUE(dynamic_cast<Player*>(aGameFactory.createPlayer(aPlayerId, aTeamId,
                                                                &aNavigator)));
}

TEST_F(GameFactoryTest, it_creates_a_game){
    ASSERT_TRUE(dynamic_cast<Game*>(aGameFactory.createGame(aBall, aField)));
}
