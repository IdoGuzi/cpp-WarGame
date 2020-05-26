#pragma once 

#include <iostream>
#include "Soldier.hpp"

class ParamedicCommander : public Soldier{
  private:
    int damage;
  public:
    ParamedicCommander(int player) {this->player=player;this->health=200;}

    //getters & setters
    int getPlayer() {return this->player;}
    int getHealth() {return this->health;}

    //methods
    void ability();
};