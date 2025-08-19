#include "Data.hpp"
#include "Serializer.hpp"


int main()
{
    Data data;
    Data *ptr;

    std::cout << "Adress of data:" << &data << std::endl;
    uintptr_t not_ptr = Serializer::serialize(&data);
    
    std::cout << "Adress of data as int:" << not_ptr << std::endl;
    
    ptr = Serializer::deserialize(not_ptr);
    std::cout << "Adress of data back:" << ptr << std::endl;


}