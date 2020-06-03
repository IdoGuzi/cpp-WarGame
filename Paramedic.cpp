#include <iostream>
#include "Paramedic.hpp"

void Paramedic::ability(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    for (int i=-1;i<2;++i){
        for (int j=-1;j<2;++j){
            if (i!=0 || j!=0){
                if ((0<=cord.first+i && cord.first+i<size.first) && (0<=cord.second+j && cord.second+j<size.second)){
                    if (b[cord.first+i][cord.second+j]){
                        if (b[cord.first+i][cord.second+j]->getPlayer()==this->getPlayer()){
                            b[cord.first+i][cord.second+j]->setHealth(b[cord.first+i][cord.second+j]->getMAXHP());
                        }
                    }
                }
            }
        }
    }
}

void Paramedic::command(vector<vector<Soldier*>>& b, std::pair<int,int> size, std::pair<int,int> cord){
    this->ability(b,size,cord);
}