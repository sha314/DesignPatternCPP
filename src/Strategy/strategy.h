//
// Created by shahnoor on 11/11/19.
//

#ifndef DESIGNPATTERN_STRATEGY_H
#define DESIGNPATTERN_STRATEGY_H

#include <string>

/*************
* Using Strategy Design Pattern

* Why?
	1. No code Duplication
	2. Simplified Approach
	3.
**/


/**********
* Abstruct Fly class
*/
class Fly{
public:
    virtual std::string fly()=0;
};

class CanFly : public Fly{
public:
    std::string fly() {return "I can fly";};
};

class CantFly : public Fly{
public:
    std::string fly() {return "I can't fly";};
};






/******************
 Animal class
***/
class Animal{
protected:
    Fly* flying;
public:
    void tryToFly(){std::cout << flying->fly() << std::endl;};
    void setAbility(Fly *fly){flying = fly;}

};

class Dog: public Animal{

public:
    Dog(){
        flying = new CantFly();
    }

};

class Bird: public Animal{

public:
    Bird(){
        flying = new CanFly();
    }

};



void test_strategy();


#endif //DESIGNPATTERN_STRATEGY_H
