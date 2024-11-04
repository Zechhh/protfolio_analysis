#include <iostream>
#include "heads/error_handle.hpp"
#include "heads/fetcher.hpp"
//#include <fstream>
#include <nlohmann/json.hpp>
#include "heads/company.hpp"




int main(int arc, char*argv[]){
  
    //std::string _key = "TYQSXGHX6RXBGUY1";
    //std::string _symb = "HAHAXYZ";
    //fetch::Fetcher::alpha_vantage(_key, _symb);
    
    system("clear");
    Company comp("HAHAXYZ");
    comp.display(35);
    comp.gdisplay(30, "Close");
    return 0;
}