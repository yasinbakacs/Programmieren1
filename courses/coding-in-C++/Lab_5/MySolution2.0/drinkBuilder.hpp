#ifndef DRINKBUILDER_HPP
#define DRINKBUILDER_HPP
#include <iostream>
#include <string.h>


class DrinkBuilder{
    private:
    std::string name;
    int sugar;
    int temperature;
    bool withMilk;
    
    public:
    DrinkBuilder(const std::string &name, int sugar, int temperature, bool withMilk);

    DrinkBuilder& setName(const std::string &name);

    DrinkBuilder& setSugar(int sugar);

    DrinkBuilder& setTemperature(int temp);

    DrinkBuilder& setWithMilk(bool milk);

    void print();

    


    
};
#endif

