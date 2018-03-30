#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

class String{
	protected:
	//Attributs
	size_t size_;
	char* c_str_; //pointeur vers la premiere case du tableau de char
	size_t capacity_;
	
	public:
	static size_t MAX_SIZE;	

	//Constructors/Destructor
  String(const String& tocopy);

	//Operators
  String& operator=(const char* s);

	//Methodes


	//Destructor
	~String();
};









#endif
