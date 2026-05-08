#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <iostream>
#include <string>
#include <cstdint>

#include "report.hpp"


class Product : Report{
    private:
    static int id;
    static std::string name;

    public: 
    Product(){id++;}

    virtual std::string generateReport() const {}

};

int Product::id = 0;

class ElectricEngine : public Product {
    private:
    int weight;
    int temperature;
    int voltage;
    bool visualInspection;

    public:
    ElectricEngine (int weight, int temp, int volt, bool visual) :
                    weight(weight), temperature(temp),
                    voltage(volt), visualInspection(visual){}
    
    std::string generateReport() const override {}

    
};



class CombustionEngine : public Product{
    private:
    int weight;
    int temperature;
    bool visualInspection;

    public:


};




#endif
