#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data data;
    data.name = "Test";
    data.value = 42;
    data.score = 98.5;

    std::cout << "Original: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized: " << ptr << std::endl;
    std::cout << "Equal: " << (ptr == &data ? "Yes" : "No") << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;

    return 0;
}
