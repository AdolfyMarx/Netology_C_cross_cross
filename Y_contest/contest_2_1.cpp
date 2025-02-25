#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n_days;
    std::istream & input = std::cin;
    input >> n_days;
    int m_len = n_days * 2;
    std::vector <int> temp_m(m_len);
    std::vector <int> temp_delta_m(0);
    std::vector <int> temp_day_m(0);

    if (n_days != 0) {
        for (int i = 0; i < m_len; i++) {
            input >> temp_m[i];
        }
    } else {
        std::cout << "the number of days is set to 0";
        return 0;
    }
        
    if (temp_m.size() != 0) {
        for (size_t i = 0; i < temp_m.size() - 1; i += 2) {
            temp_delta_m.push_back(temp_m[i] - temp_m[i + 1]);
            if (temp_m[i] > 0) {
                temp_day_m.push_back(temp_m[i]);
            }
        }

        auto min_delta_t = std::min_element(std::begin(temp_delta_m), std::end(temp_delta_m));
        int min_delta_t_day = std::distance(std::begin(temp_delta_m), min_delta_t) + 1;
        
        int warm_day_flag = 0;

        for (int day : temp_day_m) {
            if (day > 0) {
                warm_day_flag += 1;
            }
        }
        if (warm_day_flag == 0) {
            std::cout << min_delta_t_day << std::endl;

            std::cout << "No positive data" << std::endl;
            return 0;
        } else if (warm_day_flag == n_days) {
            std::cout << min_delta_t_day << std::endl;
            std::cout << "All data are positive" << std::endl;
            return 0;
        } else {
            std::cout << min_delta_t_day << std::endl;
            for (int value : temp_day_m) {
                std::cout << value << " ";
            }
            return 0;
        }
        
    } else {
        std::cout << "the length of the temperature vector is 0";
        return 0;
    }
    
    return 0;
 }