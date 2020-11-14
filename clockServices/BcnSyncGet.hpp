#pragma once

#include "Service.hpp"

struct BcnSyncGet : virtual Service
{
    Service& bcnSyncGet(uint32_t& _status) override
    {
        _status = 100;
        printf("bcnSyncGet is called, provide status: %u, %s\n", _status, driver.c_str());
        return *this;
    }

    virtual ~BcnSyncGet() = default;
};