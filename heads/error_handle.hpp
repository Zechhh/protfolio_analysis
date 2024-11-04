#ifndef ERROR_HANDLE_HPP
#define ERROR_HANDLE_HPP
#include <cstdlib> 
#include <string>
#include <iostream>
namespace handle{
    class Checker{
        public:
        /*
        Check if python3 is installed
        Usage: Alpha vantage fetch
        */
        static bool dpython3();
       /*
       Check if json file downloaded correctly
       */
       //for alpha vantage
        static bool av_json(std::string&, std::string&);
    };
}

#endif