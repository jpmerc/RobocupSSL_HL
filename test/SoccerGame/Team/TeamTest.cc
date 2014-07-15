#include <gtest/gtest.h>

#include "SoccerGame/Team/Team.h"

#include "SoccerGame/Player/PlayerMock.h"

class TeamTest : public testing::Test {
protected:
    Team* aTeam;

    virtual void SetUp() {
        TeamId aTeamId(0);

        aTeam = new Team(aTeamId);
    }

    virtual void TearDown() {
        delete aTeam;
    }

    void loadATeam();
};

TEST_F(TeamTest, it_should_not_have_players_by_default){
    ASSERT_EQ(aTeam->getPlayers().size(), 0);
}

TEST_F(TeamTest, it_can_be_added_a_player){
    PlayerId aPlayerId(0);
    Player* aPlayer = new Player(aPlayerId, aTeam->getId());

    ASSERT_TRUE(aTeam->addPlayer(aPlayer));
}

TEST_F(TeamTest, it_can_not_be_added_two_players_with_same_id){
    PlayerId aPlayerId(0);
    PlayerId anotherPlayerId(0);
    Player* aPlayer = new Player(aPlayerId, aTeam->getId());
    Player* anotherPlayer = new Player(anotherPlayerId, aTeam->getId());

    ASSERT_TRUE(aTeam->addPlayer(aPlayer));
    ASSERT_FALSE(aTeam->addPlayer(anotherPlayer));
}

TEST_F(TeamTest, it_should_have_a_player_that_has_been_added){
    PlayerId aPlayerId(4);
    Player* aPlayer = new Player(aPlayerId, aTeam->getId());

    aTeam->addPlayer(aPlayer);

    ASSERT_TRUE(aTeam->hasPlayer(aPlayerId));
}

TEST_F(TeamTest, it_should_not_have_a_player_that_has_not_been_added){
    PlayerId aPlayerId(4);

    ASSERT_FALSE(aTeam->hasPlayer(aPlayerId));
}

TEST_F(TeamTest, it_updates_players_positions){
    this->loadATeam();
    std::map<PlayerId, Pose> someCoordinates;

    for(int i = 0; i < 7; i++){
        PlayerId aPlayerId(i);
        Pose aPosition(i, i, i);

        someCoordinates.insert(std::pair<PlayerId, Pose>(aPlayerId, aPosition));
    }

    aTeam->updatePlayersPositions(someCoordinates);

    std::map<PlayerId, Player*> players = aTeam->getPlayers();
    for(int i = 0; i < 7; i++){
        PlayerId aPlayerId(i);
        ASSERT_EQ(players.find(aPlayerId)->second->getPosition().x, someCoordinates.find(aPlayerId)->second.Position.x);
        ASSERT_EQ(players.find(aPlayerId)->second->getPosition().y, someCoordinates.find(aPlayerId)->second.Position.y);
    }
}

void TeamTest::loadATeam(){
    for(int i = 0; i < 7; i++){
        PlayerId aPlayerId(i);
        Player* aPlayer = new Player(aPlayerId, aTeam->getId());

        aTeam->addPlayer(aPlayer);
    }
}
