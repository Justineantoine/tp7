#include <stdio.h>
#include <stdlib.h>
#include "String.h"

//size_t String::MAX_SIZE;

//Constructors
String::String(const String& tocopy){
	//copying attributs of tocopy in 
	size_ = tocopy.size_;
	c_str_ = tocopy.c_str_;
	capacity_ = tocopy.capacity_;
}
	
	
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
