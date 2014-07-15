#include <gtest/gtest.h>

#include <Utils/Orientation.h>
#include <Utils/Vector2f.h>

class OrientationTest : public testing::Test{
protected:
    Orientation* anOrientation;

    virtual void SetUp(){
        anOrientation = new Orientation();
    }

    virtual void TearDown(){
        delete anOrientation;
    }
};

TEST_F(OrientationTest, it_should_have_a_null_polar_by_default){
    ASSERT_EQ(anOrientation->getPolar(), 0.0f);
}

TEST_F(OrientationTest, it_should_have_a_1_cartesian_x_by_default){
    ASSERT_EQ(anOrientation->getCartesian().x, 1.0f);
}

TEST_F(OrientationTest, it_should_have_a_null_cartesian_y_by_default){
    ASSERT_EQ(anOrientation->getCartesian().y, 0.0f);
}

TEST_F(OrientationTest, it_is_initializable_with_double_arguments){
    double x = 2.3;
    double y = 0.9;
    Orientation anotherOrientation(x, y);

    ASSERT_EQ(anotherOrientation.getCartesian().x, x);
    ASSERT_EQ(anotherOrientation.getCartesian().y, y);
}

TEST_F(OrientationTest, it_is_initializable_with_a_vector2d_argument){
    double x = 2.3;
    double y = 0.9;
    Vector2d aVector2d(x, y);
    Orientation anotherOrientation(aVector2d);

    ASSERT_EQ(anotherOrientation.getCartesian().x, aVector2d.x);
    ASSERT_EQ(anotherOrientation.getCartesian().y, aVector2d.y);
}

TEST_F(OrientationTest, it_should_not_be_different_than_another_orientation_with_same_attributes){
    Orientation anotherOrientation;

    ASSERT_EQ(*anOrientation, anotherOrientation);
}

TEST_F(OrientationTest, it_should_be_different_than_another_orientation_with_different_attributes){
    double x = 2.0;
    double y = 1.0;
    Orientation anotherOrientation(x, y);

    ASSERT_NE(*anOrientation, anotherOrientation);
}

//TEST_F(OrientationTest, it_is_initializable_with_a_degree_argument){

//}

//TEST_F(OrientationTest, it_is_initializable_with_a_radian_argument){

//}
