#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "String.h"

void test_constructor_cstr();


int main(int argc, char* argv[]){
  std::cout << "Hello World !" << std::endl;
	test_constructor_cstr();
  return 0;
}

void test_constructor_cstr(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << &str1 << std::endl;
}
