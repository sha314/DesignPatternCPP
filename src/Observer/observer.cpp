//
// Created by shahnoor on 11/11/19.
//

#include <algorithm>
#include <iostream>
#include "observer.h"

using namespace std;

Observer::Observer(Car *car) {
    car_ = car;
    car_->attach(this);
}

LeftObserver::LeftObserver(Car *car) : Observer(car) {}

void LeftObserver::update() {
    int pos  = get_car()->get_position();
    if(pos < 0){
        cout << "LeftObserver" << endl;
    }

}

RightObserver::RightObserver(Car *car) : Observer(car) {}

void RightObserver::update() {
    int pos  = get_car()->get_position();
    if(pos >= 0){
        cout << "RightObserver" << endl;
    }

}

void Car::set_position(int p) {
    pos = p;
    notify();
}

void Car::dettach(Observer *obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void Car::notify() {
    for(size_t i{}; i < observers.size(); ++i){
        observers[i]->update();
    }

}

void test_observer() {
    Car* car = new Car();
    RightObserver rightObserver(car);
    LeftObserver leftObserver(car);

    int value=0;
    cout << int('q') << endl;
    while(value != int('q')){
        cout << "Enter a value (q to quit) : ";
        cin >> value;
        cout << value << endl;
        cin.clear();
        //        cin.ignore(256, '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        car->set_position(value);
    }
}