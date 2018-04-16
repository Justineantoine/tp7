#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "String.h"
#include <cstring>

const size_t String::MAX_SIZE;

//Constructors
String::String(const String& tocopy){
	//copying attributs of tocopy in
	size_t t_size = tocopy.size_; //Necessaire de passer par un intermédiaire ?
	//char * t_c_str = tocopy.c_str_;
	size_t t_cap = tocopy.capacity_;
	size_ = t_size;
	capacity_ = t_cap;
	char* t_c_str = new char[capacity_];
	int i;
	for (i=0;i<size_;++i){
		t_c_str[i] = tocopy.c_str_[i];
	}
	c_str_ = t_c_str;
}
	
String::String(const char* cstr)
{
	long Size = strlen(cstr);
	size_ = Size;
	char* ptr = new char[size_+1];
	ptr[size_]=0;
	strcpy(ptr,cstr);
	capacity_ = size_ + 1;      
	c_str_=ptr;      
}


//Getters

size_t String::length() const{
	return size_;
}

size_t String::size() const{
	return size_;
}

const char* String::c_str() const{
	return c_str_;
}

size_t String::capacity() const
{
	return capacity_;
}
//Operators

 String& String::operator=(const char* s){
	delete[] c_str_;
	int s_size = 0;
	while(s[s_size] != '\0'){
		++s_size;
	}
	 ++s_size;
	
    c_str_ = new char[s_size];
    for(int i=0; i< s_size; ++i){
        c_str_[i] = s[i];
    } 
	size_ = s_size - 1;
	reserve(size_+1);
	return *this;
}


String& String::operator=(char c){
  	delete[] c_str_;
	char* ptr = new char[2];
	ptr[0] = c;
	ptr[1] = '\0';
	c_str_ = ptr;
	size_ = 1;
	reserve(size_+1);
	return *this; //Renvoie l'objet lui-même (qui a été modifié)
}



//Methodes

size_t String::max_size() const{
	return MAX_SIZE;
}

bool String::empty() const{ //retourne "1" si la string est vide
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
		delete[] c_str_;
		c_str_ = ptr;
		size_ = n;
		reserve(n+1);
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
		delete[] c_str_;
		c_str_ = ptr;
		size_ = n;
		reserve(n+1);
	}
}

void String::reserve(size_t n){
	if (n > MAX_SIZE){
		printf("%s\n", "La taille à réserver est plus grande que la taille maximale autorisée");
	}
	else {
		if (n < size_ + 1){
			n = size_ +1;
		}
		char* future_c_str = new char[n];
		for (int i = 0; i < size_ + 1; ++i){ //copie la chaîne de caractère dans le nouvel espace alloué
			future_c_str[i] = c_str_[i];
		}
		delete[] c_str_;
		c_str_ = future_c_str;
		capacity_ = n;
		
	}
}

void String::clear(){
	delete[] c_str_;
	capacity_=1;
	size_=0;
}

//Destructor
String::~String(){
	delete[] c_str_;
}

String operator+(const String& lhs, const char* rhs){
	String final(lhs);
	size_t size1 = lhs.length();
	int size2=0;
    while(rhs[size2] != '\0'){
        ++size2;
      }
	size_t size = size1 + size2;
	final.reserve(size+1);
	int j;
	for (j=size1;j<size+1;++j){
		final.c_str_[j] = rhs[j-size1];
	}
	final.size_ = size;
	return(final);
}

String operator+(const String& lhs, const String& rhs){
	String final(lhs);
	size_t final_size = lhs.size_ + rhs.size_;
	final.reserve(final_size + 1); //il faut compter le '\0'
	for (int i = 0 ; i < rhs.size_ + 1 ; ++i) {
		final.c_str_[lhs.size_ + i] = rhs.c_str_[i];
	}
	final.size_ = final_size;
	return(final);
}
