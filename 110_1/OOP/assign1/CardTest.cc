/* Copyright (c) 1999 by The National Chengchi Univ. All Rights Reserved */

/***************************************************************************
   NAME
     CardTest.cc
   PURPOSE
     Testing card displaying
   NOTES

   AUTHOR
     Tsai-Yen Li (li@cs.nccu.edu.tw)
   HISTORY
     Tsai-Yen Li - Oct 7, 1999: Created.
***************************************************************************/

/* $Log:$ */

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <assert.h>
}

#include <iostream>
#include "AnsiPrint.h"
#include "Cards.h"

using namespace std;

/**
 * Print my id 
 */
void
PrintMyID(const char *studId) {

  char *str= new char[sizeof(studId)+5];
  // we put string in a buffer first 
  sprintf(str,"ID: %s",studId);
  // print the buffer out with color
  AnsiPrint(str,yellow,red, true, true);
  cout << endl << endl;
  delete [] str;

}


/**
 * PrintUsage
 */
void
PrintUsage(const char *progName) {

  assert(progName);
  cout << "Usage: " << progName << " NCards [Seed]" << endl;

}

/**
 * Main Function Call
 */
int
main(int argc, char **argv) {

  int ncards=0;  // number of cards to draw 
  if (argc==3) {
    long seed=atoi(argv[2]); // the third argument is the seed
    srand(seed);
    ncards=atoi(argv[1]); // the second argument is the number of cards
  } else if (argc==2) {
    ncards=atoi(argv[1]);
  } else {
    PrintUsage(argv[0]);
    exit(-1);
  }

  // You are asked to fill in a few missing statements here

  //only have 52 cards
  if(ncards > 52){
	  cout << "Sorry, number of cards can not be greater than 52" << endl;
	  return 0;
  }
  
  int tmp,pip[ncards],flag[53] = {0};
  char suit[ncards],output[12];
  //pick cards randomly
  for(int i=0;i<ncards;++i){
	  tmp = rand() % (52) +1;
	  if(flag[tmp] == 0){
		  pip[i] = tmp;
		  flag[tmp] = 1;
	  }
	  else{
		  --i;
	  }
  }
  
 //turn the random numbers to follwing suit and pip 
  for(int i=0;i<ncards;++i){
	  suit[i] = findSuit(pip[i]);
	  pip[i] = findPip(pip[i]);
  }

  for(int i=0;i<ncards;i+=5){
	  for(int k=0;k<11;++k){
		  for(int j=i;j<i+5;++j){
			  if(j >= ncards){
				  break;
			  }
			  if(suit[j]=='S' || suit[j]=='C'){
				  //the first and last line did not need to change anything
				  if(k==0 || k==10){
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
				  if(k==0 || k==10){
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
  }

  // Print my id at the end of the program
  PrintMyID("s10937");

  return 0;

}
