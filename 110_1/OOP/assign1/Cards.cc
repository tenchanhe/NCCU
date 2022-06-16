/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     Cards.cc
   NOTE
     You are asked to design this module.
     You need to draw the given number of cards and print them out.
     Assume that you are given a deck of 52 cards. The cards do not reappear.
     That is, you do not put a card back into the deck after it is drawn.
***************************************************************************/

//turn the random number to following pip
int findPip(int num){
	return ((num-1)/4);
}

//turn the random number to following suit
char findSuit(int num){
	if(num%4 == 1)
		return 'S';
	if(num%4 == 2)
		return 'H';
	if(num%4 == 3)
		return 'D';
	if(num%4 == 0)
		return 'C';

	return 0;
}
