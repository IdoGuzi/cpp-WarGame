#pragma once 

#include <iostream>
#include "Soldier.hpp"
#include "Sniper.hpp"

class SniperCommander : public Sniper{
  private:
    static const int MAX_HP = 120;
  public:
    SniperCommander(int player) {
      this->player=player;
      this->health=120;
      this->damage=100;
      this->commander=true;
    }

    //getters & setters
    int getPlayer() {return this->player;}
    int getHealth() {return this->health;}
    int getMAXHP() {return this->MAX_HP;}
    int getDamage() {return this->damage;}
    bool getCommander() {return this->commander;}
    string getName() {return Sniper::getName();}

    void setHealth(int HP) {this->health=HP;}

    //methods
    void ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
    void command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
};