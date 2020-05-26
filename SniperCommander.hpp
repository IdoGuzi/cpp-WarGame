#pragma once 

#include <iostream>
#include "Soldier.hpp"

class SniperCommander : public Soldier{
  private:
    int damage;
  public:
    SniperCommander(int player) {this->player=player;this->health=120;}

    //getters & setters
    int getPlayer() {return this->player;}
    int getHealth() {return this->health;}

    //methods
    void ability();
};