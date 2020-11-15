#include "ClockService.hpp"

MakeClockService::MakeClockService(std::string driver) 
        : clockService(std::make_unique<ClockService>(driver))
{
}

Service& MakeClockService::operator()() const
{
    return *clockService;
}