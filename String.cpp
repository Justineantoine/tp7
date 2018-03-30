#include <stdio.h>
#include <stdlib.h>
#include "String.h"

//size_t String::MAX_SIZE;

//Constructors/Destructor
String::String(const String& tocopy){
	//copying attributs of tocopy in 
	size_ = tocopy.size_;
	c_str_ = tocopy.c_str_;
	capacity_ = tocopy.capacity_;
}
	
	
//Getters

//Operators

//Methodes
