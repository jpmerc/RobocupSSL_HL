#include <gtest/gtest.h>

#include <math.h>

#include "Utils/Radian.h"

class RadianTest : public testing::Test{

};

TEST_F(RadianTest, it_is_initializable_with_no_arguments){
    Radian aRadian;

    ASSERT_EQ(aRadian.getValue(), 0.0f);
}

TEST_F(RadianTest, it_is_initializable_with_a_float_argument){
    float radians = M_PI / 2;
    Radian aRadian(radians);

    ASSERT_EQ(aRadian.getValue(), radians);
}
