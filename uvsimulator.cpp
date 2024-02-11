#include "uvsimulator.h"
#include "loadstore/load.h"
#include "loadstore/store.h"
#include "arithmetic/subtract.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Constructor
UVSimulator::UVSimulator() : memory(100, 0), accumulator(0), pc(0) {}

// Load input program into memory
void UVSimulator::loadProgram(const vector<int>& program) {
    for (int i = 0; i < program.size(); ++i) {
        memory[i] = program[i];
    }
}

// Get a value from memory location
int UVSimulator::getMemory(int index) const {
    if (index >= 0 && index < memory.size()) {
        return memory[index];
    } else {               
        return 0; // Returning 0 if index is out of bounds
    }
}

// Set a value to memory location
void UVSimulator::setMemory(int index, int value) {
    if (index >= 0 && index < memory.size()) {
        memory[index] = value;
    } else {} // does nothing if index is out of bounds
}

// Get value from accumulator
int UVSimulator::getAccumulator() const {
    return accumulator;
}

// Set value to accumulator
void UVSimulator::setAccumulator(int value) {
    accumulator = value;
}

// Build a program
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

void UVSimulator::printMemory() const {
        cout << "Memory contents:" << endl;
        for (int i = 0; i < memory.size(); ++i) {
            cout << "Memory[" << i << "]: " << memory[i] << endl;
    }
}

// Execute the program
void UVSimulator::executeProgram() {
    while (true) {
        int instruction = memory[pc];     // Reads instruction from memory (starts at 00)
        int opcode = instruction / 100;   // Instruction to take place (i.e., "ADD")
        int operand = instruction % 100;  // Memory location for that instruction

        switch (opcode) {
            case 10:  // READ
                break;
            case 11:  // WRITE
                break;
            case 20:  // LOAD
                {
                    Load load;
                    load.execute(*this, operand);
                }
                break;
            case 21:  // STORE
                {
                    Store store;
                    store.execute(*this, operand);
                }
                break;
            case 30:  // ADD
                break;
            case 31:  // SUBTRACT
                {
                    Subtract subtract;
                    subtract.execute(*this, operand);
                }
                break;
            case 32:  // DIVIDE
                break;
            case 33:  // MULTIPLY
                break;
            case 40:  // BRANCH
                continue;
            case 41:  // BRANCHNEG
                break;
            case 42:  // BRANCHZERO
                break;
            case 43:  // HALT
                return;
            default:
                cout << "Opcode: " << operand << " is invalid and was not included in the program." << endl;
                return;
        }

        ++pc;  // Move to the next instruction
    }
}