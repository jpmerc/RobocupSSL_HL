#include <gtest/gtest.h>

#include <math.h>

#include "Utils/Vector2f.h"


class Vector2fTest : public testing::Test{

};

TEST_F(Vector2fTest, it_is_initializable_with_no_arguments){
    Vector2f aVector2f;

    ASSERT_EQ(aVector2f.x, 0.0f);
    ASSERT_EQ(aVector2f.y, 0.0f);
}

TEST_F(Vector2fTest, it_is_initializable_with_float_arguments){
    float x = 1.0f;
    float y = 2.0f;
    Vector2f aVector2f(x, y);

    ASSERT_EQ(aVector2f.x, x);
    ASSERT_EQ(aVector2f.y, y);
}

TEST_F(Vector2fTest, it_is_initializable_with_an_other_vector2f){
    float x = 4.0f;
    float y = -3.0f;
    Vector2f anOtherVector2f(x, y);
    Vector2f aVector2f(anOtherVector2f);

    ASSERT_EQ(aVector2f.x, x);
    ASSERT_EQ(aVector2f.y, y);
}

TEST_F(Vector2fTest, it_should_return_the_length_of_the_vector2f){
    float x = 4.0f;
    float y = 3.0f;
    float length = sqrt(pow(x, 2) + pow(y, 2));
    Vector2f aVector2f(x, y);

    ASSERT_EQ(aVector2f.length(), length);
}

TEST_F(Vector2fTest, it_should_add_two_vector2f){
    float x1 = 1.5f;
    float y1 = -0.5f;
    Vector2f aVector2f(x1, y1);

    float x2 = 0.5f;
    float y2 = 0.5f;
    Vector2f anOtherVector2f(x2, y2);

    Vector2f resVector2f = aVector2f + anOtherVector2f;

    ASSERT_EQ((aVector2f.x + anOtherVector2f.x), resVector2f.x);
    ASSERT_EQ((aVector2f.y + anOtherVector2f.y), resVector2f.y);
}

TEST_F(Vector2fTest, it_should_substract_two_vector2f){
    float x1 = 1.5f;
    float y1 = -0.5f;
    Vector2f aVector2f(x1, y1);

    float x2 = 0.5f;
    float y2 = 0.5f;
    Vector2f anOtherVector2f(x2, y2);

    Vector2f resVector2f = aVector2f - anOtherVector2f;

    ASSERT_EQ((aVector2f.x - anOtherVector2f.x), resVector2f.x);
    ASSERT_EQ((aVector2f.y - anOtherVector2f.y), resVector2f.y);
}

TEST_F(Vector2fTest, it_should_multiply_two_vector2f){
    float x1 = 1.5f;
    float y1 = -0.5f;
    Vector2f aVector2f(x1, y1);

    float x2 = 0.5f;
    float y2 = 0.5f;
    Vector2f anOtherVector2f(x2, y2);

    Vector2f resVector2f = aVector2f * anOtherVector2f;

    ASSERT_EQ((aVector2f.x * anOtherVector2f.x), resVector2f.x);
    ASSERT_EQ((aVector2f.y * anOtherVector2f.y), resVector2f.y);
}

TEST_F(Vector2fTest, it_should_multiply_a_vector2f_by_a_scalar){
    float x = 1.5f;
    float y = -0.5f;
    Vector2f aVector2f(x, y);

    float scalar = 2.0f;

    Vector2f resVector2f = aVector2f * scalar;

    ASSERT_EQ((aVector2f.x * scalar), resVector2f.x);
    ASSERT_EQ((aVector2f.y * scalar), resVector2f.y);
}

TEST_F(Vector2fTest, it_should_divide_two_vector2f){
    float x1 = 1.5f;
    float y1 = -0.5f;
    Vector2f aVector2f(x1, y1);

    float x2 = 0.5f;
    float y2 = 0.5f;
    Vector2f anOtherVector2f(x2, y2);

    Vector2f resVector2f = aVector2f / anOtherVector2f;

    ASSERT_EQ((aVector2f.x / anOtherVector2f.x), resVector2f.x);
    ASSERT_EQ((aVector2f.y / anOtherVector2f.y), resVector2f.y);
}

TEST_F(Vector2fTest, it_should_not_divide_a_vector2f_with_a_zero_vector2f){
    float x = 1.5f;
    float y = -0.5f;
    Vector2f aVector2f(x, y);
    Vector2f anOtherVector2f;

    Vector2f resVector2f = aVector2f / anOtherVector2f;

    ASSERT_EQ(aVector2f.x, resVector2f.x);
    ASSERT_EQ(aVector2f.y, resVector2f.y);
}

TEST_F(Vector2fTest, it_should_divide_a_vector2f_with_a_scalar){
    float x = 1.5f;
    float y = -0.5f;
    Vector2f aVector2f(x, y);

    float scalar = 2.0f;

    Vector2f resVector2f = aVector2f / scalar;

    ASSERT_EQ((aVector2f.x / scalar), resVector2f.x);
    ASSERT_EQ((aVector2f.y / scalar), resVector2f.y);
}

TEST_F(Vector2fTest, it_should_not_divide_a_vector2f_with_a_zero_scalar){
    float x = 1.5f;
    float y = -0.5f;
    Vector2f aVector2f(x, y);

    float scalar = 0.0f;

    Vector2f resVector2f = aVector2f / scalar;

    ASSERT_EQ(aVector2f, resVector2f);
}

TEST_F(Vector2fTest, it_should_be_replaceable_with_another_vector2f){
    float x = -9.2f;
    float y = 3.3f;
    Vector2f aVector2f;
    Vector2f anOtherVector2f(x, y);

    aVector2f = anOtherVector2f;

    ASSERT_EQ(aVector2f.x, x);
    ASSERT_EQ(aVector2f.y, y);
}

TEST_F(Vector2fTest, it_should_assign_a_vector2f_to_another){
    float x = -1.0f;
    float y = 2.5f;
    Vector2f aVector2f(x, y);

    Vector2f resVector2f = aVector2f;

    ASSERT_EQ(aVector2f.x, resVector2f.x);
    ASSERT_EQ(aVector2f.y, resVector2f.y);
}

TEST_F(Vector2fTest, it_should_be_different_than_another_vector2f_with_different_attributes){
    float x = -1.0f;
    float y = 2.5f;
    Vector2f aVector2f(x, y);
    Vector2f anOtherVector2f;

    ASSERT_NE(aVector2f, anOtherVector2f);
}

TEST_F(Vector2fTest, it_should_not_be_different_than_another_vector2f_with_same_attributes){
    float x = -1.0f;
    float y = 2.5f;
    Vector2f aVector2f(x, y);
    Vector2f anOtherVector2f(x, y);

    ASSERT_EQ(aVector2f, anOtherVector2f);
}
