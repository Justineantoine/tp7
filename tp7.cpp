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
void test_equal_operator_string(String s1, String s2);
void test_plus_operator_charptr(String s, char* chaine);
void test_plus_operator_string(String s1, String s2);
void test_plus_operator_char(String s, char c);
void test_clear(String s);
void see_cedillia();


int main(int argc, char* argv[]){
	std::cout << "Hello World !" << std::endl;
	test_constructor_cstr();
	test_copy_constructor(); //on vérifie les constructeurs

	/* CONSTRUCTION DE STRING POUR LES TESTS */
	char chaine1[] = "Bonjour l'ami";
	String str1(chaine1);
	char vide[] = "";
	String strvide(vide);
	char chaine2[] = "Hello";
	char chaine3[] = ", ça va ?"; //Apparemment le ç compte pour 2 caractères.
	String str2(chaine3);


	/*DECOMMENTER LES METHODES POUR VOIR LEUR APPLICATION*/

	//test_length(str1);
	//test_capacity(str1);
  //test_max_size(str1);
  //test_empty(str1, strvide);
	//test_c_str(str1);
	//test_resize(str1, str1);
	//test_reserve(str1);
	//test_equal_operator_char(str1, 'A');
	//test_equal_operator_charptr(str1, chaine2);
	//test_equal_operator_string(str1, str2);
	//test_plus_operator_charptr(str1, chaine3);
	//test_plus_operator_string(str1, str2);
	//test_plus_operator_char(str1, 'e');
	//test_clear(str1);
	//see_cedillia();


	return 0;
}

void test_constructor_cstr(){
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << "Test constructor from c-string =" << std::endl;
	std::cout << &str1 << std::endl;
}

void test_copy_constructor(){
  printf("\n");
  std::cout << "Test copy constructor" << std::endl;
	char chaine[] = "Bonjour";
	String str1(chaine);
	std::cout << &str1 << std::endl;
	String str2(str1);
	std::cout << &str2 << std::endl;
}

void test_length(const String& s){
	printf("\n");
	std::cout << "Test getter length()" << std::endl;
	std::cout << s.length() << std::endl;
}

void test_capacity(const String& s){
	printf("\n");
	std::cout << "Test getter capacity()" << std::endl;
	std::cout << s.capacity() << std::endl;
}


void test_max_size(const String& s){
  printf("\n");
  std::cout << "Test getter max_size()" << std::endl;
  std::cout << s.max_size() << std::endl;
}

void test_empty(const String& s1, const String& s2){
	printf("\n");
	std::cout << "Test boolean empty()" << std::endl;
	std::cout << "string non vide =" << s1.empty() << std::endl;
	std::cout << "string vide =" << s2.empty() << std::endl;
}
void test_c_str(const String& s){
	printf("\n");
	std::cout << "Test getter c_str() : " << std::endl;
	std::cout << s.c_str() << std::endl;
}

void test_resize(String s1, String s2){
	printf("\n");
	s1.resize(4,'d');
	std::cout << "Test resize() avec n < size_" << std::endl;
	std::cout << "Nouvelle taille : " << s1.length() << std::endl;
	std::cout << "Nouvelle chaine : " << s1.c_str() << std::endl;

	printf("\n");
	s2.resize(18,'d');
	std::cout << "Test resize() avec n > size_" << std::endl;
	std::cout << "Nouvelle taille : " << s2.length() << std::endl;
	std::cout << "Nouvelle chaine : " << s2.c_str() << std::endl;
}

void test_reserve(String s){
	printf("\n");
	std::cout << "Test reserve()" << std::endl;
	std::cout << "capacité : " << s.capacity() << std::endl;
	s.reserve(18);
	std::cout << "nouvelle capacité : " << s.capacity() << std::endl;
}	
	
void test_equal_operator_char(String s, char letter){
	printf("\n");
	s = letter;
	std::cout << "Test operator= (char)" << std::endl;
	std::cout << "Nouvelle chaine : " << s.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << s.length() << std::endl;
}

void test_equal_operator_charptr(String s, char* chaine){
	printf("\n");
	s = chaine;
	std::cout << "Test operator= (char*)" << std::endl;
	std::cout << "Nouvelle chaine : " << s.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << s.length() << std::endl;
}

void test_equal_operator_string(String s1, String s2){
	printf("\n");
	std::cout << "Test operator= (String)" << std::endl;
	std::cout << "Taille s1 : " << s1.size() << std::endl;
	std::cout << "Taille s2 : " << s2.size() << std::endl;
	std::cout << "Chaîne s1: " << s1.c_str() << std::endl;
	s1 = s2;
	std::cout << "Nouvelle chaine s1: " << s1.c_str() << std::endl;
	std::cout << "Nouvelle taille s1: " << s1.size() << std::endl;
}

void test_plus_operator_charptr(String s, char* chaine){
	printf("\n");
	String str = s + chaine;
	std::cout << "Test operator+ (char*)" << std::endl;
	std::cout << "Nouvelle chaine : " << str.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << str.length() << std::endl;
}

void test_plus_operator_string(String s1, String s2){
	printf("\n");
	String s3 = s1 + s2;
	std::cout << "Test operator+ (string)" << std::endl;
	std::cout << "Nouvelle chaine : " << s3.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << s3.length() << std::endl;
}

void test_plus_operator_char(String s, char c){
	printf("\n");
	std::cout << "Test operator+ (char)" << std::endl;
	std::cout << "Chaîne : " << s.c_str() << std::endl;
	std::cout << "Taille : " << s.length() << std::endl;
	String new_s = s+c;
	std::cout << "Nouvelle chaine : " << new_s.c_str() << std::endl;
	std::cout << "Nouvelle taille : " << new_s.length() << std::endl;
}

void test_clear(String s){
	printf("\n");
	std::cout << "Chaîne avant clear :" << s.c_str() << std::endl;
	std::cout << "capacité avant clear :" << s.capacity() << std::endl;
	std::cout << "Taille avant clear :" << s.size() << std::endl;
	std::cout << "Vide ? " << s.empty() << std::endl;
	s.clear();
	std::cout << "Chaîne après clear :" << s.c_str() << std::endl;
	std::cout << "capacité après clear :" << s.capacity() << std::endl;
	std::cout << "Taille après clear :" << s.size() << std::endl;
	std::cout << "Vide ? " << s.empty() << std::endl;
}

void see_cedillia(){
	printf("\n");
	char chaine[] = "ç";
	String s(chaine);
	size_t size = s.size();
	std::cout<<"Code ASCII de la chaîne 'ç' :"<<std::endl;
	for(int i=0;i<size;++i){
		std::cout<<int(chaine[i])<<std::endl;//Il y a bien deux caractères
	}
}
