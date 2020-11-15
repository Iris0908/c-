#pragma once

#include "Service.hpp"

struct BcnStatusGet : virtual Service
{
    Service& bcnStatusGet(bool& _status) override
    {
        _status = true;
        printf("bcnStatusGet is called, provide status: %u, %s\n", _status, driver.c_str());
        return *this;
    }

    virtual ~BcnStatusGet() = default;
};