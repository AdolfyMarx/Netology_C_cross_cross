#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>


int main() {
    std::string date_str;
    std::getline(std::cin, date_str);

    int num_days;
    std::cin >> num_days;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string cost_str;
    std::getline(std::cin, cost_str);

    std::vector<double> cost_vect;
    std::stringstream ss(cost_str);
    double day_cost;
    while (ss >> day_cost) {
        cost_vect.push_back(day_cost);
    }

    tm start_date = {};
    std::istringstream ss_str(date_str);
    ss_str >> std::get_time(&start_date, "%d %m %Y");

    time_t start_date_tt = mktime(&start_date);
    auto start_date_sc = std::chrono::system_clock::from_time_t(start_date_tt);

    double max_cost = std::numeric_limits<double>::lowest();
    int max_cost_pos = -1;
    for (int i = 0; i < cost_vect.size(); ++i) {
        if (cost_vect[i] > max_cost) {
            max_cost = cost_vect[i];
            max_cost_pos = i;
        }
    }
    int days_grow = 0;
    for (int i = max_cost_pos; i >= 0; --i) {
        if (i > 0 && cost_vect[i] <= cost_vect[i - 1]) {
            break;
        }
        ++days_grow;
    }

    auto new_date = std::chrono::time_point_cast<std::chrono::days>(start_date_sc) + std::chrono::days(max_cost_pos + 1);
    auto shifted_t_point = std::chrono::time_point_cast<std::chrono::seconds>(new_date);
    time_t new_tt = std::chrono::system_clock::to_time_t(shifted_t_point);
    tm result_date = *localtime(&new_tt);

    std::ostringstream oss;
    oss << std::put_time(&result_date, "%d.%m.%Y");

    std::string result_string = oss.str() + " " + std::to_string(days_grow);
    std::cout << result_string << std::endl;
    return 0;
}