#ifndef LOAD_H
#define LOAD_H

class UVSimulator;

class Load {
   public:
    static void execute(UVSimulator& simulator, int operand);
};

#endif  // LOAD_H