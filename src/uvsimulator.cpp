#include "uvsimulator.h"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
 Constructor for the UVSimulator class.
 Initializes the memory to 100 locations with 0, accumulator to 0, and program counter to 0.
 */
UVSimulator::UVSimulator() : memory(100, 0), accumulator(0), pc(0) {}

/*
 * Loads a program into the memory.
 
 * param: program A vector of integers representing the program to be loaded.
 * pre: The program must be a valid sequence of instructions.
 * post: The program is loaded into the memory.
 */
void UVSimulator::loadProgram(const vector<int>& program) {
    for (int i = 0; i < program.size(); ++i) {
        memory[i] = program[i];
    }
}

/*
 * Get a value from memory location.
 
 * param: The index of the memory location.
 * pre: The index must be within the bounds of the memory size.
 * post: Returns the value at the specified index in the memory. If the index is out of bounds, returns 0.
 */
int UVSimulator::getMemory(int index) const {
    if (index >= 0 && index < memory.size()) {
        return memory[index];
    } else {
        return 0;  // Returning 0 if index is out of bounds
    }
}

/* 
 * Set a value to memory location

 * param index The index of the memory location, and the value to be set at the specified memory location.
 * pre: The index must be within the bounds of the memory size.
 * post: The value at the specified index in the memory is set to the provided value. If the index is out of bounds, does nothing.
 */
void UVSimulator::setMemory(int index, int value) {
    if (index >= 0 && index < memory.size()) {
        memory[index] = value;
    } else {
    }  // does nothing if index is out of bounds
}

/*
 * gets size of memory array

 * pre: None.
 * post: Returns the size of the memory array.
 */
int UVSimulator::getMemSize() {
    return memory.size();
}

/*
 * Get value from accumulator
 * pre: None.
 * post: Returns the current value of the accumulator.
 */
int UVSimulator::getAccumulator() const {
    return accumulator;
}

/* 
 * Set value to accumulator

 * param: value The value to be set in the accumulator.
 * pre: None.
 * post: The accumulator is set to the provided value.
 */
void UVSimulator::setAccumulator(int value) {
    accumulator = value;
}

/*
 * sets value of PC for jump operations

 * param: value The value to be set in the program counter.
 * pre: None.
 * post: The program counter is set to the provided value.
 */
void UVSimulator::setPC(int value) {
    pc = value;
}

/* 
 * gets value of PC

 * pre None.
 * post Returns the current value of the program counter.
 */
int UVSimulator::getPC() {
    return pc;
}

/*
 * Build a program
 
 * pre: None.
 * post: Returns a vector of integers representing the program built by the user.
 */
vector<int> UVSimulator::buildProgram() {
    vector<int> program;
    string userInput;

    do {
        cout << "Enter your four-digit operation or 'done' to exit: \n";
        cin >> userInput;
        if (userInput == "done") {
            break;
        }
        stringstream ss(userInput);
        int number;
        if (!(ss >> number) || ss.peek() != EOF || userInput.length() != 4) {
            cout << "Invalid input.\n";
            continue;
        } else {
            int operation = stoi(userInput);
            program.push_back(operation);
        }
    } while (true);

    return program;
}

/*
 * Prints the contents of the memory.
 *
 * pre: None.
 * post: The contents of the memory are printed to the console.
 */
void UVSimulator::printMemory() const {
    cout << "Memory contents:" << endl;
    for (int i = 0; i < memory.size(); ++i) {
        cout << "Memory[" << i << "]: " << memory[i] << endl;
    }
}

/*
 * Execute the program
 
 * pre: A program must be loaded into the memory.
 * post: The program is executed and the state of the memory, accumulator, and program counter may be changed.
 */
void UVSimulator::executeProgram() {
    while (true) {
        int instruction = memory[pc];     // Reads instruction from memory (starts at 00)
        int opcode = instruction / 100;   // Instruction to take place (i.e., "ADD")
        int operand = instruction % 100;  // Memory location for that instruction

        switch (opcode) {
            case 10:  // READ
            {
                Read read;
                read.execute(*this, operand);
            } break;
            case 11:  // WRITE
            {
                Write write;
                write.execute(*this, operand);
            } break;
            case 20:  // LOAD
            {
                Load load;
                load.execute(*this, operand);
            } break;
            case 21:  // STORE
            {
                Store store;
                store.execute(*this, operand);
            } break;
            case 30:  // ADD
            {
                Add add;
                add.execute(*this, operand);
            } break;
            case 31:  // SUBTRACT
            {
                Subtract subtract;
                subtract.execute(*this, operand);
            } break;
            case 32:  // DIVIDE
            {
                Divide divide;
                divide.execute(*this, operand);
            } break;
            case 33:  // MULTIPLY
            {
                Multiply multiply;
                multiply.execute(*this, operand);
            } break;
            case 40:  // BRANCH
            {
                Branch branch;
                branch.execute(*this, operand);
            } break;
            case 41:  // BRANCHNEG
            {
                BranchNeg branchneg;
                branchneg.execute(*this, operand);
            } break;
            case 42:  // BRANCHZERO
            {
                BranchZero branchzero;
                branchzero.execute(*this, operand);
            } break;
            case 43:  // HALT
            {
                Halt halt;
                halt.execute(*this);
            }
                return;
            default:
                cout << "Opcode: " << operand << " is invalid and was not included in the program." << endl;
                return;
        }

        ++pc;  // Move to the next instruction
    }
}
