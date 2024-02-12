#ifndef UVSIMULATOR_H
#define UVSIMULATOR_H

#include <vector>

#include "arithmetic/add.h"
#include "arithmetic/divide.h"
#include "arithmetic/multiply.h"
#include "arithmetic/subtract.h"
#include "control/branch.h"
#include "control/branchneg.h"
#include "control/branchzero.h"
#include "control/halt.h"
#include "io/read.h"
#include "io/write.h"
#include "loadstore/load.h"
#include "loadstore/store.h"

// forward declarations to avoid cyclical delcarations
class Branch;
class BranchZero;
class BranchNeg;
class Halt;
// end of forward declarations

class UVSimulator {
   private:
    std::vector<int> memory;
    int accumulator;
    int pc;

   public:
    UVSimulator();
    void loadProgram(const std::vector<int> &program);
    void executeProgram();
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