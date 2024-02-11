#include <iostream>
#include "read.h"

extern int memory[100];

void READ(int location){
  if(location>=0 && location < sizeof(memory)/sizeof(memory[0])){
    std::cin>>memory[location];
  } else {
      throw std:: out_of_range ("Memory location out of range");
  }
}
  

