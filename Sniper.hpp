#pragma once 

#include <iostream>
#include "Soldier.hpp"
#include "Board.hpp"

class Sniper : public Soldier{
  private:
    static const int MAX_HP = 100;
  public:
    Sniper() {}
    Sniper(int player) {
      this->player=player;
      this->health=100;
      this->damage=50;
      this->commander=false;
    }
    ~Sniper(){}

    //getters & setters
    virtual int getPlayer() {return this->player;}
    virtual int getHealth() {return this->health;}
    virtual int getMAXHP() {return this->MAX_HP;}
    virtual int getDamage() {return this->damage;}
    virtual bool getCommander() {return this->commander;}
    virtual string getName() {return "sniper";}

    virtual void setHealth(int HP) {this->health=HP;}

    //methods
    virtual void ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
    virtual void command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
};