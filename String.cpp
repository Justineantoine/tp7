#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "String.h"
#include <cstring>

//size_t String::MAX_SIZE;

//Constructors
String::String(const String& tocopy){
	//copying attributs of tocopy in 
	size_t t_size = tocopy.size_;
	char * t_c_ctr = tocopy.c_str_;
	size_t t_cap = tocopy.capacity_;
	size_ = t_size;
	c_str_ = t_c_str;
	capacity_ = t_cap;
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
String& operator=(const char* s){
	size_t s_size = strlen(*s);
	char* s_str = s
	size_ = s_size;
	c_str_ = s_str;
}
//Methodes

//Destructor
String::~String()
{
	delete []c_str_;
	c_str_ = nullptr;
	size_ = 0;
}
