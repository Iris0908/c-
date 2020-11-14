#pragma once

#include <memory>
#include <string>

class ServicesException : std::runtime_error
{
public:
    ServicesException(std::string _message) : std::runtime_error(_message){}
};

struct Service
{
    Service() = default;
    virtual ~Service() = default;
    Service(std::string _driver) : driver(_driver) {}

    virtual Service& updateDeviceDriver()
    {
        throw ServicesException("updateDeviceDriver implemtation is empty\n");
    }

    virtual Service& bcnSyncSet(uint32_t status)
    {
        (void)status;
        throw ServicesException("bcnSyncSet implemtation is empty\n");
    }

    virtual Service& bcnSyncGet(uint32_t& status)
    {
        (void)status;
        throw ServicesException("bcnSyncGet implemtation is empty\n");
    }

    virtual Service& bcnStatusGet(bool& isSynced)
    {
        (void)isSynced;
        throw ServicesException("bcnStatusGet implemtation is empty\n");
    }

protected:
    std::string driver{"Driver was not called\n"};
};

class MakeClockService
{
public:
    MakeClockService(std::string);

    Service& operator()() const;

private:
    std::unique_ptr<Service> clockService{nullptr};
};