#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <array>

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
        line.pop_back(); // \r removing (it somehow reads it (no clue))
        std::stringstream ss(line);
        std::string element;
        std::vector<std::string> row;

        while (std::getline(ss, element, ';'))
        {
            row.push_back(element);
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

double WEIGHTS[3]{0.5, 0.25, 0.25};
double determineValue(short age, short sex, short pclass)
{
    return (1.0 / (age + 1) * WEIGHTS[0] + (1 + sex) / 2.0 * WEIGHTS[1] + 1.0 / pclass * WEIGHTS[2]);
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
        titanicMatrix[i].push_back(std::to_string(determineValue(age, sex, pclass)));
    }
}
struct Passenger
{
    size_t id;
    std::string name;
    size_t boats;
    double value;
};
std::vector<Passenger> packPassengers(matrix titanicMatrix, size_t boats, size_t seats)
{
    std::sort(titanicMatrix.begin() + 1, titanicMatrix.end(), [](const std::vector<std::string> &left, const std::vector<std::string> &right)
              { return left[COLUMNS::Value] > right[COLUMNS::Value]; });
    std::vector<Passenger> survived;
    for (size_t i = 1; i <= boats * seats; i++)
    {
        Passenger passenger{std::stoul(titanicMatrix[i][COLUMNS::PassengerId]), titanicMatrix[i][COLUMNS::Name],
                            i / seats + 1, std::stod(titanicMatrix[i][COLUMNS::Value])};
        // passenger.id = std::stoi(titanicMatrix[i][COLUMNS::PassengerId]);
        // passenger.name =titanicMatrix[i][COLUMNS::Name];
        survived.push_back(passenger);
    }
    return survived;
}
