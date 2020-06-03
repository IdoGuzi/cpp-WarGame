#include <iostream>
#include <cmath>
#include "FootSoldier.hpp"

void FootSoldier::ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    double minDis=INFINITY;
    std::pair<int,int> closestEnemy(-1,-1);
    for (int i=0;i<size.first;++i){
        for (int j=0;j<size.second;++j){
            if (b[i][j]){
                if (b[i][j]->getPlayer()!=this->getPlayer()){
                    double dist = sqrt(pow(cord.first-i,2)+pow(cord.second-j,2));
                    if (dist<minDis){
                        minDis = dist;
                        closestEnemy.first = i;
                        closestEnemy.second = j;
                    }
                }
            }
        }
    }
    if (closestEnemy.first<0 || closestEnemy.second<0) return; // no target found (after this a player should be declared as winner).
    b[closestEnemy.first][closestEnemy.second]->setHealth(b[closestEnemy.first][closestEnemy.second]->getHealth()-this->damage);
    if (!(b[closestEnemy.first][closestEnemy.second]->getHealth()>0)) {
        delete b[closestEnemy.first][closestEnemy.second];
        b[closestEnemy.first][closestEnemy.second] = nullptr;
    }
}

void FootSoldier::command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    this->ability(b,size,cord);
}