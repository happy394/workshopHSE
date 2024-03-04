#ifndef INC_3KONTEST_OBESITY_H
#define INC_3KONTEST_OBESITY_H

#include <string>
#include <map>
#include <unordered_map>

// unordered_map - hash table in cpp
using GenderMap = std::unordered_map<std::string, std::map <int, double>>;
typedef std::map<int, double> AgeWeight;

struct Person{
    Person(int, const std::string&, double);
    Person operator+(const Person&) const;

    int age;
    std::string sex;
    double weight;
};

GenderMap readcsv(const std::string&);
void printGenderMap(const GenderMap&);


#endif //INC_3KONTEST_OBESITY_H
