#ifndef STRING_H
#define STRING_H

#include <cstdio>
#include <cstdlib>

class String{
    friend String operator+(const String& lhs, const char* rhs);
    friend String operator+(const String& lhs, const String& rhs);
    friend String operator+(const String& lhs, char rhs);
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
	String& operator=(String s);

	//Methodes
	size_t length() const;
	size_t size() const;
	size_t capacity() const;
	size_t max_size() const;
	bool empty() const;
	const char* c_str() const;
	void resize(size_t n, char c);
	void reserve(size_t n);
	void clear();


	//Destructor
	~String();
};

//Non member fonctions

String operator+ (const String& lhs, const char* rhs);
String operator+(const String& lhs, const String& rhs);
String operator+(const String& lhs, char rhs);




#endif
