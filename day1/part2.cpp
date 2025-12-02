#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>

std::ifstream datafile;

int result = 0;
int position = 50;
bool lastwaszero = false;

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
            int tempid = 0;
            for(int i = 1; i < line.size(); i++) {
                if(isdigit(line[i])) {
                    tempid = tempid * 10 + (line[i] - '0');
                }
                else {
                    continue;
                }
            }
            if(line[0] == 'R') {
               //going right
               //do nothing
            }
            else if(line[0] == 'L') {
                //going left
                tempid = -tempid; 
            }
            else {
                std::cout << "Unknown direction: " << line << "\n";
                continue;
            }
            position += tempid;
            
            if(position < 0) {
                while(position < 0) {
                    position += 100;
                    if(!lastwaszero) {
                        std::cout << "ROTATION\n";
                        result++;
                       
                    }
                    lastwaszero = false;
                }
            }
            if(position >= 100) {
                while(position >= 100) {
                    position -= 100;
                    if(position != 0) {
                        std::cout << "ROTATION\n";
                        result++;
                    }
                    
                }
            }

            
            if(position == 0) {
                std::cout << "IS 0\n";
                result++;
                
            }
            
            lastwaszero = (position == 0);
            std::cout << "Position: " << position << " Result: " << result << " line: " << line << "\n";
            
        }
        datafile.close();
        std::cout << "Result: " << result << "\n";
    }
    return 0;
}