#ifndef TITANIC_TITANIC_H
#define TITANIC_TITANIC_H

#include "obesity.h"
#include <vector>
#include <string>

//extern double WEIGHTS[3]{0.5, 0.25, 0.25};

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
    Embarked,
    Value
};
struct Passenger {public:
    size_t id;
    std::string name;
    std::string sex;
    size_t age;
    size_t pclass;
    double value;
    double weight;
    bool operator >(const Passenger &right) const;
};
class Boat {
public:
    void addP(const Passenger&);
    void setID(size_t);
    void printSeats()const;
private:
    std::vector<Passenger> seats;
    size_t boatID;
};

std::vector<Passenger> fillPassengers(const matrix&);
typedef std::vector<Boat> boatsVector;

matrix readCsv(const std::string &filePath);
void printMatrix(const matrix &titanicMatrix);
double determineValue(short age, short sex, short pclass);
void fillNan(matrix &titanicMatrix, int k);
void addValue(matrix &titanicMatrix);
boatsVector packPassengers(const matrix& titanicMatrix, size_t boats, size_t seats);
std::vector<Passenger> fillPassengers(const matrix& titanicMatrix, const GenderMap& gendermap);

#endif // TITANIC_TITANIC_H
