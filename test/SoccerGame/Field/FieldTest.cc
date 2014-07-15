#include <gtest/gtest.h>

#include "SoccerGame/Field/Field.h"

class FieldTest : public testing::Test {
protected:
    Field* aField;
    virtual void SetUp(){
        aField = new Field;
    }
    virtual void TearDown(){
        delete aField;
    }
};

TEST_F(FieldTest, it_should_have_a_null_width_by_default){
    ASSERT_EQ(aField->getWidth(), 0);
}

TEST_F(FieldTest, it_should_have_a_null_height_by_default){
    ASSERT_EQ(aField->getHeight(), 0);
}

TEST_F(FieldTest, it_should_have_a_null_playable_width_by_default){
    ASSERT_EQ(aField->getPlayableWidth(), 0);
}

TEST_F(FieldTest, it_should_have_a_null_playable_height_by_default){
    ASSERT_EQ(aField->getPlayableHeight(), 0);
}

TEST_F(FieldTest, it_should_have_a_point_inside_the_playable_area){
    Field anotherField(500, 500, 450, 450);
    Vector2d aPointInsidePlayableArea(300, 200);

    ASSERT_TRUE(anotherField.isInPlayableArea(aPointInsidePlayableArea));
}

TEST_F(FieldTest, it_should_have_a_point_outsite_the_playable_area){
    Field anotherField(100, 100, 50, 50);
    Vector2d aPointOutsidePlayableArea(200, 100);

    ASSERT_FALSE(anotherField.isInPlayableArea(aPointOutsidePlayableArea));
}
