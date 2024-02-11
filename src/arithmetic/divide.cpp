#include "divide.h"

// but the sign of a data word may be either plus or minus

Divide::Divide() {
    // leaving default constructor, not much else to add from this.
}

// Divide the word in the accumulator by a word from a specific location in memory (leave the result in the accumulator).
int Divide::divide(int &dividend, int divisor) {
    int result;
    if (divisor != 0) {
        result = dividend / divisor;
        return result;
    } else {
        throw("Divide by zero not allowed");
        // need to consider how to handle 0 division issues
    }
}