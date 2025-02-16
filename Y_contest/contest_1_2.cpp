#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>

int main() {
    int number_X10;
    std::cin >> number_X10;

    std::stringstream str_stream;
    str_stream << std::hex << number_X10;
    std::string str_hex = str_stream.str();
    char max_char = *std::max_element(str_hex.begin(), str_hex.end());

    if (max_char >= '0'&& max_char <= '9') {
        number_X10 = number_X10 * 2;
    } else if ((max_char) == 'a' || max_char == 'd') {
        if (str_hex.length() > 1) {
            number_X10 /= 10;
            // str_hex.pop_back();
        } else {
            number_X10 = 0;
        }
        // number_X10 = std::stoi(str_hex, nullptr, 16);
    } else if (max_char == 'b' || max_char == 'c') {
        std::string number_string = std::to_string(number_X10);
        if (number_X10 > 9) {
            char f_char = number_string.front();
            char l_char = number_string.back();
            number_string[0] = l_char;
            number_string[number_string.length() - 1] = f_char;
            number_X10 = std::stoi(number_string);
        }
        // char f_char = str_hex.front();
        // char l_char = str_hex.back();
        // str_hex[0] = l_char;
        // str_hex[str_hex.length() - 1] = f_char;
        // number_X10 = std::stoi(str_hex, nullptr, 16);
    } else if (max_char == 'e') {
        number_X10 = number_X10 + 1;
    } else if (max_char == 'f') {
        int result_sum = 0;
        int source_num = number_X10;
        while (source_num > 0) {
            result_sum += source_num % 10;
            source_num /= 10;
        }
        number_X10 += result_sum;
    }
    std::cout << number_X10;
    return 0;
}