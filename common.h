#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <tuple>

void showBits(int a, std::vector<int>& v) {
    int size = sizeof(a) * 8; //Assuming 8 bits
    int mask = 0x1 << (size - 1);
    size--;
    while(size >= 0) {
        v.push_back(((a & mask) ? 1 : 0));
        mask = 0x1 << (size-1);
        size--;
    }
}

void printBits(std::vector<int>& v) {
    int count = 0;
    for(auto i: v) {
        std::cout<<i;
        count++;
        if (!(count % 8)) std::cout << " ";
    }
    std::cout<<std::endl;
}

long convertToNum(std::string s) {
    int maxLen = s.length();
    long result = 0;
    for (auto [i, mul] = std::tuple{s.rbegin(), 0}; i != s.rend(); i++, mul++) {
        result += (pow(2, mul) * (*i - '0'));
    }
    return result;
}
