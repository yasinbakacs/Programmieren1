#ifndef REPORT_HPP
#define REPORT_HPP

#include <iostream>
#include <string>


class Report{
    public:

    virtual std::string generateReport() const{}

    ~Report(){}
};
#endif