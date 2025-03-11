#include "main.h"

int lines::numberSymbols() {
    int symbols = 0;
    for (char i : text) {
        symbols++;
    }
    return symbols;
}

std::string lines::textWithout5() {
    std::string result;
    for (char i : text) {
        if (i != '5') {
            result += i;
        }
    }
    return result;
}

int main() {
    lines object1;
    std::cin >> object1.text;
    std::cout << std::endl;
    std::cout << object1.numberSymbols() << std::endl;
    std::cout << object1.textWithout5() << std::endl;
}