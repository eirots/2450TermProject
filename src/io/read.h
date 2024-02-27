class UVSimulator;  // forward declaration to avoid cyclical declarations

#ifndef READ_H
#define READ_H
#include "io.h"

class Read : public IO {
   public:
    void execute(UVSimulator& simulator, int operand) override;
};

#endif  // READ_H
