#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include <cstring>

//size_t String::MAX_SIZE;

//Constructors/Destructor
	
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
