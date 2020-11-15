#include <gtest/gtest.h>
#include "Service.hpp"

TEST(ClockServiceTest, init)
{

    std::string driver = "Driver was called now\n";
    uint32_t setStatus{1000};
    uint32_t getStatus{};
    bool isSynced{false};

    MakeClockService(driver)()
            .bcnSyncSet(setStatus)
            .bcnSyncGet(getStatus)
            .bcnStatusGet(isSynced);

    ASSERT_EQ(isSynced, true);
    ASSERT_EQ(setStatus, getStatus);
    printf("isSynced: %s\n", isSynced ? "True" : "False");

    getStatus = 0;
    MakeClockService(driver)()
            .bcnSyncGet(getStatus);
    ASSERT_EQ(setStatus, getStatus);
}

GTEST_API_ int main(int argc, char ** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}