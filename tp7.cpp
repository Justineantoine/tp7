#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "String.h"

void test_constructor_cstr();
void test_length();


int main(int argc, char* argv[]){
  std::cout << "Hello World !" << std::endl;
	test_constructor_cstr();
	test_length();
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
