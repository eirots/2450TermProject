#ifndef STORE_H
#define STORE_H

class UVSimulator;

class Store {
   public:
    static void execute(UVSimulator& simulator, int operand);
};

#endif  // STORE_H