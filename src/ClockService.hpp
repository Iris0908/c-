#pragma once

#include "clockServices/BcnSyncGet.hpp"
#include "clockServices/BcnSyncSet.hpp"
#include "clockServices/BcnStatusGet.hpp"

struct ClockService : BcnSyncSet, BcnSyncGet, BcnStatusGet
{
    ClockService(std::string _driver) : Service(_driver){}
};