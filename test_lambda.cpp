#include <memory>
#include <iostream>
#include <functional>

decltype(auto) convert(std::function<uint32_t()>&& func)
{
    auto handle = [func = std::move(func)]()->decltype(auto)
                    {
                        auto f = [func = std::move(func)]
                        {
                            std::cout << func() << std::endl;
                        };

                        return f;
                    };
    return handle;
}

struct Handle
{
    uint32_t a{1000};

    decltype(auto) handler()
    {
        auto handle = convert([this]()->decltype(auto){return a;});
        return handle();
    }
};

int main()
{
    Handle handle;
    auto func = handle.handler();
    func();
}