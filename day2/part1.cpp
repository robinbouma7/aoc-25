#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <array>
#include <cstdint>

std::ifstream datafile;
std::vector<std::array<int64_t, 2>> values;

int64_t result = 0;

int main(int argc, char *argv[]) {
    if(argc > 1 && (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "--test") == 0)) {
        std::cout << "TEST DATA\n\n";
        datafile.open("testdata.txt");
    }
    else {
        datafile.open("data.txt");
    }

    if (datafile.is_open()) {
        while(datafile.good() ) {
            std::string line;
            getline(datafile, line);
            int64_t tempint = 0;
            std::array<int64_t, 2> tempvalues = {-1, -1};
            for(int i = 0; i < line.size(); i++) {
                //process line here
                if(isdigit(line[i])) {
                    tempint = tempint * 10 + (line[i] - '0');
                }
                else if(line[i] == '-'){
                    //first value
                    tempvalues[0] = tempint;
                    tempint = 0;
                }
                else if(line[i] == ',') {
                    //second value
                    tempvalues[1] = tempint;
                    tempint = 0;
                    values.push_back(tempvalues);
                    tempvalues[0] = -1;
                    tempvalues[1] = -1;
                }
                
            }
            tempvalues[1] = tempint;
            values.push_back(tempvalues);
        }
        datafile.close();
        std::cout << "DATA LOADED\n";
        //process values here
        int64_t oldresult = result;
        for(int i = 0; i < values.size(); i++) {
            std::cout << "Processing range: " << values[i][0] << " to " << values[i][1] << "\n";
            for(int64_t j = values[i][0]; j <= values[i][1]; j++) {
                std::string strj = std::to_string(j);
                int strlen = strj.length();
                if(strlen % 2 == 0) {
                   //split in half and compare
                   std::string firsthalf = strj.substr(0, strlen / 2);
                   std::string secondhalf = strj.substr(strlen / 2, strlen / 2);
                    if(firsthalf == secondhalf) {
                        //std::cout << "MATCH: " << strj << "\n";
                        result += j;
                        if(j <= 0) {
                            std::cout << "\nNEGATIVE NUMBER DETECTED: " << j << "\n";
                        }
                        if(result < oldresult) {
                            std::cout << "\nOVERFLOW DETECTED\n";
                            std::cout << "result: " << result << "\n";
                            std::cout << "oldresult: " << oldresult << "\n";
                        }
                        oldresult = result;
                    }
                }
            }
        }
        std::cout << "\nRESULT: " << result << "\n";
    }
    return 0;
}