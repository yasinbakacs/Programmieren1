#include "drinkBuilder.hpp"
#include <iostream>
#include <string.h>
#include <cstdint>

DrinkBuilder::DrinkBuilder(const std::string &name, int sugar, int temperature, bool withMilk) 
                           : name(name), sugar(sugar), temperature(temperature), withMilk(withMilk){}

DrinkBuilder& DrinkBuilder::setName(const std::string &name){
    this->name = name;
    return *this;
}

DrinkBuilder& DrinkBuilder::setSugar(int sugar){
    if (sugar < 0){
        std::cout << "Please enter valid sugar ammount.\n";
        return *this;
    }
    this->sugar;
    return *this;
}

void DrinkBuilder::print(){
    std::cout << this->name <<  "\n" << this->sugar;
}



int main(){
    DrinkBuilder builder("u", 2, 3, true);

    builder.setName("ii").setSugar(-1).print();
}
