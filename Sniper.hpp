#pragma once 

#include <iostream>
#include "Soldier.hpp"

class Sniper : public Soldier{
  private:
    int damage;
  public:
    Sniper(int player) {this->player=player;this->health=100;}

    //getters & setters
    int getPlayer() {return this->player;}
    int getHealth() {return this->health;}

    //methods
    void ability();
};