#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "String.h"

void test_constructor_cstr();
void test_length();
void test_copy_constructor();
void test_to_string();
void test_max_size();
void test_c_str();

int main(int argc, char* argv[]){
  std::cout << "Hello World !" << std::endl;
	test_constructor_cstr();
	test_length();
	test_copy_constructor();
	//test_to_string();
  test_max_size();
	test_c_str();
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

void test_c_str(){
	char chaine[] = "Bonjour";
	String str(chaine);
	std::cout << "Test c_str() : " << str.c_str() << std::endl;
}
