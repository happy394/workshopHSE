#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

typedef std::vector <std::vector <std::string>> matrix;

matrix readCsv(const std::string& filePath){
    std::ifstream ifile(filePath);

    matrix titanicMatrix;

    if (!ifile) {
        std::cout << "File not found.";
        return titanicMatrix;
    }

    std::string line;

    while (std::getline(ifile, line)){
        line.pop_back(); // \r removing (it somehow reads it (no clue))
        std::stringstream ss(line);
        std::string element;
        std::vector <std::string> row;

        while (std::getline(ss, element, ';')){
            row.push_back(element);
        }

        titanicMatrix.push_back(row);
    }

    return titanicMatrix;
}

void printMatrix(const matrix& titanicMatrix){
    for (const std::vector <std::string>& row: titanicMatrix){
        for (const std::string& element: row){
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }
}

double WEIGHTS[3]{0.5, 0.25, 0.25};
double determineValue(short age, short sex, short pclass){
    return (1/(age + 1) * WEIGHTS[0] + (1 + sex)/2 * WEIGHTS[1] + 1/pclass * WEIGHTS[2]);
}

// age = 2 -> sex = 1 -> Pclass = 1;

// 1/age