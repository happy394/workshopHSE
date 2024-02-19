#include <iostream>
#include "titanic.h"

std::string FILEPATH = "../data/titanic.csv";

int main()
{
    matrix titanicMatrix = readCsv(FILEPATH);
    for (int k : {COLUMNS::Age, COLUMNS::Sex, COLUMNS::Pclass})
    {
        fillNan(titanicMatrix, k);
    }
    addValue(titanicMatrix);
    printMatrix(titanicMatrix);
    std::vector<Passenger> survived = packPassengers(titanicMatrix, 10, 10);
    for (const Passenger &x : survived)
    {
        std::cout << x.id << '\t' << x.name << '\t' << x.boats << '\t' << x.value << std::endl;
    }
    return 0;
}