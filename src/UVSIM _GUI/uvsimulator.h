// forward declarations to avoid cyclical delcarations

// arithmetic classes
class Arithmetic;
class Add;
class Divide;
class Multiply;
class Subtract;

// io classes
class IO;
class Read;

// control classes
class Control;
class Branch;
class BranchZero;
class Write;
class BranchNeg;
class Halt;

// end of forward declarations
#ifndef UVSIMULATOR_H
#define UVSIMULATOR_H

#include <vector>
#include <string> // Added to use std::string

#include "add.h"
#include "divide.h"
#include "multiply.h"
#include "subtract.h"
#include "branch.h"
#include "branchneg.h"
#include "branchzero.h"
#include "halt.h"
#include "read.h"
#include "write.h"
#include "load.h"
#include "store.h"

class UVSimulator {
private:
    std::vector<std::string> memory;
    int accumulator;
    int pc;

public:
    UVSimulator();
    void loadProgram(const std::vector<std::string>& program); // Changed parameter type
    void executeProgram(int command);
    std::vector<std::string> buildProgram(); // Changed return type
    std::string getMemory(int index) const; // Changed return type
    void setMemory(int index, const std::string& value); // Changed parameter type
    int getMemSize();
    int getAccumulator() const;
    void setAccumulator(int value);
    void printMemory() const;
    int loadFile(std::string filename);
    int saveFile(std::string filename);
    void setPC(int value);
    int getPC();
};

#endif  // UVSIMULATOR_H
