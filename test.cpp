#include "Service.hpp"

int main()
{
    std::string driver = "Driver was called now\n";
    uint32_t status{};
    bool isSynced{false};

    MakeClockService(driver)()
            .bcnSyncGet(status)
            .bcnSyncSet(status)
            .bcnStatusGet(isSynced);

    printf("isSynced: %s\n", isSynced ? "True" : "False");
    return 0;
}