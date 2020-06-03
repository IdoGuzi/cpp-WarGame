#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Soldier{
  protected:
    int player,health,damage;
    bool commander;
  public:
    virtual ~Soldier() {}
    //get & set
    virtual int getPlayer() = 0;
    virtual int getHealth() = 0;
    virtual int getMAXHP() = 0;
    virtual int getDamage() = 0;
    virtual bool getCommander() = 0;
    virtual string getName() = 0;

    virtual void setHealth(int HP) = 0;

    //methods
    virtual void ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord) = 0;
    virtual void command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord) = 0;
};