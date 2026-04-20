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

    std::cout << "Enter age: ";
    while(true){
        if(!(std::cin >> age)){
            std::cout << "Not a valid input. Try again. \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

        else if(age < 0){
            std::cout << "No negative ages allowed. Try again. \n";
    }
        else if(age > AGE_MAX){
            std::cout << "Unrealistic age. Try again. \n";
    }   
        else {
            break;
    }
        std::cout << "Enter age: ";
    }
    
    std::cout << "You are " << age << " years old. \n";
    if (validation::Senior(age)){
        std::cout << "You are a Senior. \n";
    }
    else if (validation::Adult(age)){
        std::cout << "You are an Adult. \n";
    }
    else {
        std::cout << "You are a child. \n";
    }
    

}
