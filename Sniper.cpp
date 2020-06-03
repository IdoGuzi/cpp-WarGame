#include <iostream>
#include <cmath>
#include "Sniper.hpp"

void Sniper::ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    int maxHealth=-999999;
    std::pair<int,int> strongestEnemy(-1,-1);
    for (int i=0;i<size.first;++i){
        for (int j=0;j<size.second;++j){
            if (b[i][j]){
                if (b[i][j]->getPlayer()!=this->getPlayer()){
                    int health = b[i][j]->getHealth();
                    if (maxHealth<health){
                        maxHealth = health;
                        strongestEnemy.first = i;
                        strongestEnemy.second = j;
                    }
                }
            }
        }
    }
    b[strongestEnemy.first][strongestEnemy.second]->setHealth(b[strongestEnemy.first][strongestEnemy.second]->getHealth()-this->getDamage());
    if (b[strongestEnemy.first][strongestEnemy.second]->getHealth()<=0){
        delete b[strongestEnemy.first][strongestEnemy.second];
        b[strongestEnemy.first][strongestEnemy.second] = nullptr;
    }
}

void Sniper::command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    this->ability(b,size,cord);
}