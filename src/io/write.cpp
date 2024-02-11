#include <iostream>
#include "write.h"

extern int memory[];

void WRITE(int location, int value){
  if (location>=0 && location<sizeof(memory)/sizeof(memory[0])){
    memory[location]=value;
    std::out <<"Value "<<value<<"written at location "<<location<< std::endl;
  } else {
      throw std::out_of_range("Memory location out of range");
  }
}
    

