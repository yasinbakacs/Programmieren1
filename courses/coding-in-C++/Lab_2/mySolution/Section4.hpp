#ifndef SECTION4_HPP
#define SECTION4_HPP

#include <iostream>
#include <cstdint>
#include <string>

constexpr int DEFAULT_TEMP = 20;
constexpr int DEFAULT_SUGAR = 0;

class DrinkBuilder{

    private:
        std::string name = "Default Name";
        int sugar = DEFAULT_SUGAR;
        int temperature = DEFAULT_TEMP;
        bool withMilk = false;
    

    public:
        //DrinkBuilder(const std::string &name, int sugar, int temperature, bool withMilk);
        DrinkBuilder &setName(const std::string &name);
        DrinkBuilder &setSugar(int sugar);
        DrinkBuilder &setTemperature(int temperature);
        DrinkBuilder &setWithMilk(bool withMilk); 

        const DrinkBuilder &print() const;
        bool isValid() const;
    
};



#endif