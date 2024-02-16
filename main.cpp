#include <iostream>
#include "titanic.h"

std::string FILEPATH = "../data/titanic.csv";

int main(){
    matrix titanicMatrix = readCsv(FILEPATH);
    printMatrix(titanicMatrix);

    return 0;
}

