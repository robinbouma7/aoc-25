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
                        continue;
                    }
                }
                if(strlen % 3 == 0) {
                    //split in thirds and compare
                    std::string firstthird = strj.substr(0, strlen / 3);
                    std::string secondthird = strj.substr(strlen / 3, strlen / 3);
                    std::string thirdthird = strj.substr(2 * (strlen / 3), strlen / 3);
                    if(firstthird == secondthird && secondthird == thirdthird) {
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
                        continue;
                    }
                }
                if(strlen % 4 == 0) {
                    //split in quarters and compare
                    std::string firstquarter = strj.substr(0, strlen / 4);
                    std::string secondquarter = strj.substr(strlen / 4, strlen / 4);
                    std::string thirdquarter = strj.substr(2 * (strlen / 4), strlen / 4);
                    std::string fourthquarter = strj.substr(3 * (strlen / 4), strlen / 4);
                    if(firstquarter == secondquarter && secondquarter == thirdquarter && thirdquarter == fourthquarter) {
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
                        continue;
                    }
                }
                if(strlen % 5 == 0) {
                    //split in fifths and compare
                    std::string firstfifth = strj.substr(0, strlen / 5);
                    std::string secondfifth = strj.substr(strlen / 5, strlen / 5);
                    std::string thirdfifth = strj.substr(2 * (strlen / 5), strlen / 5);
                    std::string fourthfifth = strj.substr(3 * (strlen / 5), strlen / 5);
                    std::string fifthfifth = strj.substr(4 * (strlen / 5), strlen / 5);
                    if(firstfifth == secondfifth && secondfifth == thirdfifth && thirdfifth == fourthfifth && fourthfifth == fifthfifth) {
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
                        continue;
                    }
                }
                if(strlen % 6 == 0) {
                    //split in sixths and compare
                    std::string firstsixth = strj.substr(0, strlen / 6);
                    std::string secondsixth = strj.substr(strlen / 6, strlen / 6);
                    std::string thirdsixth = strj.substr(2 * (strlen / 6), strlen / 6);
                    std::string fourthsixth = strj.substr(3 * (strlen / 6), strlen / 6);
                    std::string fifthsixth = strj.substr(4 * (strlen / 6), strlen / 6);
                    std::string sixthsixth = strj.substr(5 * (strlen / 6), strlen / 6);
                    if(firstsixth == secondsixth && secondsixth == thirdsixth && thirdsixth == fourthsixth && fourthsixth == fifthsixth && fifthsixth == sixthsixth) {
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
                        continue;
                    }
                }
                if(strlen % 7 == 0) {
                    //split in sevenths and compare
                    std::string firstseventh = strj.substr(0, strlen / 7);
                    std::string secondseventh = strj.substr(strlen / 7, strlen / 7);
                    std::string thirdseventh = strj.substr(2 * (strlen / 7), strlen / 7);
                    std::string fourthseventh = strj.substr(3 * (strlen / 7), strlen / 7);
                    std::string fifthseventh = strj.substr(4 * (strlen / 7), strlen / 7);
                    std::string sixthseventh = strj.substr(5 * (strlen / 7), strlen / 7);
                    std::string seventhseventh = strj.substr(6 * (strlen / 7), strlen / 7);
                    if(firstseventh == secondseventh && secondseventh == thirdseventh && thirdseventh == fourthseventh && fourthseventh == fifthseventh && fifthseventh == sixthseventh && sixthseventh == seventhseventh) {
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
                        continue;
                    }
                }
                if(strlen % 8 == 0) {
                    //split in eighths and compare
                    std::string firsteighth = strj.substr(0, strlen / 8);
                    std::string secondeighth = strj.substr(strlen / 8, strlen / 8);
                    std::string thirdeighth = strj.substr(2 * (strlen / 8), strlen / 8);
                    std::string fourtheighth = strj.substr(3 * (strlen / 8), strlen / 8);
                    std::string fiftheighth = strj.substr(4 * (strlen / 8), strlen / 8);
                    std::string sixtheighth = strj.substr(5 * (strlen / 8), strlen / 8);
                    std::string seventheighth = strj.substr(6 * (strlen / 8), strlen / 8);
                    std::string eighteighth = strj.substr(7 * (strlen / 8), strlen / 8);
                    if(firsteighth == secondeighth && secondeighth == thirdeighth && thirdeighth == fourtheighth && fourtheighth == fiftheighth && fiftheighth == sixtheighth && sixtheighth == seventheighth && seventheighth == eighteighth) {
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
                        continue;
                    }
                }
                if(strlen % 9 == 0) {
                    //split in ninths and compare
                    std::string firstninth = strj.substr(0, strlen / 9);
                    std::string secondninth = strj.substr(strlen / 9, strlen / 9);
                    std::string thirdninth = strj.substr(2 * (strlen / 9), strlen / 9);
                    std::string fourthninth = strj.substr(3 * (strlen / 9), strlen / 9);
                    std::string fifthninth = strj.substr(4 * (strlen / 9), strlen / 9);
                    std::string sixthninth = strj.substr(5 * (strlen / 9), strlen / 9);
                    std::string seventhninth = strj.substr(6 * (strlen / 9), strlen / 9);
                    std::string eighthninth = strj.substr(7 * (strlen / 9), strlen / 9);
                    std::string ninthninth = strj.substr(8 * (strlen / 9), strlen / 9);
                    if(firstninth == secondninth && secondninth == thirdninth && thirdninth == fourthninth && fourthninth == fifthninth && fifthninth == sixthninth && sixthninth == seventhninth && seventhninth == eighthninth && eighthninth == ninthninth) {
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
                        continue;
                    }
                }
                if(strlen % 10 == 0) {
                    //split in tenths and compare
                    std::string firsttenth = strj.substr(0, strlen / 10);
                    std::string secondtenth = strj.substr(strlen / 10, strlen / 10);
                    std::string thirdtenth = strj.substr(2 * (strlen / 10), strlen / 10);
                    std::string fourthtenth = strj.substr(3 * (strlen / 10), strlen / 10);
                    std::string fifthtenth = strj.substr(4 * (strlen / 10), strlen / 10);
                    std::string sixthtenth = strj.substr(5 * (strlen / 10), strlen / 10);
                    std::string seventhtenth = strj.substr(6 * (strlen / 10), strlen / 10);
                    std::string eighttenth = strj.substr(7 * (strlen / 10), strlen / 10);
                    std::string ninthtenth = strj.substr(8 * (strlen / 10), strlen / 10);
                    std::string tenthtenth = strj.substr(9 * (strlen / 10), strlen / 10);
                    if(firsttenth == secondtenth && secondtenth == thirdtenth && thirdtenth == fourthtenth && fourthtenth == fifthtenth && fifthtenth == sixthtenth && sixthtenth == seventhtenth && seventhtenth == eighttenth && eighttenth == ninthtenth && ninthtenth == tenthtenth) {
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
                        continue;
                    }
                }
            }
        }
        //not proud but it works.
        //thanks github copilot from saving me the effort of writing all those if statements manually.
        std::cout << "\nRESULT: " << result << "\n";
    }
    return 0;
}