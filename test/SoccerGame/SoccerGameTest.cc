#include <gtest/gtest.h>

#include "SoccerGame/SoccerGame.h"

#include "SoccerGame/Game/GameFactoryMock.h"

class SoccerGameTest : public testing::Test{
protected:
    SoccerGame aSoccerGame;

    GameFactoryMock aGameFactory;

    virtual void SetUp(){
    }

    virtual void TearDown(){
    }
};

//TEST_F(SoccerGameTest, it_creates_a_new_soccer_game){
//    ASSERT_TRUE(aSoccerGame.createSoccerGame(aGameFactory, aStrategyFactory));
//}

//TEST_F(SoccerGameTest, it_creates_the_game){
//    ASSERT_TRUE(aSoccerGame.createGame(aGameFactory));
//}

//TEST_F(SoccerGameTest, it_creates_the_strategy){
//    ASSERT_TRUE(aSoccerGame.createStrategy(aStrategyFactory));
//}

//TEST_F(SoccerGameTest, it_creates_the_navigator){
//    ASSERT_TRUE(aSoccerGame.createNavigator(aNavigatorFactory));
//}
