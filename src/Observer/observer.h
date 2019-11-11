//
// Created by shahnoor on 11/11/19.
//

#ifndef DESIGNPATTERN_OBSERVER_H
#define DESIGNPATTERN_OBSERVER_H

#include <vector>

/***
 *
 */
class Car{
    int pos;
    std::vector<class Observer*> observers;

public:

    Car() = default;
    int get_position(){ return pos;}
    void set_position(int p);
    void attach(Observer* obs){observers.emplace_back(obs);}
    void dettach(Observer* obs);
    void notify();

};

class Observer{
    Car* car_;
public:
    explicit Observer(Car* car);
    virtual void update() = 0;

protected:
    Car* get_car(){return car_;}
};

class LeftObserver: public Observer{
public:
    explicit LeftObserver(Car *car);
    void update() override;

};

class RightObserver: public Observer{
public:
    explicit RightObserver(Car *car);
    void update() override;
};



void test_observer();

#endif //DESIGNPATTERN_OBSERVER_H
