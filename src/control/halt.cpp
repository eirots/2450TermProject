#include "halt.h"

void Halt::HALT() {}

/*
 * Executes the halt operation.
 * This method halts the execution of the program.
 * param: simulator A reference to the UVSimulator instance on which to perform the halt operation.
 * pre: None.
 * post: The execution of the program is halted.
 */
void Halt::execute(UVSimulator &simulator) {
    simulator.setPC(-1);
}
