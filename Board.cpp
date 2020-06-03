#include <iostream>
#include "Board.hpp"
using namespace WarGame;




Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    return this->board[location.first][location.second];
}

Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
    return this->board[location.first][location.second];
}

void WarGame::Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction){
    Soldier *temp = (*this)[source];
    if (temp==nullptr) throw std::invalid_argument("no soldier in this spot");
    if (temp->getPlayer()!=player_number) throw invalid_argument("this soldier does not belong to this player");
    std::pair<int,int> p;
    switch (direction){
    case Up:
        p = std::pair<int,int>(source.first+1,source.second);
        break;
    case Down:
        p = std::pair<int,int>(source.first-1,source.second);
        break;
    case Left:
        p = std::pair<int,int>(source.first,source.second-1);
        break;
    case Right:
        p = std::pair<int,int>(source.first,source.second+1);
        break;
    }
    if ((p.first<0 || this->board.size()<=p.first) || (p.second<0 || this->board[0].size()<=p.second)) 
        throw std::invalid_argument("Error: destenation location is invalid");
    if ((*this)[p]) throw invalid_argument("ERROR: target location already occupeied");
    (*this)[source]=nullptr;
    (*this)[p]=temp;
    std::pair<int,int> size(this->board.size(),this->board[0].size());
    if ((*this)[p]->getCommander()){
        (*this)[p]->command(this->board,size,p);
    }else (*this)[p]->ability(this->board,size,p);
}

bool WarGame::Board::has_soldiers(uint player_number) const{
    for (int i=0;i<this->board.size();i++){
        for (int j=0;j<this->board[0].size();j++){
            if (this->board[i][j]){
                if ((this->board[i][j])->getPlayer()==player_number) return true;
            }
        }
    }
    return false;
}