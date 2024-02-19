#ifndef TITANIC_TITANIC_H
#define TITANIC_TITANIC_H

#include <vector>
#include <string>

typedef std::vector<std::vector<std::string>> matrix;
enum COLUMNS
{
    PassengerId,
    Survived,
    Pclass,
    Name,
    Sex,
    Age,
    SibSp,
    Parch,
    Ticket,
    Fare,
    Cabin,
    Embarked
};
matrix readCsv(const std::string &filePath);
void printMatrix(const matrix &titanicMatrix);
double determineValue(short age, short sex, short pclass);
void fillNan(matrix &titanicMatrix, int k);
void addValue(matrix &titanicMatrix);
struct Passenger
{
    size_t id;
    std::string name;
    size_t boats;
    double value;
};
std::vector<Passenger> packPassengers(matrix titanicMatrix, size_t boats, size_t seats);

#endif // TITANIC_TITANIC_H
