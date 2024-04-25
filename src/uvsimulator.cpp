#include "uvsimulator.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/*
 Constructor for the UVSimulator class.
 Initializes the memory to 100 locations with empty strings, accumulator to 0, and program
 counter to 0.
 */
UVSimulator::UVSimulator() : memory(100, "0"), accumulator(0), pc(0) {}

/*
 * Loads a program into the memory.

 * param: program A vector of strings representing the program to be loaded.
 * pre: The program must be a valid sequence of instructions.
 * post: The program is loaded into the memory.
 */
void UVSimulator::loadProgram(const vector<string>& program) {
    for (size_t i = 0; i < program.size() && i < memory.size(); ++i) {
        memory[i] = program[i];
    }
}

/*
 * Get a value from memory location.

 * param: The index of the memory location.
 * pre: The index must be within the bounds of the memory size.
 * post: Returns the value at the specified index in the memory. If the index is
 out of bounds, returns an empty string.
 */
string UVSimulator::getMemory(int index) const {
    if (index >= 0 && index < memory.size()) {
        return memory[index];
    }
    else {
        return ""; // Returning an empty string if index is out of bounds
    }
}

/*
 * Set a value to memory location

 * param index The index of the memory location, and the value to be set at the
 specified memory location.
 * pre: The index must be within the bounds of the memory size.
 * post: The value at the specified index in the memory is set to the provided
 value. If the index is out of bounds, does nothing.
 */
void UVSimulator::setMemory(int index, const string& value) {
    if (index >= 0 && index < memory.size()) {
        memory[index] = value;
    }
    else {
    } // does nothing if index is out of bounds
}

/*
 * gets size of memory array

 * pre: None.
 * post: Returns the size of the memory array.
 */
int UVSimulator::getMemSize() { return memory.size(); }

/*
 * Get value from accumulator
 * pre: None.
 * post: Returns the current value of the accumulator.
 */
int UVSimulator::getAccumulator() const { return accumulator; }

/*
 * Set value to accumulator

 * param: value The value to be set in the accumulator.
 * pre: None.
 * post: The accumulator is set to the provided value.
 */
void UVSimulator::setAccumulator(int value) { accumulator = value; }

/*
 * sets value of PC for jump operations

 * param: value The value to be set in the program counter.
 * pre: None.
 * post: The program counter is set to the provided value.
 */
void UVSimulator::setPC(int value) { pc = value; }

/*
 * gets value of PC

 * pre None.
 * post Returns the current value of the program counter.
 */
int UVSimulator::getPC() { return pc; }

/*
 * Build a program

 * pre: None.
 * post: Returns a vector of strings representing the program built by the
 user.
 */
vector<string> UVSimulator::buildProgram() {
    vector<string> program;
    string userInput;

    do {
        cout << "Enter your four-digit operation or 'done' to exit: \n";
        cin >> userInput;
        if (userInput == "done") {
            break;
        }
        if (userInput.length() != 4) {
            cout << "Invalid input.\n";
            continue;
        }
        else {
            program.push_back(userInput);
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
    for (size_t i = 0; i < memory.size(); ++i) {
        cout << "Memory[" << i << "]: " << memory[i] << endl;
    }
}
/*
 * Load data values from a file.
 * param: File path for file.
 * pre: None.
 * post: Data values from file are loaded into memory.
 */
int UVSimulator::loadFile(std::string filename) {
    std::ifstream file(filename); // Open the file
    std::vector<std::string> values; // Vector to store values

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) { // Read each line of the file
            std::stringstream ss(line);
            std::string value;
            while (std::getline(ss, value, ',')) { // Tokenize each line by comma
                values.push_back(value); // Store each token in the vector
            }
        }
        file.close(); // Close the file
        for (size_t i = 0; i < values.size(); ++i) { //Load txt file to memory.
            memory[i] = values[i];
        }
    }
    else {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }
}
/*
 * Saves memory to new file.
 * param: file path for saved file.
 * pre: None.
 * post: Data values from memory are saved to file.
 */
int UVSimulator::saveFile(std::string filename) {

    // Open the file for writing
    std::ofstream outputFile(filename);

    // Check if the file was opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return 1;
    }

    // Write the values to the file separated by commas
    for (size_t i = 0; i < memory.size(); ++i) {
        outputFile << memory[i];
        if (i != memory.size() - 1) {
            outputFile << ","; // Add comma delimiter for all values except the last one
        }
    }
    outputFile << std::endl; // Add newline after writing all values

    // Close the file
    outputFile.close();
    return 0;
}
/*
 * Execute the program

 * pre: A program must be loaded into the memory.
 * post: The program is executed and the state of the memory, accumulator, and
 program counter may be changed.
 */


void UVSimulator::executeProgram(int command) {
    pc++;
    int instruction = command; // Reads instruction from memory (starts at 00)
    int opcode = instruction / 100;  // Instruction to take place (i.e., "ADD")
    int operand = instruction % 100; // Memory location for that instruction

    switch (opcode) {
    case 10: // READ
    {
        Read read;
        read.execute(*this, operand);
    } break;
    case 11: // WRITE
    {
        Write write;
        write.execute(*this, operand);
    } break;
    case 20: // LOAD
    {
        Load load;
        load.execute(*this, operand);
    } break;
    case 21: // STORE
    {
        Store store;
        store.execute(*this, operand);
    } break;
    case 30: // ADD
    {
        Add add;
        add.execute(*this, operand);
    } break;
    case 31: // SUBTRACT
    {
        Subtract subtract;
        subtract.execute(*this, operand);
    } break;
    case 32: // DIVIDE
    {
        Divide divide;
        divide.execute(*this, operand);
    } break;
    case 33: // MULTIPLY
    {
        Multiply multiply;
        multiply.execute(*this, operand);
    } break;
    case 40: // BRANCH
    {
        Branch branch;
        branch.execute(*this, operand);
    } break;
    case 41: // BRANCHNEG
    {
        BranchNeg branchneg;
        branchneg.execute(*this, operand);
    } break;
    case 42: // BRANCHZERO
    {
        BranchZero branchzero;
        branchzero.execute(*this, operand);
    } break;
    case 43: // HALT
    {
        Halt halt;
        halt.execute(*this);
    } return;
    default:
        break;
    }
}
