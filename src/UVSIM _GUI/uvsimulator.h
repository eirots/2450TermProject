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
class Write;

// control classes
class Control;
class Branch;
class BranchZero;
class BranchNeg;
class Halt;

// end of forward declarations
#ifndef UVSIMULATOR_H
#define UVSIMULATOR_H

#include <vector>

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
    std::vector<int> memory;
    int accumulator;
    int pc;

   public:
    UVSimulator();
    void loadProgram(const std::vector<int> &program);
    void executeProgram(int command);
    std::vector<int> buildProgram();
    int getMemory(int index) const;
    void setMemory(int index, int value);
    int getMemSize();
    int getAccumulator() const;
    void setAccumulator(int value);
    void printMemory() const;
    void setPC(int value);
    int getPC();
};

#endif  // UVSIMULATOR_H