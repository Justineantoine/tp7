#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "String.h"

void test_constructor_cstr();
void test_copy_constructor();
void test_length(const String& s);
void test_capacity(const String& s);
void test_max_size(const String& s);
void test_empty(const String& s1, const String& s2);
void test_c_str(const String& s);
void test_resize(String s1, String s2);
void test_reserve(String s);
void test_equal_operator_char(String s, char letter);
void test_equal_operator_charptr(String s, char * chaine);
void test_plus_operator_charptr(String s, char* chaine);
void test_plus_operator_string(String s1, String s2);
void test_clear(String s);

int main(int argc, char* argv[]){
	std::cout << "Hello World !" << std::endl;
	test_constructor_cstr();
	test_copy_constructor(); //on vérifie les constructeurs

	/* CONSTRUCTION DE STRING POUR LES TESTS */
	char chaine1[] = "Bonjour";
	String str1(chaine1);
	char vide[] = "";
	String strvide(vide);
	char chaine2[] = "Hello";
	char chaine3[] = ", ça va ?";
	String str2(chaine3);

	test_length(str1);
	test_capacity(str1);
    test_max_size(str1);
    test_empty(str1, strvide);
	test_c_str(str1);
	test_resize(str1, str1);
	test_reserve(str1);
	test_equal_operator_char(str1, 'A');
	test_equal_operator_charptr(str1, chaine2);
	test_plus_operator_charptr(str1, chaine3);
	test_plus_operator_string(str1, str2);
	test_clear(str1);


	return 0;
}

void test_constructor_cstr(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << "Test constructor from c-string =" << std::endl;
	std::cout << &str1 << std::endl;
}

void test_copy_constructor(){
  	std::cout << "Test copy constructor" << std::endl;
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << &str1 << std::endl;
	String str2(str1);
	std::cout << &str2 << std::endl;
}

void test_length(const String& s){
	std::cout << "Test getter length()" << std::endl;
	std::cout << s.length() << std::endl;
}

void test_capacity(const String& s){
	std::cout << "Test getter capacity()" << std::endl;
	std::cout << s.capacity() << std::endl;
}


void test_max_size(const String& s){
  	std::cout << "Test getter max_size()" << std::endl;
  	std::cout << s.max_size() << std::endl;
}

void test_empty(const String& s1, const String& s2){
	std::cout << "Test boolean empty()" << std::endl;
	std::cout << "string non vide =" << s1.empty() << std::endl;
	std::cout << "string vide =" << s2.empty() << std::endl;
}
void test_c_str(const String& s){
	std::cout << "Test getter c_str() : " << std::endl;
	std::cout << s.c_str() << std::endl;
}

void test_resize(String s1, String s2){
	s1.resize(4,'d');
	std::cout << "Test resize() avec n < size_" << std::endl;
	std::cout << "Nouvelle taille : " << s1.length() << std::endl;
	std::cout << "Nouvelle chaine : " << s1.c_str() << std::endl;

	s2.resize(10,'d');
	std::cout << "Test resize() avec n > size_" << std::endl;
	std::cout << "Nouvelle taille : " << s2.length() << std::endl;
	std::cout << "Nouvelle chaine : " << s2.c_str() << std::endl;
}

void test_reserve(String s){
	s.reserve(10);
	std::cout << "Test reserve()" << std::endl;
	std::cout << "nouvelle capacité : " << s.capacity() << std::endl;
}	
	
void test_equal_operator_char(String s, char letter){
	s = letter;
	std::cout << "Test operator= (char)" << std::endl;
	std::cout << "Nouvelle chaine : " << s.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << s.length() << std::endl;
}

void test_equal_operator_charptr(String s, char* chaine){
	s = chaine;
	std::cout << "Test operator= (char*)" << std::endl;
	std::cout << "Nouvelle chaine : " << s.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << s.length() << std::endl;
}

void test_plus_operator_charptr(String s, char* chaine){
	String str = s + chaine;
	std::cout << "Test operator+ (char*)" << std::endl;
	std::cout << "Nouvelle chaine : " << str.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << str.length() << std::endl;
}

void test_plus_operator_string(String s1, String s2){
	String s3 = s1 + s2;
	std::cout << "Test operator+ (string)" << std::endl;
	std::cout << "Nouvelle chaine : " << s3.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << s3.length() << std::endl;
}

void test_clear(String s){
	std::cout << "Chaîne avant clear :" << s.c_str() << std::endl;
	std::cout << "capacité avant clear :" << s.capacity() << std::endl;
	std::cout << "Taille avant clear :" << s.size() << std::endl;
	s.clear();
	std::cout << "Chaîne après clear :" << s.c_str() << std::endl;
	std::cout << "capacité après clear :" << s.capacity() << std::endl;
	std::cout << "Taille après clear :" << s.size() << std::endl;
}
