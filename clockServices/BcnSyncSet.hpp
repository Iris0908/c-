#pragma once

#include "Service.hpp"

struct BcnSyncSet : virtual Service
{
    uint32_t status{};
    Service& bcnSyncSet(uint32_t _status) override
    {
        status = _status;
        printf("bcnSyncSet is called, save status: %u, %s\n", status, driver.c_str());
        return *this;
    }

    virtual ~BcnSyncSet() = default;
};