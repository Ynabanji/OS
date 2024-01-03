#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void create_report(const std::string& reporter_file_name,const std::string& bin_file_name, double hourly_rate){
    std::ifstream bin_in(bin_file_name);
    std::ofstream report(reporter_file_name);
    report << "Отчет по файлу " << bin_file_name << "\n";
    int num;
    int num_checker;
    char name[10];
    double hours;
    bin_in.read((char*) &num,sizeof(num));
    bin_in.read(name,sizeof(name));
    bin_in.read((char*) &hours,sizeof(hours));
    report << num <<"\t" << name << "\t"<< hours<< "\t" << hours * hourly_rate << "\n";
    while(!bin_in.eof()){
        num_checker = num;
        bin_in.read((char*) &num,sizeof(num));
        bin_in.read(name,sizeof(name));
        bin_in.read((char*) &hours,sizeof(hours));
        if(num == num_checker){
            break;
        }
        else{
        report << num <<"\t" << name << "\t"<< hours<< "\t" << hours * hourly_rate << "\n";}
    }
}

int main(int argc, char *argv[]) {
    double hourly_rate = std::stod(argv[1]);
    std::string reporter_file_name = argv[2];
    std::string bin_file_name = argv[3];

    create_report(reporter_file_name,bin_file_name,hourly_rate);



    return 0;
}
