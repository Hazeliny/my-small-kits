/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_dtoBinaryIP.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:26:03 by linyao            #+#    #+#             */
/*   Updated: 2024/12/06 21:27:36 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string decimalToBinaryIP(const std::string& decimalIP) {
/*
    std::vector<std::string> octets = split(decimalIP, '.');
    if (octets.size() != 4) {
        return "Invalid IP address format";
    }
*/    
    std::ostringstream binaryIP;
    std::string octet;
    octet = decimalIP;
    int octet_num = std::stoi(octet);
    binaryIP << std::bitset<8>(octet_num);
    std::cout << "Binary: " << binaryIP.str() << std::endl;
/*
    for (size_t i = 0; i < octets.size(); ++i) {
        int octet;
        try {
            octet = std::stoi(octets[i]);
            if (octet < 0 || octet > 255) {
                return "Invalid IP address range";
            }
        } catch (...) {
            return "Invalid IP address format";
        }
        binaryIP << std::bitset<8>(octet);
        if (i < octets.size() - 1) {
            binaryIP << ".";
        }
    }
*/
    return binaryIP.str();
}

int main() {
    std::string decimalIP;
    std::cout << "Enter a number in decimal format: ";
    std::cin >> decimalIP;
    
    std::string binaryIP = decimalToBinaryIP(decimalIP);
/*
    if (binaryIP == "Invalid IP address format" || binaryIP == "Invalid IP address range") {
        std::cerr << binaryIP << std::endl;
    } else {
        std::cout << "Binary IP address: " << binaryIP << std::endl;
    }
*/
    return 0;
}

/*
#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

// 函数将十进制的 IP 地址转换为二进制格式
void ipToBinary(const string& ip) {
    stringstream ss(ip);
    string octet;
    while (getline(ss, octet, '.')) {
        // 将每个八位字节转换为二进制格式并输出
        int octetInt = stoi(octet);
        cout << bitset<8>(octetInt);  // 输出每个八位字节的二进制形式
        if (ss.peek() != EOF) {
            cout << ".";  // 如果还有更多的字节，添加点分隔符
        }
    }
    cout << endl;
}

int main() {
    string ip;

    cout << "请输入一个 IP 地址（如：192.168.1.1）：";
    cin >> ip;

    // 调用函数进行转换
    ipToBinary(ip);

    return 0;
}
*/