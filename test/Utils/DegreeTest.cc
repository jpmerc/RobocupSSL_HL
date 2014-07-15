#include <gtest/gtest.h>

#include <math.h>

#include "Utils/Degree.h"

class DegreeTest : public testing::Test{

};

TEST_F(DegreeTest, it_is_initializable_with_no_arguments){
    Degree aDegree;

    ASSERT_EQ(aDegree.getValue(), 0.0f);
}

TEST_F(DegreeTest, it_is_initializable_with_a_float_argument){
    float degrees = 45.0f;
    Degree aDegree(degrees);

    ASSERT_EQ(aDegree.getValue(), degrees);
}
