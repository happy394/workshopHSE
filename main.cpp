#include <iostream>
#include "titanic.h"

std::string FILEPATH = "../data/titanic.csv";

int main(){
    matrix titanicMatrix = readCsv(FILEPATH);
//    printMatrix(titanicMatrix);
    std::cout << determineValue(0, 1, 1);


    return 0;
}

