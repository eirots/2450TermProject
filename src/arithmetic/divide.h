class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef DIVIDE_H
#define DIVIDE_H

class Divide {
   public:
    Divide();
    void execute(UVSimulator& sim, int divisor);
};
#endif  // DIVIDE_H