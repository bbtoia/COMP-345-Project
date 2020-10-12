//
//  PlayerDriver.cpp
//  Player
//  The driver of the player class tests all classes implemented with the Player class. The player can own a collection of territories, a hand of warzone cards and a list of orders to be executed. In addition, the player can print all territories that can be attacked and all territories that can be defended as well as issueing an order and adding it to the list of orders.
//  Created by Lina Kretzschmar on 2020-09-27.
//


#include <stdio.h>
#include <iostream>
#include "Player.h"

using namespace std;

int Player::playerCount = 0;


int main() {

    //Creating two players
    Player player1("Berta");    //Created player1 using the paramterized constructor
    Player player2;             //Created player2 with the default constructor


    //Testing copy constructor
    Player* player3 (new Player("Trudy"));
    Player* player4 = player3;
    cout << "Testing copy constructor, printing name of player5 as example:\n" << player4->getName() << endl;


    //Testing assignment operator --> This is currently not working. To get my code to work I currently have to comment out the Card destructor within the player destructor
    //Player player5("Dennis");
    //Player player6("Frida");
    //player5 = player6; /*-->Cannot test right now since I need Hand's destructor*/
    //cout << "\nTesting assignment operator, printing name of player 5 as example:\n" << player5.getName() << endl;


    //Testing stream insertion opertor
    cout << "\nTesting stream insertion operator printing no values since player1 does not have any cards, territories or oders yet:";
    cout << player1;


    //Creating a map
    Map testMap = Map();


    //Creating two continents
    shared_ptr<Continent> c1 = testMap.add(Continent(1, "America", 1));
    shared_ptr<Continent> c2 = testMap.add(Continent(2, "Europe", 5));


    //Creating new territories of type ptr and adding them to the testMap
    shared_ptr<Territory> t1 = testMap.add(Territory(1, "Canada", 1));
    shared_ptr<Territory> t2 = testMap.add(Territory(2, "Iceland", 2));
    shared_ptr<Territory> t3 = testMap.add(Territory(3, "United Kingdom", 2));
    shared_ptr<Territory> t4 = testMap.add(Territory(4, "France", 2));
    shared_ptr<Territory> t5 = testMap.add(Territory(5, "Spain", 2));
    shared_ptr<Territory> t6 = testMap.add(Territory(6, "Italy", 2));


    //Connecting territories via directed graphs
    testMap.link(t1, t2);
    testMap.link(t2, t3);
    testMap.link(t3, t4);
    testMap.link(t4, t5);
    testMap.link(t4, t1);
    testMap.link(t5, t6);
    testMap.link(t6, t3);
    testMap.link(t6, t4);


    //Validating the map
    cout << "Validating created map:\n";
    testMap.validate();


    //Printing the map
    cout << "\nTesting created map: \n" << testMap.to_string() << "\n";


    //Adding two territories to player1
    player1.addTerritory(t3);
    player1.addTerritory(t4);
   

    //Displaying territoryList containing territories currently owned by player2
    cout << "\nTesting players list of territories:\n" + player1.printList(player1.getTerritoryList());


    //Test issueOrder() creates an order objects and adds it to the OrderList
    cout << "\nTest issueing orders:\n";
    player1.issueOrder("Deploy");
    player1.issueOrder("Advance");
    player1.issueOrder("Bomb");
    player1.issueOrder("Blockade");
    player1.issueOrder("Airlift");
    player1.issueOrder("Negotiate");


    //Printing the list of orders
    cout << "\nTest printing players list of orders " << player1.getName() << ":\n" << *(player1.getOrderList()) << endl;


    //Test toAttack() which returns a list of territories that can be attacked
    cout << "Test printing players territories to attack:\n" + player1.printList(player1.toAttack(testMap));

    //Test toDefend()  which returns a list of territories that can be defended
    cout << "\nTest printing players territories to defend:\n" + player1.printList(player1.toDefend(testMap));


    //creating, initializing a deck of cards
    Deck testDeck;
    testDeck.initializeVecDeck(3);
    //initialize_vec_deck();


    //test drawing two cards from the deck and adding them to the player hand and printing the hand
    cout << "\ndrawing cards from the deck:\n";
    player1.getHand()->addCard(testDeck.draw());
    player1.getHand()->addCard(testDeck.draw());
    cout << *(player1.getHand());


    //testing players to_string method
    cout << "\ntesting players tostring() method:" << player1.to_string() << endl;


    return 0;
};
