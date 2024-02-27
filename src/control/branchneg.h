#ifndef branchneg_h
#define branchneg_h
#include "../uvsimulator.h"
#include "control.h"

class UVSimulator;  // forward declaration to avoid cyclical declarations

class BranchNeg : public Control {
   public:
    void BRANCHNEG();
    void execute(UVSimulator &simulator, int operand) override;
};
#endif  // branchneg_h