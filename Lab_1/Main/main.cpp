#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void run_creator(const std::string& executable_path, int amount, const std::string& name) {
    std::string command ="./" + executable_path + " " + std::to_string(amount) + " " +name;
    std::system(command.c_str());
}
void run_reporter(const std::string& executable_path, int hourly_rate, const std::string& reporter_name,const std::string& bin_name) {
    std::string command ="./" + executable_path + " " + std::to_string(hourly_rate) + " " +reporter_name+" "+bin_name;
    std::system(command.c_str());
}

void show_bin_content(std::string &file_name, int amount) {
    std::ifstream bin_in(file_name);
    int num;
    char name[10];
    double hours;
    for(int i = 0; i < amount; i++) {
        bin_in.read((char*) &num,sizeof(num));
        bin_in.read(name,sizeof(name));
        bin_in.read((char*) &hours,sizeof(hours));
        std::cout << num << "    " << name << "    " << hours <<"\n";
    }
}

void show_report(const std::string& report_file_name,int records_amount){
    std::ifstream in(report_file_name);
    std::string str;
    for(int i = 0; i <= records_amount;i++) {
        std::getline(in, str);
        std::cout << str <<"\n";
    }
}

int main() {
    std::cout << "File name: " << "\n";
    std::string name;
    std::cin >> name;

    std::cout << "Records amount: " << "\n";
    int records_amount;
    std::cin>> records_amount;
    std::string exec_path_creator ="Creator_to_1_lab";
    std::thread creator(run_creator, exec_path_creator,records_amount,name);
    creator.join();

    show_bin_content(name,records_amount);

    std::string report_file_name;
    std::string exec_path_reporter;
    double hourly_rate;
    std::cout<<"Report file name: ";
    std::cin >> report_file_name;
    std::cout<<"hourly rate: ";
    std::cin >> hourly_rate;
    exec_path_reporter = "Reporter_to_lab_1";

    std::thread reporter(run_reporter,exec_path_reporter,hourly_rate,report_file_name,name);
    reporter.join();

    show_report(report_file_name,records_amount);


    return 0;
}
