#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include <cstring>

const size_t String::MAX_SIZE;

//Constructors
String::String(const String& tocopy){
	//copying attributs of tocopy in 
	size_t t_size = tocopy.size_;
	char * t_c_str = tocopy.c_str_;
	size_t t_cap = tocopy.capacity_;
	size_ = t_size;
	c_str_ = t_c_str;
	capacity_ = t_cap;
}
	
String::String(const char* cstr)
{
	long Size = strlen(cstr);
	size_ = Size;
	char* ptr = new char[size_+1];
	ptr[size_]=0;
	strcpy(ptr,cstr);
	char* string_ptr = ptr;
	capacity_ = size_ + 1;      
	c_str_=ptr;      
}


//Getters

size_t String::length() const{
	return size_;
}

void String::to_string(){
	for(int i=0;i<=size_;++i){
		printf("%s",c_str_[i]);
	}
}

const char* String::c_str() const{
	return c_str_;
}

size_t String::capacity()
{
 return capacity_;
}
//Operators
/*
String& operator=(const char* s){
	size_t s_size = strlen(*s);
	char* s_str = s
	size_ = s_size;
	c_str_ = s_str;
}
*/

String& String::operator=(char c){
	char* ptr = new char[2];
	ptr[0] = c;
	ptr[size_] = '\0';
	c_str_ = ptr;
	size_ = 1;
	return *this; //Renvoie l'objet lui-même (qui a été modifié)
}



//Methodes

size_t String::max_size() const{
	return MAX_SIZE;
}

bool String::empty(){ //retourne "true" si la string est vide
	if (size_ == 0){
		return true;
	}
	else {
		return false;
	} 
}
void String::resize(size_t n, char c){
	if (n < size_){
		char* ptr = new char[n+1];
		int i;
		for (i=0;i<n;++i){
			ptr[i] = c_str_[i];
		}
		ptr[n] = '\0';
		c_str_ = ptr;
		size_ = n;
	}
	if (n > size_){
		char* ptr = new char[n+1];
		int i;
		for (i=0;i<size_;++i){
			ptr[i] = c_str_[i];
		}
		int j;
		for (j=size_;j<n;++j){
			ptr[j] = c;
		}
		ptr[n] = '\0';
		c_str_ = ptr;
		size_ = n;
	}
}

//Destructor
/*String::~String()
{
	delete []c_str_;
	c_str_ = nullptr;
	size_ = 0;
}*/

//Non member fonctions

String operator+(const String& lhs, const char* rhs){
	String str1(lhs);
	String str2(rhs);
	size_t size1 = str1.length();
	size_t size2 = str2.length();
	size_t size = size1 + size2;
	char* ptr = new char[size+1];
	int i;
	for (i=0;i<size1;++i){
		ptr[i] = str1.c_str_[i];
	}
	int j;
	for (j=size1;j<size;++j){
		ptr[j] = str2.c_str_[j-size1];
	}
	ptr[size] = '\0';
	String str(ptr);
	delete[] ptr;
	return str;
}
