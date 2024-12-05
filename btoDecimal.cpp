/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoDecimal.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:08:56 by linyao            #+#    #+#             */
/*   Updated: 2024/12/05 22:09:06 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

bool isValidBinary(const std::string& binaryStr) {
    for (char ch : binaryStr) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}

int binaryToDecimal(const std::string& binaryStr) {
    int decimalValue = 0;
    int length = binaryStr.length();
    for (int i = 0; i < length; ++i) {
        if (binaryStr[length - i - 1] == '1') {
            decimalValue += std::pow(2, i);
        }
    }
    return decimalValue;
}

int main() {
    std::string binaryInput;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryInput;

    if (!isValidBinary(binaryInput)) {
        std::cerr << "Invalid binary number!" << std::endl;
        return 1;
    }

    int decimalOutput = binaryToDecimal(binaryInput);
    std::cout << "The decimal value is: " << decimalOutput << std::endl;

    return 0;
}
