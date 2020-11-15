#include <gtest/gtest.h>
#include "Service.hpp"

TEST(ClockServiceTest, init)
{

    std::string driver = "Driver was called now\n";
    uint32_t status{};
    bool isSynced{false};

    MakeClockService(driver)()
            .bcnSyncGet(status)
            .bcnSyncSet(status)
            .bcnStatusGet(isSynced);

    ASSERT_EQ(isSynced, true);
    printf("isSynced: %s\n", isSynced ? "True" : "False");
}

GTEST_API_ int main(int argc, char ** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}