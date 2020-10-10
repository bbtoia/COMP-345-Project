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


int main(){
    
    //Creating two players
    Player player1("Berta");    //Created player1 using the paramterized constructor
    Player player2;             //Created player2 with the default constructor
    Player player3("Kevin");
    
    
    //Testing copy constructor
    
    
    
    //Testing stream insertion opertor
    
    

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
    
    //Printing the map
    cout << "Testing map: \n" <<  testMap.to_string() << "\n";
    
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
    cout << "\nTest printing players list of orders" << player1.getName() << ":\n" << *(player1.getOrderList()) << endl;
    
    //Test toAttack() which returns a list of territories that can be attacked
    cout << "Test printing players territories to attack:\n" + player1.printList(player1.toAttack(testMap));
    
    
    
    //Test toDefend()  which returns a list of territories that can be defended
    cout << "\nTest printing players territories to defend:\n" + player1.printList(player1.toDefend(testMap));
    
////    cout << player1.printList(player1.toDefend(testMap)) << " Printed toDefend()";
//    
//    //Creating, initializing a deck of cards
//    Deck testDeck;
//    testDeck.initialize_vec_deck();
//    
//    //Test drawing two cards from the deck and adding them to the player hand and printing the hand
//    cout << "\nDrawing cards from the deck:\n";
//    player1.handOfCards->set_vec_hand(testDeck.draw());
//    player1.handOfCards->set_vec_hand(testDeck.draw());
//    cout << *(player1.getHandOfCards());
//    
//    //Testing players to_string method
//    cout << "\nTesting players toString() method:" << player1.to_string() << endl;

    //Test destructor
    
    
    return 0;
};
