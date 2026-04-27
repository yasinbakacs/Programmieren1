#include <iostream>
#include <cstdint>
#include <string>
#include "Section4.hpp"
/*
DrinkBuilder::DrinkBuilder(const std::string &name, int sugar, int temperature, bool withMilk)
    : name(name), sugar(sugar), temperature(temperature), withMilk(withMilk)
    {

    }
 */   
DrinkBuilder &DrinkBuilder::setName(const std::string &name){
        this->name = name;
        return *this;
}
    
DrinkBuilder &DrinkBuilder::setSugar(int sugar){
    this->sugar = sugar;
    return *this;
}

DrinkBuilder &DrinkBuilder::setTemperature(int temperature){
    this->temperature = temperature;
    return *this;
}

DrinkBuilder &DrinkBuilder::setWithMilk(bool withMilk){
    this->withMilk = withMilk;
    return *this;
}

const DrinkBuilder  &DrinkBuilder::print() const{
    std::cout << "Drink Name: " << name << std::endl;
    std::cout << "Sugar: " << sugar << std::endl;
    std::cout << "Temperature: " << temperature << std::endl;
    std::cout << "With Milk: " << std::boolalpha << withMilk << std::endl;
    return *this;
}

bool DrinkBuilder::isValid() const{
    if(sugar < DEFAULT_SUGAR || temperature < 0){
        std::cout << "Drink not valid" << std::endl;
        return false;
    }else {
        std::cout << "Drink valid." << std::endl;
        return true;
    }
}


int main(){
    DrinkBuilder drink1;
    drink1.setName("Tea").setSugar(-1).setTemperature(35).setWithMilk(true).print().isValid();

}