#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "String.h"
#include <cstring>

const size_t String::MAX_SIZE;

//Constructors
String::String(const String& tocopy){
	//copying attributes of tocopy in a new String
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

/*Pre-conditions : None
Post-conditions : The this String argument will have the same atributes as s argument. the c_str_ has the same content but a different adress
Return : The modified String passed as this argument*/
String& String::operator=(String s){
	delete[] c_str_;
	size_t new_size = s.size();
	char* ptr = new char[new_size +1];
	for(int i=0;i<new_size;++i){
		ptr[i] = s.c_str_[i];
	}
	ptr[new_size] = '\0';
	c_str_=ptr;
	size_=new_size;
	reserve(size_+1);
	return *this;
}


//Methodes

size_t String::max_size() const{
	return MAX_SIZE;
}

/*Return : 1 if empty, 0 if not empty*/
bool String::empty() const{
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

/*Pre-conditions : None
Post-conditions :Erases the content of c_str_ and reduces capacity_ and size_. The 'x' argument has no utility here as 0 will always be inferior or equal to the actual size of the String*/
void String::clear(){
	resize(0,'x');
}

//Destructor
String::~String(){
	delete[] c_str_;
	size_=0;
	capacity_=0;
}

String operator+(const String& lhs, const char* rhs){
	String finals(lhs);
	size_t size1 = lhs.length();
	int size2=0;
    while(rhs[size2] != '\0'){
        ++size2;
      }
	size_t size = size1 + size2;
	finals.reserve(size+1);
	int j;
	for (j=size1;j<size+1;++j){
		finals.c_str_[j] = rhs[j-size1];
	}
	finals.size_ = size;
	return(finals);
}

String operator+(const String& lhs, const String& rhs){
	String finals(lhs);
	size_t final_size = lhs.size_ + rhs.size_;
	finals.reserve(final_size + 1); //il faut compter le '\0'
	for (int i = 0 ; i < rhs.size_ + 1 ; ++i) {
		finals.c_str_[lhs.size_ + i] = rhs.c_str_[i];
	}
	finals.size_ = final_size;
	return(finals);
}

/*Pre-conditions : None
Post-conditions : None
Return : A String constructed from lhs with the char rhs at the end of c_str_.*/
String operator+(const String& lhs, char rhs){
	String finals(lhs); //On copie lhs dans un nouveau String
	size_t final_size = lhs.size() +1;
	finals.reserve(final_size+1);//Ici on a une chaîne de caractère terminée par /0 puis une case non utilisée
	finals.c_str_[final_size-1] = rhs;//On remplace le /0 par le caractère à ajouter.
	finals.size_ = final_size;
	return finals;
}
	
