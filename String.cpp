#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include <cstring>

//size_t String::MAX_SIZE;

//Constructors
String::String(const String& tocopy){
	//copying attributs of tocopy in 
	size_ = tocopy.size_;
	c_str_ = tocopy.c_str_;
	capacity_ = tocopy.capacity_;
}
	
String::String(char* cstr)
{
	long Size = strlen(cstr);
	size_ = Size;
	char* ptr = new char[size_+1];
	ptr[size_]=0;
	strcpy(ptr,cstr);
	char* string_ptr = ptr;
	capacity_ = size_ + 1;            
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
