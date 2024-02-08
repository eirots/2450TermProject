#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class UVSimulator {
private:
    vector<int> memory;   // Vector that acts as storage for memory locations
    int accumulator;      // Accumulator register
    int pc;               // Program Counter

public:
    UVSimulator() : memory(100, 0), accumulator(0), pc(0) {}

    // Load input program into memory
    void loadProgram(const vector<int>& program) {
        for (int i = 0; i < program.size(); ++i) {
            memory[i] = program[i];
        }
    }

    // execute the program
    void executeProgram() {
        while (true) {
            int instruction = memory[pc];     // Reads instruction from memory (starts at 00)
            int opcode = instruction / 100;   // Instruction to take place(i.e "ADD")
            int operand = instruction % 100;  // Memory location for that instruction

            switch (opcode) {
                case 10:  // READ
                    break;
                case 11:  // WRITE
                    break;
                case 20:  // LOAD
                    break;
                case 21:  // STORE
                    break;
                case 30:  // ADD
                    break;
                case 31:  // SUBTRACT
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
                    return;
            }

            ++pc;  // Move to the next instruction
        }
    }
    vector<int> buildProgram(){
        vector<int> program;
        string userInput;
        
        do{
            cout << "Enter your 4-digit operation or 'done' to exit: \n";
            cin >> userInput;
            if (userInput == "done"){
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
};

int main() {

    UVSimulator simulator;
    vector<int> program = simulator.buildProgram();
    simulator.loadProgram(program);
    simulator.executeProgram();

    return 0;
}