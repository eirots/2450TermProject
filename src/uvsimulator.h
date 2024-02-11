#ifndef UVSIMULATOR_H
#define UVSIMULATOR_H

#include <vector>

// forward declarations to avoid cyclical delcarations
class Branch;
class BranchZero;

class UVSimulator {
   private:
    std::vector<int> memory;
    int accumulator;
    int pc;

   public:
    UVSimulator();
    void loadProgram(const std::vector<int>& program);
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

#endif
