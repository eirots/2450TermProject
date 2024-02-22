#ifndef LOAD_H
#define LOAD_H

class UVSimulator;


/*
 * class Load
 * A class to handle the load operation in the program.
 *
 * This class provides the functionality to load a value from a specific memory location into the accumulator of the program.
 */
class Load {
   public:
    static void execute(UVSimulator& simulator, int operand);
};

#endif  // LOAD_H
