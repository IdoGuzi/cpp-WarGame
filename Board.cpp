#include <iostream>
#include "Board.hpp"
using namespace WarGame;




Soldier*& Board::operator[](std::pair<int,int> location){
    return this->board[location.first][location.second];
}

Soldier* Board::operator[](std::pair<int,int> location) const{
    return this->board[location.first][location.second];
}

void Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction){
    Soldier *temp = (*this)[source];
    std::pair<int,int> p;
    if (direction==Up) p = std::pair<int,int>(source.first+1,source.second);
    if (direction==Down) p = std::pair<int,int>(source.first-1,source.second);
    if (direction==Left) p = std::pair<int,int>(source.first,source.second-1);
    if (direction==Right) p = std::pair<int,int>(source.first,source.second+1);
    if (temp==nullptr) throw std::invalid_argument("no soldier in this spot");
    if ((p.first<0 || this->board.size()<=p.first) || (p.second<0 || this->board[0].size()<=p.second)) 
        throw std::invalid_argument("Error: destenation location is invalid");
    (*this)[source]=nullptr;
    (*this)[p]=temp;
    (*this)[p]->ability();
}

bool Board::has_soldiers(uint player_number) const{
    for (int i=0;i<this->board.size();i++){
        for (int j=0;j<this->board[0].size();j++){
            if (this->board[i][j]){
                if ((this->board[i][j])->getPlayer()==player_number) return true;
            }
        }
    }
    return false;
}