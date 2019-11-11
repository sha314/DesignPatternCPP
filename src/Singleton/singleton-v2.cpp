#include <iostream>
#include <fstream>
#include "singleton.h"

using namespace std;


Logging_v2* Logging_v2::_instance=nullptr;

void f_v2(){
	cout << "in func f()" << endl;
	Logging_v2* log = Logging_v2::getInstance();
	log->addText("there :)");
}



void test_singleton_v2(){
	Logging_v2* log = Logging_v2::getInstance();

	log->addText("Hi ");
	log->setFilename("b.txt");
	f();
	log->addText("Last entry ");
}