/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackDealer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 12, 1998: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;
#include <assert.h>
#include <iostream>
#include "AnsiPrint.h"
#include "Card.h"
#include "CardPat.h"
#include "BJackPlayer.h"
#include "BJackDealer.h"
#include <algorithm>

// constructor 
// nDeck is the number of standard decks that the dealer will deal with
BJackDealer::BJackDealer(int nSet) {

	strcpy(name,"Dealer");
	nset = nSet;
	maxcards = nSet*52;
	nCards = 0;
	cardsleft = maxcards;
	totalpoints = 0;
	showAll = false;
	cardsonhand = new int[maxcards]; //cards ready to be give

	int flag[52]={0},tmp;
	for(int i=0;i<maxcards;++i){ //put 0~51 randomly to cards on hand
		tmp = rand() % 52;
		if(flag[tmp] < nset){
			cardsonhand[i] = tmp;
		}
		else{
			--i;
		}
	}
}

// distribute a card to the player
int
BJackDealer::giveCard() {

	if(cardsleft > nset*17){	//check whether cardsleft enough to be give
		--cardsleft;
		return cardsonhand[cardsleft-1];
	}
	else{
		shuffle(); //shuffle when cards did not enough
	}
	return 0;
}

// give the dealer one card unconditionally
void 
BJackDealer::addCard() {

	if(nCards < 10){
		Card add(giveCard());
		cards[nCards] = add;
		++nCards;
	}
	else{
		cout << "Error: Exceed the maximal number of cards a player can have." << endl;
	}
}

// give the dealer as many cards as necessary to exceed the player 
// of the given total points
// A special case happen when both of them have 21 points.
// It is a tie game and therefore the dealer does not get more cards.

void
BJackDealer::addCards(int oppTotal) {
	
	int point;
	int credit=0;

	totalpoints=0;
	//check dealer's total points
	for(int i=0;i<nCards;++i){
		point=cards[i].getPip()+1;
		if(point==1){
			credit++;
		}
		else if(point>10){
			point = 10;
		}
		totalpoints += point;
	}

	for(int i=0;i<credit;++i){
		if(totalpoints+10 <= 21){
			totalpoints += 10;
		}
		else{
			break;
		}
	}
	
	//check if addcards have to stop
	if(totalpoints == 21){
		return;
	}
	if(oppTotal<=21 && totalpoints>oppTotal){
		return;
	}
	if(oppTotal>21 && totalpoints>17){
		return;
	}
	//continue add card if cards did not enough
	addCard();
	addCards(oppTotal);
}

// Determine who has win the game.
// The total points that the dealer has should be greater than 
// the player at the point this function is called.

result
BJackDealer::judge(int oppTotal) const {
	
	if(totalpoints>21 && oppTotal>21){ //both side over 21points
		return tie;
	}	   
	else if(totalpoints == oppTotal){ //both side equal points
		return tie;
	}
	else if(totalpoints>21 && oppTotal<=21){ //dealer over 21 player under 21
		return lose;
	}
	else if(totalpoints<=21 && oppTotal>21){ //dealer under 21 player over 21
		return win;
	}
	else if(totalpoints > oppTotal){ //dealer's points bigger than player
		return win;
	}
	else if(totalpoints < oppTotal){ //dealer's points lower than player
		return lose;
	}
	return win;
}

// start a new game
// before starting a new game, check if there are enough cards left for 
// the next game.

void
BJackDealer::start(void) {
	
	nCards = 0;
	showAll = false;
	if(cardsleft < nset*17){ //check cardsleft
		shuffle();
	}
}

// shuffle the deck of cards
void 
BJackDealer::shuffle(void) {

	cardsleft = maxcards;
	int flag[52]={0},tmp;
	for(int i=0;i<maxcards;++i){
		tmp = rand() % 52;
		if(flag[tmp] < nset){
			cardsonhand[i] = tmp;
		}
		else{
			--i;
		}
	}
}

// reset the seed before shuffling
void
BJackDealer::shuffle(long seed) {

	srand(seed); //include seed
	shuffle();
}

// open the dealer's first card 
void 
BJackDealer::openFirstCard(void) {
	
	showAll=true;
}

// show the dealer's hand to the screen
void 
BJackDealer::showCards(void) const {
	unsigned char s,p;
	char line[kCardWidth+1];
	int curCard=0, lastCard;

	while(curCard < nCards) {
		for(int i=0;i<kCardHeight;i++) {
			lastCard = min(curCard+kNCardPerRow, nCards);
			if (i < (int)strlen(name)) {
				cout << name[i] << " ";
			} else {
				cout << "  ";
			}
			for(int j=curCard;j<lastCard;j++) {
				s=cards[j].getID()%kNSuit;
				p=cards[j].getID()/kNSuit;
				if ((j==0)&&(showAll==false)) 
					p=13;
				for(int k=0;k<kCardWidth;k++) {
					line[k]=card[p][i][k];
					if (line[k]=='x') 
						line[k]=cardAbbrev[s];
				}
				line[kCardWidth]='\0';
				AnsiPrint(line,cardColor[s],white);
				cout << " ";
			}
			cout << endl;
		}
		curCard=lastCard;
	}
}

