#include "heads/company.hpp"

Company::Company(const std::string& stock_symbol){
    this->stock_name= stock_symbol;
    this->data = Parse::Json::js_invoke(stock_symbol);
}

Company::~Company(){}

void Company::display(short int n){
    if(n < 0 || n > this->data.size())
        n=this->data.size();
    for(int i = 0; i<n; i++){
        std::cout<< std::left << std::setw(6) <<"Date: "<<this->data[i].date
        << std::setw(9) <<", High: "<<std::fixed << std::setprecision(2) <<this->data[i].high
        << std::setw(8) <<", Low: "<<std::fixed << std::setprecision(2)<< this->data[i].low
        << std::setw(9) <<", Open: "<<std::fixed << std::setprecision(2)<<this->data[i].open
        << std::setw(9) <<", Close: "<<std::fixed << std::setprecision(2)<<this->data[i].close
        << std::setw(9) <<", Vol. :"<<std::fixed << std::setprecision(2)<<this->data[i].volume
        <<std::endl;
    }
}


void Company::gdisplay(short int n, const std::string& select_){
    n = (n < 0 || n > this->data.size()) ? this->data.size() : 0;
    FILE* gnuplotPipe = popen("gnuplot -p", "w");
    if(!gnuplotPipe){
        throw std::runtime_error("Cannot open gnuplot pipe.");
    }
    std::string * title = new std::string;
    *title = "set title '" +this->stock_name + " " + select_ + " Prices Over Time'\n";
    fprintf(gnuplotPipe, title->c_str());
    delete title;
    fprintf(gnuplotPipe, "set xdata time\n");
    fprintf(gnuplotPipe, "set timefmt '%%Y-%%m-%%d'\n");
    fprintf(gnuplotPipe, "set format x '%%Y-%%m-%%d'\n");
    fprintf(gnuplotPipe, "set xlabel 'Date'\n");
    fprintf(gnuplotPipe, "set ylabel 'Price'\n");
    fprintf(gnuplotPipe, "plot '-' using 1:2 with lines title 'Price'\n");
   // printf(">SIZE %i\n", this->data.size());
    float buffor;
    for (size_t i = this->data.size(); i > 0; --i) {
        if(select_ == "Open"){
            fprintf(gnuplotPipe, "%s %f\n", this->data[i-1].date.c_str(), this->data[i-1].open);
        }else if(select_ == "High"){
            fprintf(gnuplotPipe, "%s %f\n", this->data[i-1].date.c_str(), this->data[i-1].high);
        }else if(select_=="Low"){
            fprintf(gnuplotPipe, "%s %f\n", this->data[i-1].date.c_str(), this->data[i-1].low);
        }else if(select_ == "Close"){
            fprintf(gnuplotPipe, "%s %f\n", this->data[i-1].date.c_str(), this->data[i-1].close);
        }else{
            throw std::runtime_error("Invalid graph selection");
        }
        
    }
    fprintf(gnuplotPipe, "e\n");
    pclose(gnuplotPipe);
}