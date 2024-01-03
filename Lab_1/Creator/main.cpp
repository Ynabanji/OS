#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
class Name_exception {

};

void full_bin_from_console(std::ofstream & bin_out,int amount) {
    int num;
    char name[10];
    double hours;
    for(int i = 0; i < amount; i++) {
        std::cin >> num;
        try {
            std::cin >> name;
        } catch (Name_exception e) {
            std::cout << "bad_name_error";
            exit(1);
        }
        std::cin >> hours;

        bin_out.write((char*)& num,sizeof(num));
        bin_out.write(name,sizeof(name));
        bin_out.write((char*) &hours,sizeof(hours));
    }
}

int main( int argc, char *argv[]) {
    int amount = atoi(argv[1]);
    std::string name = argv[2];
    std::ofstream bin_out(name);
    full_bin_from_console(bin_out,amount);



    return 0;
}
