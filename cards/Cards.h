#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <iterator> 
using namespace std;

class Card
{
public:
	Card();

	~Card();

	//initialize the card type vector
	void initializeVecCardType();

	//for test to print all card types
	void printVecCardType();

	//set card type id, from 0-4 ***remove Id from naming***
	void setCardTypeId(int num);

	//get card type 
	string getCardType();

	string to_string();

	Card(const Card&);

	Card& operator=(const Card&);

	friend ostream& operator<<(ostream&, Card&);


private:
	//the vector stores the 5 types of card as a string, 0->bomb, 1->reinforcement, 2->blockade, 3->airlift, 4->displomacy
	vector<string> vecCardType;		//MAKE AN ENUM

	string cardType;


};

//deck class inherit the card class
class Deck :public Card {

public:

	Deck();

	~Deck();

	//initialize the Deck depending on the number of players *for now the formula is numplayers * 10 **
	void initializeVecDeck(int numPlayers);

	//print the size of Deck
	void printVecDeckSize();

	//returns the top card of the Deck to the player's hand
	Card* draw();

	//add card into Deck
	void addCard(Card* oneCard);

	string to_string();

	Deck(const Deck&);

	Deck& operator=(const Deck&);

	friend ostream& operator<<(ostream&, Deck&);

private:
	vector<Card*> vecDeck;
	Card* ptrCard;				//used to create cards

	Card* tempCard;				//used when drawing and removing from deck 

};


class Hand : public Deck {

public:
	Hand();

	~Hand();

	//add card to player's hand
	void addCard(Card* a_card);

	//when playing a card, at the moment, simply returns the card to the deck,and deletes from hand
	void play(Card* aCard, Deck* aDeck);

	//returns the list of cards in player's hand
	vector<Card*>* getVecHand();

	//shows all cards to played this turn
	void printVecPlayCards();

	//this vector holds all cards to be played this turn
	vector<Card*>* getVecPlayCards();

	//return a card to the deck cards
	void returnPlayedCardToDeck(Deck* aDeck);

	//remove a card from the player's hand
	void removePlayedCardOfHand(Card* r_card);

	int getVecHandSize();

	string to_string();

	Hand(const Hand&);

	Hand& operator=(const Hand&);

	friend ostream& operator<<(ostream&, Hand&);

private:
	vector<Card*> vecHand;//for storing cards in player hand

	vector<Card*> vecPlayCards;//for storing cards to be played this turn

};