#include <cassert>
#include <iostream>
#include <string>

#include "Divide.h"

// test cases go here
void runTests() {
    // division test cases
    Divide div;
    int divResult;
    int divX = 10, divY = 5;
    divResult = div.divide(divX, divY);
    std::cout << "Division test 1: " << divResult << std::endl;
    divY = 0;
    divResult = div.divide(divX, divY);
    std::cout << "Division test 2: " << divResult << std::endl;

    Add adder;
    int addResult;
    int addX = 2, addY = 3;
    addResult = adder.add(addX, addY);
    std::cout << "Addition test 1: " << addResult <<  std::endl;  
    addY = -3;
    addResult = adder.add(addX, addY);
    std::cout << "Addition test 2: " << addResult <<   std::endl; 
}
    
}

int main() {
    runTests();
}
