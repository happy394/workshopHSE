#ifndef TITANIC_TITANIC_H
#define TITANIC_TITANIC_H

#include <vector>
#include <string>

typedef std::vector <std::vector <std::string>> matrix;

matrix readCsv(const std::string& filePath);
void printMatrix(const matrix& titanicMatrix);
double determineValue(short age, short sex, short pclass);

#endif //TITANIC_TITANIC_H
