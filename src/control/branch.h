#include "../uvsimulator.h"

class uvsimulator;  // forward declaration to avoid cyclical declarations

class Branch {
   public:
    void BRANCH();
    void execute(UVSimulator &simulator, int operand);
};
