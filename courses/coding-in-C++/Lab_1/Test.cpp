#include <iostream>
#include <cstdint>
#include <limits>

namespace validation{
    const std::uint8_t ADULT_AGE_LIMIT = 18;
    const std::uint8_t Senior_AGE_LIMIT = 65;

    bool Adult(std::uint8_t age){
        return age >= ADULT_AGE_LIMIT;
    }

    bool Senior(std::uint8_t age){
        return age >= Senior_AGE_LIMIT;
    }
}


int main(){
    std::uint8_t AGE_MAX = 130;
    int age = 0;

    std::cout << "Enter your age: ";
    
}
