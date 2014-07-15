#include <gtest/gtest.h>

#include <math.h>

#include "Utils/Vector2d.h"


class Vector2dTest : public testing::Test{

};

TEST_F(Vector2dTest, it_is_initializable_with_no_arguments){
    Vector2d aVector2d;

    ASSERT_EQ(aVector2d.x, 0.0);
    ASSERT_EQ(aVector2d.y, 0.0);
}

TEST_F(Vector2dTest, it_is_initializable_with_float_arguments){
    float x = 1.0;
    float y = 2.0;
    Vector2d aVector2d(x, y);

    ASSERT_EQ(aVector2d.x, x);
    ASSERT_EQ(aVector2d.y, y);
}

TEST_F(Vector2dTest, it_is_initializable_with_an_other_Vector2d){
    float x = 4.0;
    float y = -3.0;
    Vector2d anOtherVector2d(x, y);
    Vector2d aVector2d(anOtherVector2d);

    ASSERT_EQ(aVector2d.x, x);
    ASSERT_EQ(aVector2d.y, y);
}

TEST_F(Vector2dTest, it_should_return_the_length_of_the_Vector2d){
    float x = 4.0;
    float y = 3.0;
    float length = sqrt(pow(x, 2) + pow(y, 2));
    Vector2d aVector2d(x, y);

    ASSERT_EQ(aVector2d.length(), length);
}

TEST_F(Vector2dTest, it_should_add_two_Vector2d){
    float x1 = 1.5;
    float y1 = -0.5;
    Vector2d aVector2d(x1, y1);

    float x2 = 0.5;
    float y2 = 0.5;
    Vector2d anOtherVector2d(x2, y2);

    Vector2d resVector2d = aVector2d + anOtherVector2d;

    ASSERT_EQ((aVector2d.x + anOtherVector2d.x), resVector2d.x);
    ASSERT_EQ((aVector2d.y + anOtherVector2d.y), resVector2d.y);
}

TEST_F(Vector2dTest, it_should_substract_two_Vector2d){
    float x1 = 1.5;
    float y1 = -0.5;
    Vector2d aVector2d(x1, y1);

    float x2 = 0.5;
    float y2 = 0.5;
    Vector2d anOtherVector2d(x2, y2);

    Vector2d resVector2d = aVector2d - anOtherVector2d;

    ASSERT_EQ((aVector2d.x - anOtherVector2d.x), resVector2d.x);
    ASSERT_EQ((aVector2d.y - anOtherVector2d.y), resVector2d.y);
}

TEST_F(Vector2dTest, it_should_multiply_two_Vector2d){
    float x1 = 1.5;
    float y1 = -0.5;
    Vector2d aVector2d(x1, y1);

    float x2 = 0.5;
    float y2 = 0.5;
    Vector2d anOtherVector2d(x2, y2);

    Vector2d resVector2d = aVector2d * anOtherVector2d;

    ASSERT_EQ((aVector2d.x * anOtherVector2d.x), resVector2d.x);
    ASSERT_EQ((aVector2d.y * anOtherVector2d.y), resVector2d.y);
}

TEST_F(Vector2dTest, it_should_multiply_a_Vector2d_by_a_scalar){
    float x = 1.5;
    float y = -0.5;
    Vector2d aVector2d(x, y);

    float scalar = 2.0;

    Vector2d resVector2d = aVector2d * scalar;

    ASSERT_EQ((aVector2d.x * scalar), resVector2d.x);
    ASSERT_EQ((aVector2d.y * scalar), resVector2d.y);
}

TEST_F(Vector2dTest, it_should_divide_two_Vector2d){
    float x1 = 1.5;
    float y1 = -0.5;
    Vector2d aVector2d(x1, y1);

    float x2 = 0.5;
    float y2 = 0.5;
    Vector2d anOtherVector2d(x2, y2);

    Vector2d resVector2d = aVector2d / anOtherVector2d;

    ASSERT_EQ((aVector2d.x / anOtherVector2d.x), resVector2d.x);
    ASSERT_EQ((aVector2d.y / anOtherVector2d.y), resVector2d.y);
}

TEST_F(Vector2dTest, it_should_not_divide_a_Vector2d_with_a_zero_Vector2d){
    float x = 1.5;
    float y = -0.5;
    Vector2d aVector2d(x, y);
    Vector2d anOtherVector2d;

    Vector2d resVector2d = aVector2d / anOtherVector2d;

    ASSERT_EQ(aVector2d.x, resVector2d.x);
    ASSERT_EQ(aVector2d.y, resVector2d.y);
}

TEST_F(Vector2dTest, it_should_divide_a_Vector2d_with_a_scalar){
    float x = 1.5;
    float y = -0.5;
    Vector2d aVector2d(x, y);

    float scalar = 2.0;

    Vector2d resVector2d = aVector2d / scalar;

    ASSERT_EQ((aVector2d.x / scalar), resVector2d.x);
    ASSERT_EQ((aVector2d.y / scalar), resVector2d.y);
}

TEST_F(Vector2dTest, it_should_not_divide_a_Vector2d_with_a_zero_scalar){
    float x = 1.5;
    float y = -0.5;
    Vector2d aVector2d(x, y);

    float scalar = 0.0;

    Vector2d resVector2d = aVector2d / scalar;

    ASSERT_EQ(aVector2d, resVector2d);
}

TEST_F(Vector2dTest, it_should_be_replaceable_with_an_other_Vector2d){
    float x = -9.2;
    float y = 3.3;
    Vector2d aVector2d;
    Vector2d anOtherVector2d(x, y);

    aVector2d = anOtherVector2d;

    ASSERT_EQ(aVector2d.x, x);
    ASSERT_EQ(aVector2d.y, y);
}

TEST_F(Vector2dTest, it_should_assign_a_Vector2d_to_an_other){
    float x = -1.0;
    float y = 2.5;
    Vector2d aVector2d(x, y);

    Vector2d resVector2d = aVector2d;

    ASSERT_EQ(aVector2d.x, resVector2d.x);
    ASSERT_EQ(aVector2d.y, resVector2d.y);
}

TEST_F(Vector2dTest, it_should_be_different_than_another_Vector2d_with_different_attributes){
    float x = -1.0;
    float y = 2.5;
    Vector2d aVector2d(x, y);
    Vector2d anOtherVector2d;

    ASSERT_NE(aVector2d, anOtherVector2d);
}

TEST_F(Vector2dTest, it_should_not_be_different_than_another_Vector2d_with_same_attributes){
    float x = -1.0;
    float y = 2.5;
    Vector2d aVector2d(x, y);
    Vector2d anOtherVector2d(x, y);

    ASSERT_EQ(aVector2d, anOtherVector2d);
}
