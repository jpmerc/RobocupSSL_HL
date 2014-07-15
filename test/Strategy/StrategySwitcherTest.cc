#include <gtest/gtest.h>

#include "Strategy/StrategySwitcher.h"

class StrategySwitcherTest : public testing::Test{
protected:
    StrategySwitcher aStrategySwitcher;
    virtual void SetUp(){

    }
    virtual void TearDown(){

    }
};

TEST_F(StrategySwitcherTest, it_is_not_done){
    ASSERT_FALSE(this->aStrategySwitcher.isDone());
}
