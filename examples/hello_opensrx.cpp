#include <iostream>

#include "opensrx/api.hpp"

int main() {
    std::cout << "Hello from " << OpenSRX::app_name() << '\n';
    return 0;
}
