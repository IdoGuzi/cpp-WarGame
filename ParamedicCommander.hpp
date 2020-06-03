#pragma once 

#include <iostream>
#include "Soldier.hpp"
#include "Paramedic.hpp"

class ParamedicCommander : public Paramedic{
  private:
    static const int MAX_HP = 200;
  public:
    ParamedicCommander(int player) : Paramedic() {
      this->player=player;
      this->health=200;
      this->damage=0;
      this->commander=true;
      }

    //getters & setters
    int getPlayer() {return this->player;}
    int getHealth() {return this->health;}
    int getMAXHP() {return this->MAX_HP;}
    int getDamage() {return this->damage;}
    bool getCommander() {return this->commander;}
    string getName() {return "medic";}

    void setHealth(int HP) {this->health=HP;}

    //methods
    void ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
    void command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord);
};