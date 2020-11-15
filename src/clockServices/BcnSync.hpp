#pragma once

#include "Service.hpp"

struct BcnSync : virtual Service
{
    Service& bcnSyncSet(uint32_t _status) override
    {
        status = _status;
        printf("bcnSyncSet is called, save status: %u, %s\n", status, driver.c_str());
        return *this;
    }

    Service& bcnSyncGet(uint32_t& _status) override
    {
        _status = status;
        printf("bcnSyncGet is called, provide status: %u, %s\n", status, driver.c_str());
        return *this;
    }
    
    virtual ~BcnSync() = default;

private:
    static uint32_t status;
};

uint32_t BcnSync::status{};