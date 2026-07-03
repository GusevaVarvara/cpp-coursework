#include <iostream>
#include <string>
#include "operations.h"


std::string operator+(std::string binary1, std::string binary2) {
    return reverseBinaryAddition(binary1, binary2);
}

std::string operator-(std::string binary1, std::string binary2) {
    return reverseBinarySubtraction(binary1, binary2);
}

std::string operator*(std::string binary1, std::string binary2) {
    return reverseBinaryMultiplication(binary1, binary2);
}


int main() {
    int num_bits = 8;
    int num1, num2;
    char operation;

    std::cout << "Enter two numbers and an operation (+, -, *) between them: ";
    std::cin >> num1 >> operation >> num2;

    std::string binary1 = toReverseBinary(num1, num_bits);
    std::string binary2 = toReverseBinary(num2, num_bits);

    std::string result;
    switch (operation) {
    case '+':
        result = binary1 + binary2;
        break;
    case '-':
        result = binary1 - binary2;
        break;
    case '*':
        result = binary1 * binary2;
        break;
    default:
        std::cout << "Unsupported operation!" << std::endl;
        return 1;
    }

    std::cout << "Result: " << fromReverseBinary(result) << std::endl;

    return 0;
}




 