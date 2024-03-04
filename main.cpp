#include <iostream>
#include "titanic.h"
#include "obesity.h"

std::string FILEPATH = "../data/titanic.csv";
std::string FILEPATH2 = "../data/obesity.csv";

int main()
{
//    matrix titanicMatrix = readCsv(FILEPATH);
//    for (int k : {COLUMNS::Age, COLUMNS::Sex, COLUMNS::Pclass})
//    {
//        fillNan(titanicMatrix, k);
//    }
//    addValue(titanicMatrix);
////    printMatrix(titanicMatrix);
//    boatsVector survived = packPassengers(titanicMatrix, 10, 10);
//    //Passenger changed:
//    for (const Boat &x : survived)
//    {
//        x.printSeats();
//    }
    printGenderMap(readcsv(FILEPATH2));
    return 0;
}