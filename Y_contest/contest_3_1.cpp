#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    int num_students;
    std::cin >> num_students;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string students_str;
    std::getline(std::cin, students_str);

    std::vector<int> students_vect;
    std::stringstream ss(students_str);
    int student;
    while (ss >> student) {
        students_vect.push_back(student);
    }

    std::vector<int> top_students_vect;
    std::copy_if(students_vect.begin(), students_vect.end(), std::back_inserter(top_students_vect),
                 [](int value) { return value >= 90; });

    std::sort(top_students_vect.begin(), top_students_vect.end(), std::greater<int>());

    std::vector<int> bottom_students_vect;
    std::copy_if(students_vect.begin(), students_vect.end(), std::back_inserter(bottom_students_vect),
                 [](int value) { return value < 60; });    

    if (top_students_vect.size() == 0 || bottom_students_vect.size() == 0) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }

    if (bottom_students_vect.size() == 1) {
        top_students_vect.resize(1);
    } else if (bottom_students_vect.size() == 2) {
        top_students_vect.resize(2);
    } else {
        top_students_vect.resize(3);
    }
    
    int group_size = bottom_students_vect.size() / top_students_vect.size();
    int remainder_students = bottom_students_vect.size() % top_students_vect.size();

    if (top_students_vect.size() == 1) {
        top_students_vect.insert(top_students_vect.end(), bottom_students_vect.begin(), bottom_students_vect.end());
        for (int value : top_students_vect) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    } else if (top_students_vect.size() == 2) {
        std::vector<int> group_1 = {top_students_vect[0]};
        std::vector<int> group_2 = {top_students_vect[1]};
        if (remainder_students == 1) {
            group_1.insert(group_1.end(), bottom_students_vect.begin(), bottom_students_vect.begin() + group_size + 1);
            group_2.insert(group_2.end(), bottom_students_vect.begin() + group_size + 1, bottom_students_vect.end());
        } else {
            group_1.insert(group_1.end(), bottom_students_vect.begin(), bottom_students_vect.begin() + group_size);
            group_2.insert(group_2.end(), bottom_students_vect.begin() + group_size, bottom_students_vect.end());
        }
        for (int value_1 : group_1) {
            std::cout << value_1 << " ";
        }
        std::cout << std::endl;
        for (int value_2 : group_2) {
            std::cout << value_2 << " ";
        }
        std::cout << std::endl;
        
    } else {
        std::vector<int> group_1 = {top_students_vect[0]};
        std::vector<int> group_2 = {top_students_vect[1]};
        std::vector<int> group_3 = {top_students_vect[2]};
        if (remainder_students == 2) {
            group_1.insert(group_1.end(), bottom_students_vect.begin(), bottom_students_vect.begin() + group_size + 1);
            group_2.insert(group_2.end(), bottom_students_vect.begin() + group_size + 1, bottom_students_vect.begin() + 2 * group_size + 2);
            group_3.insert(group_3.end(), bottom_students_vect.begin() + 2 * group_size + 2, bottom_students_vect.end());
        } else if (remainder_students == 1) {
            group_1.insert(group_1.end(), bottom_students_vect.begin(), bottom_students_vect.begin() + group_size + 1);
            group_2.insert(group_2.end(), bottom_students_vect.begin() + group_size + 1, bottom_students_vect.begin() + 2 * group_size + 1);
            group_3.insert(group_3.end(), bottom_students_vect.begin() + 2 * group_size + 1, bottom_students_vect.end());
        } else {
            group_1.insert(group_1.end(), bottom_students_vect.begin(), bottom_students_vect.begin() + group_size);
            group_2.insert(group_2.end(), bottom_students_vect.begin() + group_size, bottom_students_vect.begin() + 2 * group_size);
            group_3.insert(group_3.end(), bottom_students_vect.begin() + 2 * group_size, bottom_students_vect.end());
        }
        for (int value_1 : group_1) {
            std::cout << value_1 << " ";
        }
        std::cout << std::endl;
        for (int value_2 : group_2) {
            std::cout << value_2 << " ";
        }
        std::cout << std::endl;
        for (int value_3 : group_3) {
            std::cout << value_3 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
