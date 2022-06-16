/* Copyright (c) 1998 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     BJackPlayer.cc
   PURPOSE
     
   NOTES
     
   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct. 5, 1998: Created.
***************************************************************************/

/* $Log: BJackPlayer.cc,v $
 * */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
}

using namespace std;
#include <iostream>
#include <string>
#include "AnsiPrint.h"
#include "CardPat.h"
#include "BJackPlayer.h"

// default constructor: simply initialize the number of cards to 0

BJackPlayer::BJackPlayer(const char *player_name) {
	totalP = 0;
	ncards = 0;
	playerN = player_name;
	name_size = playerN.size();
	open = true;
}

// start the black jack game with a new card
void
BJackPlayer::start(void) {

}

// add a new card to the current hand.
// need to protect the array from overflowing
void 
BJackPlayer::addCard(Card newCard) {
	if(newCard.getPip() >= 9) //the points of all J,Q,K cards are 10 points
		totalP += 10;
	else
	   	totalP += newCard.getPip()+1;
	
	pip[ncards] = newCard.getPip();
	if(newCard.getSuit() == 0)
		suit[ncards] = 'S';
	else if(newCard.getSuit() == 1)
		suit[ncards] = 'H';
	else if(newCard.getSuit() == 2)
		suit[ncards] = 'D';
	else if(newCard.getSuit() == 3)
		suit[ncards] = 'C';
	++ncards;
}

// get the total points of the current hand in a black jack game
// cards with face vaules above 10 are treated as 10
// Ace's can be treated as 1 or 11 points

int
BJackPlayer::totalPoints(void) const {
	return totalP;
}

// set the status of the first card

void
BJackPlayer::openFirstCard() {
	open = false; //close the first card
}

// print the current hand to the screen graphically

void 
BJackPlayer::showCards() const {
	char output[12];
	for(int i=0;i<ncards;i+=5){
		int flag = 0;
		for(int k=0;k<11;++k){
			if(flag < name_size){ //print player's name
				cout << playerN[flag] << ' ';
				++flag;
			}
			else{
				cout << "  ";
			}
			for(int j=i;j<i+5;++j){
				if(j >= ncards){
					break;
				}
				if(suit[j]=='S' || suit[j]=='C'){
					//the first and last line did not need to change anything
					if(open == false && j == 0){
						AnsiPrint(card[13][0],black,white,false,false);
					}
					else if(k==0 || k==10){
						AnsiPrint(card[0][0],black,white,false,false);
					}
					else{
						strcpy(output,card[pip[j]][k]);
						for(int l=0;l<11;++l){
							if(output[l] == 'x'){
								output[l] = suit[j];
							}
						}
						AnsiPrint(output,black,white,false,false);
					}
					cout << ' ';
				}
				else if(suit[j]=='H' || suit[j]=='D'){
					//the first and last line did not need to change anything
					if(open == false && j == 0){
						AnsiPrint(card[13][0],red,white,false,false);
					}
					else if(k==0 || k==10){
						AnsiPrint(card[0][0],red,white,false,false);
					}
					else{
						strcpy(output,card[pip[j]][k]);
						for(int l=0;l<11;++l){
							if(output[l] == 'x'){
								output[l] = suit[j];
							}
						}
						AnsiPrint(output,red,white,false,false);
					}
					cout << ' ';
				}
			}
			cout << endl;
		}
		cout << endl;
	} 
}
