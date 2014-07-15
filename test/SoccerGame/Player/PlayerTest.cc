#include <gtest/gtest.h>

#include "SoccerGame/Player/Player.h"

class PlayerTest : public testing::Test {
protected:
    Player* aPlayer;

    virtual void SetUp() {
        PlayerId aPlayerId(0);
        TeamId aTeamId(0);
        Navigator aNavigator;
        aPlayer = new Player(aPlayerId, aTeamId, &aNavigator);
    }

    virtual void TearDown() {
        delete aPlayer;
    }
};

TEST_F(PlayerTest, it_is_initializable){

}

TEST_F(PlayerTest, it_is_equivalent_to_another_player_with_the_same_id){
    PlayerId anotherPlayerId(0);
    TeamId anotherTeamId(0);
    Navigator aNavigator;
    Player* anotherPlayer = new Player(anotherPlayerId, anotherTeamId,&aNavigator);

    EXPECT_EQ(*aPlayer, *anotherPlayer);

    delete anotherPlayer;
}
