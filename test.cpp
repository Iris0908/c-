#include <memory>
#include <iostream>

struct clean
{
    uint32_t a;
    uint32_t b;
};

decltype(auto) test(std::unique_ptr<clean>&& p)
{
    p->a = 100;
    p->b = 200;
    return std::move(p);
}

int main()
{
    auto pw = std::make_unique<clean>();
    pw->a = 10;
    pw->b = 20;
    auto t = test(std::move(pw));

    std::cout << pw->a << pw->b << std::endl;
}