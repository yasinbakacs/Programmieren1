#include <iostream>
#include <string>
#include <cstdint>

#include "product.hpp"
#include "report.hpp"
#include <iostream>
#include <string>



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