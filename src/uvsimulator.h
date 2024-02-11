#ifndef UVSIMULATOR_H
#define UVSIMULATOR_H

#include <vector>

class Branch;  // forward declaration to avoid cyclical delcarations

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
    int getAccumulator() const;
    void setAccumulator(int value);
    void printMemory() const;
    void setPC(int value);
    int getPC();
};

#endif
