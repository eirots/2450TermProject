#include "read.h"
#include "write.h"
#include <iostream>

extern int memory[];

void test_READ(){
  for(i=0; i<0; i++){
    memory[i]=i
  }
  READ(10);
  if (memory[10]!=10){
    std::cout<<" Read test failed!"<<std::endl;
  } else{
      std::cout<<"Read test passed!"<<std::endl;
    }
}

void test_WRITE(){
  WRITE(5,20);
  if (memory[5]!=20{
    std::cout<<"Write test failed!"<< std::endl;
  } else{
      std::cout<<"Write test passed!"<<std::endl;
    }
}

int main(){
  test_READ();
  test_WRITE();
  Return 0;
}
