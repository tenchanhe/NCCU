/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackGame.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "BJackGame.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"

using namespace std;

// only constructor
// Must be given a valid (initialized) game player and dealer
// Menu is constructed internally to provide basic text interface
// We must use an initialization list here.
BJackGame::BJackGame(BJackPlayer &bjp, BJackDealer &bjd) : menu(sizeof(menuItems)/sizeof(char *),menuItems),bjplayer(bjp),bjdealer(bjd){
	
	gameover = true;
	dealercredit = initCredit; //give both side 10 point when game start
	playercredit = initCredit;
}

// one run of the game
// take and process a user action
// show current hands for both players at the end of a run.
bool
BJackGame::oneRun() {
	
	menu.print();
	int select = menu.getAnswer();
	if(select==1){ 
		moreCard();
	}
	else if(select==2){
		enough();
	}
	else if(select==3){ 
		restart();
	}
	else{ //(select==4){ 
		return false;
	}
	return true;
}

// give the player one more card
// check if we can do that first
void 
BJackGame::moreCard() {
	
	if(gameover == true){     //press more card when game over
		cout << "Game Over" << endl;
		bjplayer.showCards();
		bjdealer.showCards();
		return;
	}
	if(bjplayer.totalPoints() < 21){
		Card add(bjdealer.giveCard());
		bjplayer.addCard(add);
	}
	else{
		cout << "You are over 21 already" << endl; 
	}
	bjplayer.showCards();
	bjdealer.showCards();
}

// give the dealer enough cards to try to win the player
// determine who win the game at the end
void 
BJackGame::enough() {

	if(gameover == true){    //press enough when game over
		cout << "Game Over" << endl;
		bjplayer.showCards();
		bjdealer.showCards();
		return;
	}
	
	bjdealer.addCards(bjplayer.totalPoints());  //add dealer's card when player stop adding cards
	
	result Result = bjdealer.judge(bjplayer.totalPoints());
	if(Result == win){
		++dealercredit;
		--playercredit;
		cout << "I win. Try again.(You have " << playercredit << " points, I have "<< dealercredit << "points.)" << endl;
	}
	else if(Result == lose){
		--dealercredit;
		++playercredit;
		cout << "You win. Good job.(You have " << playercredit << "points, I have " << dealercredit << "points.)" << endl;
	}
	else if(Result == tie){
		cout << "It's a Tie.(You have " << playercredit << "points, I have " << dealercredit << "points.)" << endl;
	}
	bjplayer.showCards();
	bjdealer.openFirstCard();  //open fisrt card when game over
	bjdealer.showCards();
	gameover = true;
}

// restart the game by giving each player two new cards
// need to check if any one broke (bankrupt).
void 
BJackGame::restart() {
	
	if(dealercredit==0 || playercredit==0){  //player or dealer lose all the bargaining chip
		cout << "Sorry. Game over. No loan here." << endl;
		bjplayer.showCards();
		bjdealer.showCards();
		return;
	}

	if(gameover == false){  //press restart when game is not end
		cout << "Game is not over yet. Choose 'enough' to end a game" << endl;
		bjplayer.showCards();
		bjdealer.showCards();
		return;
	}	
	gameover = false;

	bjplayer.start();
	bjdealer.start();
	for(int i=0;i<2;++i){
		int Add=bjdealer.giveCard();
		Card add(Add);
		bjplayer.addCard(add);
		bjdealer.addCard();
	}
	bjplayer.showCards();
	bjdealer.showCards();
}

