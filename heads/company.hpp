#ifndef COMPANY_HPP
#define COMPANY_HPP
#include <string>
#include <vector>
#include <stdexcept>
#include "interpreter.hpp"

class Company{
    public:
        std::string stock_name;
        std::vector<StockData> data;
    public:
        Company(const std::string&);
        ~Company();
        //terminal display
        void display(short int);

        //graph display
        void gdisplay(short int, const std::string&);
};

#endif