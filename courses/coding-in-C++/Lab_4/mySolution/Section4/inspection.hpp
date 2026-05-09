#ifndef INSPECTION_HPP
#define INSPECTION_HPP

#include "product.hpp"
#include "report.hpp"
#include <iostream>
#include <string>
#include <cstdint>



class Inspection : Report{
    public:

    // std::string generateReport() const override{}

};


class WeightCheck : public Inspection{
    private:
    static constexpr int MINWEIGHT = 200;
    static constexpr int MAXWEIGHT = 600;

    public:
    WeightCheck(Product v) {}
    std::string generateReport() const override{}



};

class VisualInspection : public Inspection{
    private:
    bool visualInspection;

    public:
    VisualInspection(bool inspectiion) : visualInspection(inspectiion){}
    std::string generateReport() const override{}
};

class TemperatureTest : public Inspection{
    private:
    static constexpr int TEMPMAX = 60;
    static constexpr int TEMPMIN = 80;
    public:
    TemperatureTest()
}
#endif