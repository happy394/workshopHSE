#include "titanic.h"
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

double WEIGHTS[3]{0.5, 0.25, 0.25};

matrix readCsv(const std::string &filePath)
{
    std::ifstream ifile(filePath);

    matrix titanicMatrix;

    if (!ifile)
    {
        std::cout << "File not found.";
        return titanicMatrix;
    }

    std::string line;

    while (std::getline(ifile, line))
    {
        if (line.back() == '\r')
        {
            line.pop_back();
        } // \r removing (it somehow reads it (no clue))

        std::stringstream ss(line);
        std::string element;
        std::vector<std::string> row;

        while (std::getline(ss, element, ';'))
        {
            row.push_back(element);
        }

        if (row.size() < COLUMNS::Embarked + 1)
        {
            row.push_back("");
        }

        titanicMatrix.push_back(row);
    }

    return titanicMatrix;
}

void printMatrix(const matrix &titanicMatrix)
{
    for (const std::vector<std::string> &row : titanicMatrix)
    {
        for (const std::string &element : row)
        {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

double determineValue(short age, short sex, short pclass)
{
    return (1.0 / (age + 1) * WEIGHTS[0] + (1 + sex) / 2.0 * WEIGHTS[1] +
            1.0 / pclass * WEIGHTS[2]);
}

void fillNan(matrix &titanicMatrix, int k)
{
    std::vector<std::string> column;

    for (int i = 1; i < titanicMatrix.size(); i++)
    {
        if (!titanicMatrix[i][k].empty())
        {
            column.push_back(titanicMatrix[i][k]);
        }
    }
    std::sort(column.begin(), column.end());
    std::string median = column[column.size() / 2];
    for (int i = 1; i < titanicMatrix.size(); i++)
    {
        if (titanicMatrix[i][k].empty())
        {
            titanicMatrix[i][k] = median;
        }
    }
}

void addValue(matrix &titanicMatrix)
{
    titanicMatrix[0].push_back("value");

    for (int i = 1; i < titanicMatrix.size(); i++)
    {
        short age = std::stoi(titanicMatrix[i][COLUMNS::Age]),
              sex = (titanicMatrix[i][COLUMNS::Sex] == "female" ? 1 : 0),
              pclass = std::stoi(titanicMatrix[i][COLUMNS::Pclass]);
        titanicMatrix[i].push_back(
            std::to_string(determineValue(age, sex, pclass)));
    }
}

bool Passenger::operator>(const Passenger &right) const
{
    return value > right.value;
}

bool compP(const Passenger &left, const Passenger &right)
{
    return left > right;
}

void Boat::addP(const Passenger &passenger)
{
    seats.push_back(passenger);
}

void Boat::setID(size_t num)
{
    boatID = num;
}

void Boat::printSeats() const
{
    std::cout << "Boat ID: " << boatID + 1 << '\n';
    for (const Passenger &x : seats)
    {
        std::cout << x.id << " " << x.name << " " << x.value << '\n';
    }
    std::cout << "----------------------------------------------------------\n";
}

boatsVector packPassengers(const matrix &titanicMatrix, size_t boats,
                           size_t seats)
{

    std::vector<Passenger> passengers;

    for (size_t i = 1; i < titanicMatrix.size(); i++)
    {
        Passenger passenger{std::stoul(titanicMatrix[i][COLUMNS::PassengerId]),
                            titanicMatrix[i][COLUMNS::Name], titanicMatrix[i][COLUMNS::Sex],
                            std::stoul(titanicMatrix[i][COLUMNS::Age]),
                            std::stoul(titanicMatrix[i][COLUMNS::Pclass]),
                            std::stod(titanicMatrix[i][COLUMNS::Value])};
        passengers.push_back(passenger);
    }

    std::sort(passengers.begin(), passengers.end(), compP);

    boatsVector survived;
    size_t currentInd = 0;
    for (size_t b = 0; b < boats; b++)
    {
        Boat buff;
        buff.setID(b);
        for (size_t s = 0; s < seats; s++)
        {
            buff.addP(passengers[currentInd++]);
        }
        survived.push_back(buff);
    }

    return survived;
}
