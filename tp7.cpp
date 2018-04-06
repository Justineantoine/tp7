#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "String.h"

void test_constructor_cstr();
void test_length();
void test_capacity();
void test_copy_constructor();
void test_to_string();
void test_max_size();
void test_empty();
void test_c_str();
void test_resize();
void test_equal_operator_char();
void test_plus_operator_charptr();

int main(int argc, char* argv[]){
  std::cout << "Hello World !" << std::endl;
	test_constructor_cstr();
	test_length();
	test_capacity();
	test_copy_constructor();
	//test_to_string();
  test_max_size();
  test_empty();
	test_c_str();
	test_resize();
	test_equal_operator_char();
	test_plus_operator_charptr();
  return 0;
}

void test_constructor_cstr(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << &str1 << std::endl;
}

void test_length(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << str1.length() << std::endl;
}

void test_capacity(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << "capacity_ =" << str1.capacity() << std::endl;
}
void test_copy_constructor(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << &str1 << std::endl;
	String str2(str1);
	std::cout << &str2 << std::endl;
}

void test_to_string(){
	char chaine[] = "Bonjour";
	String s(chaine);
	s.to_string();
}

void test_max_size(){
	char chaine[] = "Bonjour";
	String str(chaine);
  std::cout << "max_size = " << str.max_size() << std::endl;
}

void test_empty(){
	char chaine1[] = "Bonjour";
	String str1(chaine1);
	std::cout << "string non vide =" << str1.empty() << std::endl;
	char chaine2[] = "";
	String str2(chaine2);
	std::cout << "string vide =" << str2.empty() << std::endl;
}
void test_c_str(){
	char chaine[] = "Bonjour";
	String str(chaine);
	std::cout << "Test c_str() : " << str.c_str() << std::endl;
}

void test_resize(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	str1.resize(4,'d');
	std::cout << "Test resize avec n < size_" << std::endl;
	std::cout << "Nouvelle taille : " << str1.length() << std::endl;
	std::cout << "Nouvelle chaine : " << str1.c_str() << std::endl;
	String str2(chaine);
	str2.resize(10,'d');
	std::cout << "Test resize avec n > size_" << std::endl;
	std::cout << "Nouvelle taille : " << str2.length() << std::endl;
	std::cout << "Nouvelle chaine : " << str2.c_str() << std::endl;
}

void test_equal_operator_char(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	str1 = 'A';
	std::cout << "Test operator=" << std::endl;
	std::cout << "Nouvelle chaine : " << str1.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << str1.length() << std::endl;
}

void test_plus_operator_charptr(){
	char chaine1[] = "Bonjour";
	char chaine2[] = ", ça va ?";
	String str1(chaine1);
	String str3 = str1 + chaine2;
	std::cout << "Test operator+" << std::endl;
	std::cout << "Nouvelle chaine : " << str3.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << str3.length() << std::endl;
}
