#include "Base.hpp"
#include <iostream>

int main(void) {
    Base* p1 = generate();
    identify(p1);
    identify(*p1);
    delete p1;
    
    std::cout << std::endl;
    Base* p2 = generate();
    identify(p2);
    identify(*p2);
    delete p2;
    
    std::cout << std::endl;
    Base* p3 = generate();
    identify(p3);
    identify(*p3);
    delete p3;
    
    return 0;
}
