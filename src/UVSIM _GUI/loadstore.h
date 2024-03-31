class UVSimulator;  // forward declaration to avoid circular dependancies

#ifndef LOADSTORE_H
#define LOADSTORE_H

/*Purely virtual class for ensuring that other Load/Store classes derive from this. */
class LoadStore {
   public:
    virtual void execute(UVSimulator& sim, int operand) = 0;  // ensuring that there is no base functionalty, purely virtual function
};

#endif  // LOADSTORE_H