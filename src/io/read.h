class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef READ_H
#define READ_H


/*
 * class Read
 * A class to handle the read operation in the UVSimulator.
 * This class provides the functionality to read an integer from the user and store it in a specific memory location in the UVSimulator.
 */

class Read {
   public:
    void execute(UVSimulator& simulator, int operand);
};

#endif  // READ_H
