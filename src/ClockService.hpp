#pragma once

#include "clockServices/BcnSync.hpp"
#include "clockServices/BcnStatusGet.hpp"

struct ClockService : BcnSync, BcnStatusGet
{
    ClockService(std::string _driver) : Service(_driver){}
};