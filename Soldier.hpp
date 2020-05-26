#pragma once

#include <iostream>

class Soldier{
  protected:
    int player;
    int health;
  public:
    virtual ~Soldier() {}
    //get & set
    virtual int getPlayer() = 0;
    virtual int getHealth() = 0;

    //methods
    virtual void ability() =0;
};