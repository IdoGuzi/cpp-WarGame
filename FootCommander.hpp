#pragma once 

#include <iostream>
#include "Soldier.hpp"

class FootCommander : public Soldier{
  private:
    int damage;
  public:
    FootCommander(int player) {this->player=player;this->health=150;}

    //getters & setters
    int getPlayer() {return this->player;}
    int getHealth() {return this->health;}

    //methods
    void ability();
};