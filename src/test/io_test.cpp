#include <iostream>

#include "read.h"
#include "write.h"
int size = 100;

void test_READ() {
    int memory[size];
    for (int i = 0; i < 100; i++) {
        memory[i] = i;
    }
    READ(10);
    if (memory[10] != 10) {
        std::cout << "Read test failed!" << std::endl;
    } else {
        std::cout << "Read test passed!" << std::endl;
    }
}

void test_WRITE() {
    int memory[size];
    Write write;

    write.WRITE(5, 20, size);
    if (memory[5] != 20) {
        std::cout << "Write test failed!" << std::endl;
    } else {
        std::cout << "Write test passed!" << std::endl;
    }
}

int main() {
    test_READ();
    test_WRITE();
    return 0;
}
