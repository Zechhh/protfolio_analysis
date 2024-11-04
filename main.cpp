#include <iostream>
#include "heads/error_handle.hpp"
#include "heads/fetcher.hpp"
#include <fstream>
#include <nlohmann/json.hpp>
#include "heads/company.hpp"




int main(int arc, char*argv[]){
   /* 
    std::string _key = "";
    std::string _symb = "META";
    fetch::Fetcher::alpha_vantage(_key, _symb);
    */

    //system("clear");
    Company comp("TSLA");
    comp.display(30);
 
    comp.gdisplay(30, "Close");

    return 0;
}