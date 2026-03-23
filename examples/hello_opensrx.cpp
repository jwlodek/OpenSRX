#include <iostream>

#include "opensrx/app.hpp"

int main()
{
    std::cout << "Hello from " << opensrx::app_name() << '\n';
    return 0;
}