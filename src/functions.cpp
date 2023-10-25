#include "include/functions.h"
#include <string>
#include <iostream>
#include <cstdint>

namespace func {
    std::string add_num_str(std::string str1, std::string str2) {
        std::string result;
        //Making sure number strings are equally long.
        if (str1.length() > str2.length()) {
            str2.insert(0, (str1.length() - str2.length()), '0');
        } else if (str2.length() > str1.length()) {
            str1.insert(0, (str2.length() - str1.length()), '0');
        }

        //Adding number strings together, one digit at a time from right to left.
        int carry = 0;
        for (int i = static_cast<int>(str1.length()) - 1; i >= 0; i--) {
            std::string digit_1 = str1.substr(i, 1);
            std::string digit_2 = str2.substr(i, 1);
            result.insert(0, std::to_string((std::stoi(digit_1) + std::stoi(digit_2) + carry) % 10));
            //std::cout << "i: " << i << " digit_1: " << digit_1 << " digit_2: " << digit_2 << " temp_sum: " << (std::stoi(digit_1) + std::stoi(digit_2) + carry) << " carry: " << carry << '\n';
            carry = (std::stoi(digit_1) + std::stoi(digit_2) + carry) / 10;
        }

        //Prepend the final carry value to the result std::string.
        //std::cout << "carry after loop exit: " << carry << '\n';
        if (carry > 0) {
            result.insert(0, std::to_string(carry));
        }

        return result;
    }

    uint64_t digit_sum(int exponent) {
        std::string str1 = "1";
        std::string str2 = "1";
        std::string sum;
        uint64_t digit_sum = 0;
        for (int i = 1; i <= exponent; i++) {
            sum = add_num_str(str1, str2);
            str1 = sum;
            str2 = sum;
        }

        for (int j = 0; j < static_cast<int>(sum.size()); j++) {
            digit_sum += std::stoi(sum.substr(j, 1));
        }

        return digit_sum;
    }
}