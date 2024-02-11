#include "add.h"

Add::Add() {}

int Add::add(int &operand, int operand1)
{
    operand += operand1;
    return operand;
}
