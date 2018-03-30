#include "String.h"

size_t String::MAX_SIZE;

//Constructors

//Getters

//Operators

//Methodes

//Destructor
String::~String()
{
delete []c_str_;
c_str_ = nullptr;
size_ = 0;
}
