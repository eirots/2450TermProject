class UVSimulator;  // forward declaration to avoid circular dependancies

#ifndef IO_H
#define IO_H

/*Purely virtual class for ensuring that other Arithmetic classes derive from this. */
class IO {
   public:
    virtual void execute(UVSimulator& sim, int operand) = 0;  // ensuring that there is no base functionalty, purely virtual function
};

#endif  // IO_h