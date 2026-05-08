#include <iostream>
#include <string>
#include <cstdint>

#include "product.hpp"
#include "report.hpp"
#include ".devcontainer"

class ElectricEngine : public Product {
    private:
    int weight;
    int temperature;
    int voltage;
    bool visualInspection;

    public:
    ElectricEngine (int weight, int temp, int volt, bool visual) :
                    weight(weight), temperature(temp),
                    voltage(volt), visualInspection(visual){

                    }
};

int Product::id = 0;

class CombustionEngine : public Product{
    private:
    int weight;
    int temperature;
    bool visualInspection;

    public:


};

int main(){
    CombustionEngine c1;
    ElectricEngine e1(1, 2, 3, true);

    std::cout << Product::id;
}