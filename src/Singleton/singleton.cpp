#include <iostream>
#include "singleton.h"

using namespace std;


Logging_v1* Logging_v1::_instance=nullptr;


void f(){
	cout << "in func f()" << endl;
	Logging_v1* log = Logging_v1::getInstance();
	log->addText("there :) \n");
	log->show();
}



void test_singleton(){
	Logging_v1* log = Logging_v1::getInstance();
	log->show();

	log->addText("\nHi ");
	f();
	log->show();

}