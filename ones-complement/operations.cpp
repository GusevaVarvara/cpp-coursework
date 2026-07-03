#include <cmath>
#include "operations.h"

std::string toReverseBinary(int num, int num_bits) {
    std::string reverse_binary = "";
    bool is_negative = false;

    if (num < 0) {
        is_negative = true;
        num = -num;
    }

    for (int i = 0; i < num_bits; ++i) {
        reverse_binary = (num % 2 == 0 ? "0" : "1") + reverse_binary;
        num /= 2;
    }

    if (is_negative) {
        for (char& bit : reverse_binary) {
            bit = (bit == '0' ? '1' : '0');
        }
    }

    return reverse_binary;
}


int fromReverseBinary(std::string binary) {
    int result = 0;
    int sign = (binary[0] == '1' ? -1 : 1);

    if (sign == -1) {
        for (char& bit : binary) {
            bit = (bit == '0' ? '1' : '0');
        }
    }

    for (int i = binary.size() - 1; i > 0; --i) {
        result += (binary[i] - '0') * pow(2, binary.size() - 1 - i);
    }

    return result * sign;
}


std::string reverseBinaryAddition(std::string binary1, std::string binary2) {
    std::string result = "";
    int carry = 0;

    for (int i = binary1.size() - 1; i >= 0; --i) {
        int sum = (binary1[i] - '0') + (binary2[i] - '0') + carry;
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }

    std::string final_result = "";

    for (int i = result.size() - 1; i >= 0; --i) {
        int sum = (result[i] - '0') + carry;
        final_result = char(sum % 2 + '0') + final_result;
        carry = sum / 2;
    }

    return final_result;
}

std::string reverseBinarySubtraction(std::string binary1, std::string binary2) {
    for (char& bit : binary2) {
        bit = (bit == '0' ? '1' : '0');
    }

    return reverseBinaryAddition(binary1, binary2);
}

std::string reverseBinaryMultiplication(std::string binary1, std::string binary2) {
    int len = binary1.length();
    std::string result = std::string(len, '0');

    for (int i = len - 1; i >= 0; --i) {
        if (binary2[i] == '1') {
            std::string temp = binary1;
            if (binary1[0] == '1') {
                temp.append(len - i - 1, '1');
            }
            else
            {
                temp.append(len - i - 1, '0');
            }
            if (temp.length() > len) {
                temp = temp.substr(temp.length() - len);
            }
            result = reverseBinaryAddition(result, temp);
        }
    }
    return result;
}




