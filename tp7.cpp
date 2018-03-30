#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "String.h"

void test_constructor_cstr();
void test_length();
void test_copy_constructor();

int main(int argc, char* argv[]){
  std::cout << "Hello World !" << std::endl;
	//test_constructor_cstr();
	test_length();
	test_copy_constructor();
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

