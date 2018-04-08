#ifndef STRING_H
#define STRING_H

#include <cstdio>
#include <cstdlib>

class String{
    friend String operator+(const String& lhs, const char* rhs);
    friend String operator+(const String& lhs, const String& rhs);
	protected:
	//Attributs
	size_t size_;
	char* c_str_; //pointeur vers la premiere case du tableau de char
	size_t capacity_;
	
	public:
	const static size_t MAX_SIZE = 150;	

	//Constructors/Destructor
  String(const String& tocopy);
	String(const char* cstr);

	//Operators
    String& operator=(const char* s);
	String& operator=(char c);

	//Methodes
	size_t length() const;
	size_t capacity();
	size_t max_size() const;
	bool empty();
	const char* c_str() const;
	void resize(size_t n, char c);
	void reserve(size_t n);


	//Destructor
	~String();
};

//Non member fonctions

String operator+ (const String& lhs, const char* rhs);
String operator+(const String& lhs, const String& rhs);




#endif
