#include <iostream>
#include "strategy.h"

using namespace std;



void test_strategy(){
    Animal *d = new Dog();
    d->tryToFly();

    Animal *b = new Bird();
    b->tryToFly();


    d->setAbility(new CanFly());
    d->tryToFly();

}