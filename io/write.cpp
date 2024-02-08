#include <iostream>
#include "write.h"

extern int memory[];

void WRITE(int location){
  if (location>=0 && location<sizeof(memory)/sizeof(memory[0])){
    std::out << memory[location]<< std::endl;
  } else {
      throw std::out_of_range("Memory location out of range");
  }
}
    

