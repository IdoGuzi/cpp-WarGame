#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
using namespace WarGame;
using namespace std;


Board createGame(int i){
    if (i==0){
        Board b(2,2);
        b[{0,0}] = new FootSoldier(1);
        b[{1,1}] = new FootSoldier(2);
        return b;
    }else if (i==1){
        Board b(3,3);
        b[{0,0}] = new FootSoldier(1);
        b[{1,0}] = new FootCommander(1);
        b[{0,1}] = new FootSoldier(2);
        return b;
    }else if (i==2){
        Board b(4,4);
        b[{0,0}] = new Sniper(1);
        b[{1,0}] = new SniperCommander(1);
        b[{1,3}] = new FootSoldier(2);
        b[{0,3}] = new FootCommander(2);
        return b;
    }else {
        Board b(6,6);
        b[{0,0}] = new Paramedic(1);
        b[{2,0}] = new FootSoldier(1);
        b[{5,0}] = new ParamedicCommander(1);
        b[{3,0}] = new FootSoldier(1);
        b[{2,3}] = new FootSoldier(2);
        b[{3,3}] = new FootSoldier(2);
        return b;
    }
    throw runtime_error("error");
}

TEST_CASE("basic game"){
    Board b=createGame(0);
    CHECK(b.has_soldiers(1)==true);
    CHECK(b.has_soldiers(2)==true);
    Soldier *s=b[{0,0}];
    b.move(1,{0,0},Board::MoveDIR::Up);
    CHECK(s==b[{1,0}]);
    CHECK(b[{1,1}]->getHealth()==90);
    s=b[{1,1}];
    b.move(2,{1,1},Board::MoveDIR::Down);
    CHECK(s==b[{0,1}]);
    CHECK(b[{1,0}]->getHealth()==90);

    s=b[{1,0}];
    b.move(1,{1,0},Board::MoveDIR::Right);
    CHECK(s==b[{1,1}]);
    CHECK(b[{0,1}]->getHealth()==80);
    s=b[{0,1}];
    b.move(2,{0,1},Board::MoveDIR::Left);
    CHECK(s==b[{0,0}]);
    CHECK(b[{1,1}]->getHealth()==80); //10

    s=b[{1,1}];
    b.move(1,{1,1},Board::MoveDIR::Down);
    CHECK(s==b[{0,1}]);
    CHECK(b[{0,0}]->getHealth()==70);
    s=b[{0,0}];
    b.move(2,{0,0},Board::MoveDIR::Up);
    CHECK(s==b[{1,0}]);
    CHECK(b[{0,1}]->getHealth()==70);

    s=b[{0,1}];
    b.move(1,{0,1},Board::MoveDIR::Left);
    CHECK(s==b[{0,0}]);
    CHECK(b[{1,0}]->getHealth()==60);
    s=b[{1,0}];
    b.move(2,{1,0},Board::MoveDIR::Right);
    CHECK(s==b[{1,1}]);
    CHECK(b[{0,0}]->getHealth()==60);

    CHECK(b.has_soldiers(1)==true);
    CHECK(b.has_soldiers(2)==true); //20
    s=b[{0,0}];
    b.move(1,{0,0},Board::MoveDIR::Up);
    CHECK(s==b[{1,0}]);
    CHECK(b[{1,1}]->getHealth()==50);
    s=b[{1,1}];
    b.move(2,{1,1},Board::MoveDIR::Down);
    CHECK(s==b[{0,1}]);
    CHECK(b[{1,0}]->getHealth()==50);
    
    s=b[{1,0}];
    b.move(1,{1,0},Board::MoveDIR::Right);
    CHECK(s==b[{1,1}]);
    CHECK(b[{0,1}]->getHealth()==40);
    s=b[{0,1}];
    b.move(2,{0,1},Board::MoveDIR::Left);
    CHECK(s==b[{0,0}]);
    CHECK(b[{1,1}]->getHealth()==40);

    s=b[{1,1}];
    b.move(1,{1,1},Board::MoveDIR::Down);
    CHECK(s==b[{0,1}]);
    CHECK(b[{0,0}]->getHealth()==30); //30
    s=b[{0,0}];
    b.move(2,{0,0},Board::MoveDIR::Up);
    CHECK(s==b[{1,0}]);
    CHECK(b[{0,1}]->getHealth()==30);

    s=b[{0,1}];
    b.move(1,{0,1},Board::MoveDIR::Left);
    CHECK(s==b[{0,0}]);
    CHECK(b[{1,0}]->getHealth()==20);
    s=b[{1,0}];
    b.move(2,{1,0},Board::MoveDIR::Right);
    CHECK(s==b[{1,1}]);
    CHECK(b[{0,0}]->getHealth()==20);

    CHECK(b.has_soldiers(1)==true);
    CHECK(b.has_soldiers(2)==true);
    s=b[{0,0}];
    b.move(1,{0,0},Board::MoveDIR::Up);
    CHECK(s==b[{1,0}]);
    CHECK(b[{1,1}]->getHealth()==10); //40
    s=b[{1,1}];
    b.move(2,{1,1},Board::MoveDIR::Down);
    CHECK(s==b[{0,1}]);
    CHECK(b[{1,0}]->getHealth()==10);
    
    s=b[{1,0}];
    b.move(1,{1,0},Board::MoveDIR::Right);
    CHECK(s==b[{1,1}]);
    CHECK(b[{0,1}]==nullptr);
    CHECK(b.has_soldiers(2)==false);
    CHECK(b.has_soldiers(1)==true);
    for (int iRow=0; iRow<2; ++iRow) {
		for (int iCol=0; iCol<2; ++iCol) {
			Soldier* soldier = b[{iRow,iCol}];
			if (soldier)
				delete soldier;
		}
	}
}

TEST_CASE("throws"){
    Board b = createGame(0);
    CHECK_THROWS(b.move(1,{1,1},Board::MoveDIR::Down)); //soldier in {1,1} belong to player 2
    CHECK_THROWS(b.move(2,{1,1},Board::MoveDIR::Up)); //moving up will be outside the board
    CHECK_THROWS(b.move(1,{0,1},Board::MoveDIR::Up)); //no soldier in {0,1}
    b.move(1,{0,0},Board::MoveDIR::Up);
    CHECK_THROWS(b.move(1,{1,0},Board::MoveDIR::Right)); //{1,1} is already occupied with p2 soldier
    CHECK(!b.has_soldiers(0));
    CHECK(!b.has_soldiers(-1));
    CHECK(!b.has_soldiers(3));
    for (int iRow=0; iRow<2; ++iRow) {
		for (int iCol=0; iCol<2; ++iCol) {
			Soldier* soldier = b[{iRow,iCol}];
			if (soldier)
				delete soldier;
		}
	}
}

TEST_CASE("commander"){
    Board b=createGame(1);
    CHECK(b.has_soldiers(1));
    CHECK(b.has_soldiers(2));
    CHECK_NOTHROW(b.move(1,{1,0},Board::MoveDIR::Right));
    CHECK(b[{0,1}]->getHealth()==70);
    CHECK_NOTHROW(b.move(2,{0,1},Board::MoveDIR::Right));
    CHECK(b[{1,1}]->getHealth()==140);
    CHECK_NOTHROW(b.move(1,{1,1},Board::MoveDIR::Right));
    CHECK(b[{0,2}]->getHealth()==40);
    CHECK_NOTHROW(b.move(2,{0,2},Board::MoveDIR::Left));
    CHECK((b[{1,2}]->getHealth()==130 || b[{0,0}]->getHealth()==90));
    CHECK_NOTHROW(b.move(1,{1,2},Board::MoveDIR::Left));
    CHECK(b[{0,1}]->getHealth()==10); //60
    CHECK_NOTHROW(b.move(2,{0,1},Board::MoveDIR::Right));
    CHECK(b[{1,1}]->getHealth()==130);
    CHECK(b.has_soldiers(2)==true);
    CHECK_NOTHROW(b.move(1,{1,1},Board::MoveDIR::Right));
    CHECK(b.has_soldiers(2)==false);
    for (int iRow=0; iRow<3; ++iRow) {
		for (int iCol=0; iCol<3; ++iCol) {
			Soldier* soldier = b[{iRow,iCol}];
			if (soldier)
				delete soldier;
		}
	}
}

TEST_CASE("sniper && sniper commander"){
    Board b = createGame(2);
    CHECK(b.has_soldiers(1));
    CHECK(b.has_soldiers(2));
    CHECK_NOTHROW(b.move(1,{1,0},Board::MoveDIR::Up));
    CHECK(b[{0,3}]==nullptr);
    CHECK_NOTHROW(b.move(2,{1,3},Board::MoveDIR::Left));
    CHECK_NOTHROW(b.move(1,{0,0},Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(2,{1,2},Board::MoveDIR::Down));
    CHECK(b[{0,2}]->getHealth()==50);
    CHECK_NOTHROW(b.move(2,{0,2},Board::MoveDIR::Left)); //player 2 moved twice (for the test),may cause problems
    CHECK(b[{1,0}]->getHealth()==70);
    CHECK(b.has_soldiers(1));
    CHECK(b.has_soldiers(2));
    CHECK_NOTHROW(b.move(1,{1,0},Board::MoveDIR::Down));
    CHECK(!b.has_soldiers(2));
    CHECK(b.has_soldiers(1));
    for (int iRow=0; iRow<4; ++iRow) {
		for (int iCol=0; iCol<4; ++iCol) {
			Soldier* soldier = b[{iRow,iCol}];
			if (soldier)
				delete soldier;
		}
	}
}

TEST_CASE("paramedic & paramdicCommander"){
    Board b = createGame(3);
    CHECK(b.has_soldiers(1));
    CHECK(b.has_soldiers(2));
    CHECK_NOTHROW(b.move(1,{2,0},Board::MoveDIR::Right));
    CHECK(b[{2,3}]->getHealth()==90);
    CHECK_NOTHROW(b.move(2,{2,3},Board::MoveDIR::Left));
    CHECK(b[{2,1}]->getHealth()==90);
    CHECK_NOTHROW(b.move(1,{2,1},Board::MoveDIR::Left));
    CHECK(b[{2,2}]->getHealth()==80);
    CHECK_NOTHROW(b.move(2,{2,2},Board::MoveDIR::Right));
    CHECK_NOTHROW(b.move(1,{0,0},Board::MoveDIR::Up));
    CHECK(b[{2,0}]->getHealth()==100);
    CHECK_NOTHROW(b.move(1,{2,0},Board::MoveDIR::Right));
    CHECK(b[{2,3}]->getHealth()==70);
    CHECK_NOTHROW(b.move(2,{2,3},Board::MoveDIR::Left));
    CHECK(b[{2,1}]->getHealth()==90);
    CHECK_NOTHROW(b.move(1,{2,1},Board::MoveDIR::Left));
    CHECK(b[{2,2}]->getHealth()==60);
    CHECK_NOTHROW(b.move(2,{2,2},Board::MoveDIR::Right));
    CHECK(b[{2,0}]->getHealth()==80);
    CHECK_NOTHROW(b.move(1,{3,0},Board::MoveDIR::Right));
    CHECK(b[{3,3}]->getHealth()==90);
    CHECK_NOTHROW(b.move(2,{3,3},Board::MoveDIR::Left));
    CHECK(b[{3,1}]->getHealth()==90);
    CHECK_NOTHROW(b.move(1,{3,1},Board::MoveDIR::Left));
    CHECK_NOTHROW(b.move(2,{3,2},Board::MoveDIR::Right));
    CHECK_NOTHROW(b.move(1,{5,0},Board::MoveDIR::Down));
    CHECK((b[{2,0}]->getHealth()==100 && b[{3,0}]->getHealth()==100));
    CHECK_NOTHROW(b.move(1,{2,0},Board::MoveDIR::Right));
    CHECK(b[{2,1}]->getHealth()==100);
    CHECK_NOTHROW(b.move(2,{2,3},Board::MoveDIR::Left));
    CHECK(b[{2,1}]->getHealth()==90);
    CHECK_NOTHROW(b.move(1,{2,1},Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(2,{2,2},Board::MoveDIR::Right));
    //player 2 doing second move (for the test), may cause problem later
    CHECK_NOTHROW(b.move(2,{2,3},Board::MoveDIR::Right));
    CHECK_NOTHROW(b.move(1,{3,1},Board::MoveDIR::Right));
    CHECK(b[{3,3}]->getHealth()==70);
    CHECK_NOTHROW(b.move(2,{3,3},Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(1,{3,2},Board::MoveDIR::Up));
    CHECK(b[{4,3}]->getHealth()==60);
    CHECK_NOTHROW(b.move(2,{4,3},Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(1,{4,2},Board::MoveDIR::Up));
    CHECK(b[{5,3}]->getHealth()==50);
    CHECK_THROWS(b.move(2,{5,3},Board::MoveDIR::Up));
    CHECK_THROWS(b.move(1,{5,2},Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(2,{5,3},Board::MoveDIR::Down));
    CHECK_NOTHROW(b.move(1,{5,2},Board::MoveDIR::Down));
    CHECK(b[{4,3}]->getHealth()==40);
    CHECK_NOTHROW(b.move(2,{4,3},Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(1,{4,2},Board::MoveDIR::Up));
    CHECK(b[{5,3}]->getHealth()==30);
    CHECK_NOTHROW(b.move(2,{5,3},Board::MoveDIR::Down));
    CHECK_NOTHROW(b.move(1,{5,2},Board::MoveDIR::Down));
    CHECK(b[{4,3}]->getHealth()==20);
    CHECK_NOTHROW(b.move(2,{4,3},Board::MoveDIR::Up));
    CHECK_NOTHROW(b.move(1,{4,2},Board::MoveDIR::Up));
    CHECK(b[{5,3}]->getHealth()==10);
    CHECK_NOTHROW(b.move(2,{5,3},Board::MoveDIR::Down));
    CHECK(b[{5,2}]==nullptr);
    CHECK_NOTHROW(b.move(1,{3,0},Board::MoveDIR::Right));
    CHECK(b[{4,3}]==nullptr);
    CHECK_NOTHROW(b.move(1,{3,1},Board::MoveDIR::Down)); //player 1 playing twice
    CHECK(b[{2,4}]->getHealth()==30);
    CHECK_NOTHROW(b.move(2,{2,4},Board::MoveDIR::Left));
    CHECK(b[{2,1}]->getHealth()==90);
    CHECK_NOTHROW(b.move(1,{2,1},Board::MoveDIR::Right));
    CHECK(b[{2,3}]->getHealth()==20);
    CHECK_NOTHROW(b.move(2,{2,3},Board::MoveDIR::Right));
    CHECK(b[{2,2}]->getHealth()==80);
    CHECK_NOTHROW(b.move(1,{2,2},Board::MoveDIR::Left));
    CHECK(b[{2,4}]->getHealth()==10);
    CHECK_NOTHROW(b.move(2,{2,4},Board::MoveDIR::Left));
    CHECK(b[{2,1}]->getHealth()==70);
    CHECK(b.has_soldiers(2));
    CHECK_NOTHROW(b.move(1,{2,1},Board::MoveDIR::Down));
    CHECK(b[{2,3}]==nullptr);
    CHECK(!b.has_soldiers(2));
    CHECK(b.has_soldiers(1));
    for (int iRow=0; iRow<6; ++iRow) {
		for (int iCol=0; iCol<6; ++iCol) {
			Soldier* soldier = b[{iRow,iCol}];
			if (soldier)
				delete soldier;
		}
	}
}