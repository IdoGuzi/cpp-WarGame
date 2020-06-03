#pragma once 

#include <iostream>
#include "Soldier.hpp"

class FootSoldier : public Soldier{
  private:
    static const int MAX_HP = 100;
  protected:
  public:
    FootSoldier() {}
    FootSoldier(int player) {
      this->player=player;
      this->health=100;
      this->damage=10;
      this->commander=false;
    }
    ~FootSoldier() {}

    //getters & setters
    virtual int getPlayer() {return this->player;}
    virtual int getHealth() {return this->health;}
    virtual int getMAXHP() {return this->MAX_HP;}
    virtual int getDamage() {return this->damage;}
    virtual bool getCommander() {return this->commander;}
    virtual string getName() {return "foot";}

    virtual void setHealth(int HP) {this->health=HP;}

    //methods
    virtual void ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
    virtual void command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);

};