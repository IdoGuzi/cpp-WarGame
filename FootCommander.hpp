#pragma once 

#include <iostream>
#include "Soldier.hpp"
#include "FootSoldier.hpp"

class FootCommander : public FootSoldier{
  private:
    static const int MAX_HP = 150;
  public:
    FootCommander(int player) : FootSoldier() {
      this->player=player;
      this->health=150;
      this->damage=20;
      this->commander=true;
    }

    ~FootCommander(){}

    //getters & setters
    int getPlayer() {return this->player;}
    int getHealth() {return this->health;}
    int getMAXHP() {return this->MAX_HP;}
    int getDamage() {return this->damage;}
    bool getCommander() {return this->commander;}
    string getName() {return FootSoldier::getName();}

    virtual void setHealth(int HP) {this->health=HP;}

    //methods
    void ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
    void command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
};