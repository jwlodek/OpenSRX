#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "opensrx/app.hpp"

using ::testing::HasSubstr;

TEST(AppTest, ReturnsProjectName)
{
    EXPECT_THAT(opensrx::app_name(), HasSubstr("OpenSRX"));
}