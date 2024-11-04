#include "heads/error_handle.hpp"


bool handle::Checker::dpython3(){
    return !(system("python3 --version > /dev/null 2>&1"));
}

bool handle::Checker::av_json(std::string& stock_name, std::string& path_){

    return false;
}