#include <iostream>
#include <cmath>

int main() {
    double speed1, acc1, speed2, acc2, range;
    std::cout << "Введите значения переменных через пробел";
    std::cin >> speed1 >> acc1 >> speed2 >> acc2 >> range;

    int meetingTime;
    if (acc1 == 0 && acc2 == 0) {
        if (speed1 + speed2 != 0) {
            meetingTime = static_cast<int>(range / (speed1 + speed2));
        } else {
            meetingTime = 0;
        }
    } else {
        double discr = (speed1 + speed2) * (speed1 + speed2) - 2 * (acc1 + acc2) * (- range);
        if (discr < 0) {
            meetingTime = 0;
        } else {
             double resultTime = (- (speed1 + speed2) + sqrt(discr)) / (acc1 + acc2);
            // meetingTime = static_cast<int>(std::floor(resultTime));
            meetingTime = resultTime;
        }
    }
    std::cout << meetingTime;
    return meetingTime;
}