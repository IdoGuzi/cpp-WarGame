#include <iostream>
#include <cmath>
#include "FootCommander.hpp"


void FootCommander::ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    FootSoldier::ability(b,size,cord);
}


void FootCommander::command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    for (int i=0;i<size.first;++i){
        for (int j=0;j<size.second;++j){
            if (b[i][j]){
                if (b[i][j]->getPlayer()==this->getPlayer()){
                    if (b[i][j]->getName()==this->getName()) {
                        b[i][j]->ability(b,size,{i,j});
                    }
                }
            }
        }
    }
}