#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // for rand(), srand()
#include <ctime> // for time()
#include <iostream>
Base * generate(void)
{
    std::srand(std::time(NULL));
    int randomNumber = rand() % 3;
    switch (randomNumber)
    {
        case 0:
                return (new A());
        case 1:
                return (new B());
        case 2:
                return (new C());
    }
    return NULL;
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "It's an A" << std::endl;
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout << "It's a B" << std::endl;
    else if(dynamic_cast<C*>(p) != NULL)
        std::cout << "It's a C" << std::endl;
    else 
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "It's an A" << std::endl;
        return;
    }
    catch (std::exception& e)
    {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "It's a B" << std::endl;
        return;
    }
    catch (std::exception& e)
    {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "It's a C" << std::endl;
        return;
    }
    catch (std::exception& e)
    {}
    std::cout << "Unknown type" << std::endl;

}

int main()
{
    Base* random_class = generate();
    identify(random_class);
    A a_class;
    identify(a_class);
    B b_class;
    identify(b_class);
    C c_class;
    identify(c_class);
    delete random_class;

}
