//
// Created by shahnoor on 11/11/19.
//

#ifndef DESIGNPATTERN_SINGLETON_H
#define DESIGNPATTERN_SINGLETON_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

/**
 Only one instance of Logging class is allowed. No new instance can be created.
 Whenever it is called all the previous changes will be present.
 Use :
 	Database integration.
 	Saving configuration or setting.
 	Logging data.
*/
class Logging_v1{
    static Logging_v1* _instance;
    std::string _filename;
    std::string _text;

    Logging_v1(){
        _filename="a.txt";
        _text="Hello world";
    }

public:
    static Logging_v1* getInstance(){
        if (_instance == nullptr){
            _instance = new Logging_v1();
        }
        return _instance;
    }

    void setFilename(std::string filename){
        _filename=filename;
    }
    void addText(std::string text){
        _text += text;
    }
    void show(){
        std::cout << _filename << std::endl;
        std::cout << _text << std::endl;
    }

};

/**
 Only one instance of Logging class is allowed. No new instance can be created.
 Whenever it is called all the previous changes will be present.
 Use :
 	Database integration.
 	Saving configuration or setting.
 	Logging data.
*/
class Logging_v2{
    static Logging_v2* _instance;
    std::string _filename;
    std::ofstream _fout;
    char _delimiter = '\t';

    Logging_v2(){
        _filename="a.txt";
        _fout.open(_filename);
    }

public:
    static Logging_v2* getInstance(){
        if (_instance == nullptr){
            _instance = new Logging_v2();
        }
        return _instance;
    }

    void setFilename(std::string filename){
        _filename= std::move(filename);
        _fout.close();
        _fout.open(_filename);
    }
    void setDelimiter(char delimiter){
        _delimiter = delimiter;
    }

    void addText(const std::string &text){
        _fout << text << std::endl;
    }

    void addText(double value){
        _fout << value << std::endl;
    }

    void addText(const std::vector<double>& values){
        for(auto a: values){
            _fout << a << _delimiter;
        }
        _fout << std::endl;
    }

    void addText(const std::vector<std::string>& values){
        for(auto a: values){
            _fout << a << _delimiter;
        }
        _fout << std::endl;
    }


};

/***
 Without this line program will not compile.
*/
//Logging_v1* Logging_v1::_instance=nullptr;
//Logging_v2* Logging_v2::_instance=nullptr;


void f();
void test_singleton();

void f_v2();
void test_singleton_v2();

#endif //DESIGNPATTERN_SINGLETON_H
