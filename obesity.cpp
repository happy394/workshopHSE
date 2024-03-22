#include "obesity.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

enum CELLNUM{
    Gender,
    Age,
    Weight = 3
};

Person::Person(int age, const std::string& sex, double weight): age(age), sex(sex), weight(weight) {
}

Person Person::operator+(const Person &right) const{
    return Person{this->age, this->sex, this->weight + right.weight};
}

GenderMap readcsv(const std::string& filePath){
    std::ifstream ifile(filePath);

    GenderMap genderMap;
    std::vector<Person> buff;

    if (!ifile)
        throw std::runtime_error("File not found.");

    std::string line, header;

    std::getline(ifile, header);

    while (std::getline(ifile, line)){
        //getline works with stream
        std::stringstream ss(line);

        std::string cell;
        double w;
        std::string s;
        int a;

        for (int i = 0; i <= 3; i++){
            std::getline(ss, cell, ',');

            switch(i){
                case CELLNUM::Gender:
                    s = cell;
                    break;
                case CELLNUM::Age:
                    a = std::stoi(cell);
                    break;
                case CELLNUM::Weight:
                    w = std::stod(cell);
                    break;
                default:
                    continue;
            }

        }

        buff.push_back(Person(a, s, w));

    }
    for (const std::string& sex: {"Male", "Female"}){
        AgeWeight ages;
        for (int age = 0; age <= 100; age++){
            std::vector<Person> buff2;
            std::copy_if(buff.begin(), buff.end(),
                         std::back_inserter(buff2),
                         [sex, age](const Person& alone){
                             return sex == alone.sex && age == alone.age;
                         });
            if (!buff2.empty()) {
                double mean = std::reduce(buff2.begin(),
                                          buff2.end(),
                                          Person(0, "female", 0)).weight / buff2.size();
                ages.insert(std::pair<int, double>(age, mean));
            }
        }
        genderMap.insert({sex, ages});
    }
    return genderMap;
}

//no auto (for Pavel)
void printGenderMap(const GenderMap& genderMap){
    for (const std::pair<std::string, std::map<int, double>> &personInfo : genderMap){
        std::cout << personInfo.first << ":\n";
        for (const std::pair<int, double> &ageInfo: personInfo.second){
            std::cout << "Age: " << ageInfo.first << "Weight: " << ageInfo.second << std::endl;
        }
    }
}

