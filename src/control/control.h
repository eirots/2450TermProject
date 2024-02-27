class UVSimulator;  // forward declaration to avoid circular dependancies

#ifndef CONTROL_H
#define CONTROL_H

/*Purely virtual class for ensuring that other Control classes derive from this. */
class Control {
   public:
    virtual void execute(UVSimulator& sim, int operand) = 0;  // ensuring that there is no base functionalty, purely virtual function
                                                              // virtual void execute(UVSimulator& sim) = 0;
};

#endif  // CONTROL_H