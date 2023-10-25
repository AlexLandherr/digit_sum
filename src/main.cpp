#include "include/functions.h"
#include <iostream>

/*
2^15 = 32768 and the sum of the digits is 3+2+7+6+8 = 26.
What is the sum of the digits of the number 2^1000?
*/

int main() {
    //std::cout << func::add_num_str("123", "99") << '\n';
    std::cout << "The sum of the digits of the number 2^1000 is:" << '\n';
    std::cout << func::digit_sum(1000) << '\n';

    return 0;
}