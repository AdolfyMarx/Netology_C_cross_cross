#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

int main() {
    int num_rows;
    int num_cols;
    std::cin >> num_rows >> num_cols;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string tempalate_string;
    std::getline(std::cin, tempalate_string);

    std::vector<std::vector<int>> input_matrix;
    input_matrix.resize(num_rows, std::vector<int>(num_cols, 0));
    std::string line;
        for (size_t i = 0; i < num_rows; ++i) {
            std::getline(std::cin, line);
            std::istringstream iss(line);
            for (size_t j = 0; j < num_cols; ++j) {
                iss >> input_matrix[i][j];
            }
        }

    std::vector<size_t> star_indices;
    for (size_t i = 0; i < tempalate_string.size(); ++i) {
        if (tempalate_string[i] == '*') {
            star_indices.push_back(i);
        }
    }

    int success_equalty = 0;
    for (size_t i = 0; i < num_rows; ++i) {
        std::string row_replace;
        for (size_t j = 0; j < num_cols; ++j) {
            if (input_matrix[i][j] > 0) {
                row_replace += "+";
            } else if (input_matrix[i][j] < 0) {
                row_replace += "-";
            } else {
                row_replace += ".";
            }
        }
        for (size_t index : star_indices) {
            if (index < row_replace.size()) {
                row_replace[index] = '*';
            }
        }
        if (tempalate_string == row_replace) {
            ++success_equalty;
        }
    }

    if (success_equalty == 0) {
        std::cout << "No lines with mask" << std::endl;
    } else {
        std::cout << success_equalty << std::endl;
    }
    return 0;
}