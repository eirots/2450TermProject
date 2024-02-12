#include <iostream>

#include "../io/read.h"
#include "../io/write.h"

extern int memory[];

void test_READ() {
    for (int i = 0; i < 100; i++) {
        memory[i] = i;
    }
    READ(10);
    if (memory[10] != 10) {
        std::cout << "\tread test failed" << std::endl;
    } else {
        std::cout << "\tread passed!" << std::endl;
    }
}

void test_WRITE() {
    WRITE(5, 20);
    if (memory[5] != 20) {
        std::cout << "\twrite failed!" << std::endl;
    } else {
        std::cout << "\twrite passed!" << std::endl;
    }
}
