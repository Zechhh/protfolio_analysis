#include "heads/interpreter.hpp"


std::vector<StockData> Parse::Json::js_invoke(const std::string& file_name){
    std::ifstream file("fetched_data/"+file_name+".json");
    if(!(file.is_open())){ 
        std::cerr<<"Cannot locate data for given name"<<std::endl;
        return {};
    }
    std::vector<StockData> v;
    v.reserve(102);
    nlohmann::json jData;
    file >> jData;
    auto timeSeries = jData["Time Series (Daily)"];

    std::string k = "-1";
    StockData buffor;
    for(auto it = timeSeries.begin(); it!=timeSeries.end(); ++it){
        k = it.key();
        try{
        buffor.date = k;
        const nlohmann::json& Info = it.value();
        buffor.open = std::stod(Info.at("1. open").get<std::string>());
        buffor.high = std::stod(Info.at("2. high").get<std::string>());
        buffor.low = std::stod(Info.at("3. low").get<std::string>());
        buffor.close = std::stod(Info.at("4. close").get<std::string>());
        buffor.volume = std::stod(Info.at("5. volume").get<std::string>());
        }catch(const std::exception& e){
            std::cerr<<"Failure loading chunck of data <"<<k<<">"<<std::endl;
            continue;
        }
        v.emplace_back(buffor);
    }
    file.close();
    std::reverse(v.begin(), v.end());
    return v;
}