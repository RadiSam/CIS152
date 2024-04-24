/***************************************************************
* Name : FinalProjectVanluong
* Author: Logun Van Luong
* Created : 3/25/24
* Course: CIS 152 - Data Structure
* Version: 1.0
* OS: Windows 11
* IDE: Qt Creator 11.0.2
* Copyright : This is my own original work
* based on specifications issued by our instructor
* Description : A gambling simulation style game for the
* final project of the class.
*            Input: string text
*            Ouput: String text to terminal
*            BigO: Polynomial Time 0(N^2)
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access
* to my program.
***************************************************************/
#include <iostream>
#include <player.h>
#include <store.h>
#include <roulette.h>
#include <plinko.h>
#include <binarytree.h>
#include <btnodes.h>
#include <reportnodes.h>
#include <report.h>

using namespace std;

int main()
{
    //constants
    const int MAX_ROUNDS = 11;
    const int PLINKO_CHANCE_COST = 3;
    const int ROUND_INCREMENT = 1;
    const int WHEEL_SIZE = 20;
    const int ZERO = 0;
    // variables
    string userString;
    string userStartPocket;
    int userInt;
    Store store;
    Roulette wheel;
    Plinko plinko;
    Report report;
    int round = 1;
    string mode = "s";
    // game options: r = Roulette, p = Plinko, s = Store , q = Quit, b = Bio
    // Starting prompt
    cout << "Welcome to the Relief Roulette game!" << endl;
    cout << "To start please enter a name and amount of money you would like to start with..." << endl;
    // uses getline for input verification
    getline(cin, userString);
    getline(cin, userStartPocket);
    // try catch block
    try {
        userInt = stoi(userStartPocket);
    }
    catch (const exception& invalid){
        cout << "Invalid amount entered. Try again with some numbers." << endl;
        return 0;
    }
    // exits program when player pocket input is invalid
    Player p1(userString, userInt);
    // prints player data
    cout << p1.printTitle() << endl;
    cout << "Alright let's get started with the games!" << endl;
    cout << "But first let's go to the store to buy chances!" << endl;
    // interface loop which stops when user input is invalid or rounds reach 11
    while ((cin) && (round < MAX_ROUNDS)) {
        cout << "Round: " << round << endl;
        //store
        if (mode == "s") {
            store.buyStuff(p1, report.search(round));
        }
        //plinko
        else if (mode == "p") {
            cout << "Welcome to plinko, here you wager all your money in order to get a return of 3 times the amount,"
                << " lose all your money, or somewhere in between! \nIt costs 3 chances to play, will you pay yes or no?" << endl;
            cin >> userString;
            if (userString == "yes") {
                if (p1.getChances() < PLINKO_CHANCE_COST) {
                    cout << "Oops, looks like there isn't enough chances to play. Come back next time!" << endl;
                }
                else {
                    p1.setChances(p1.getChances() - PLINKO_CHANCE_COST);
                    report.search(round)->setChancesSpent(report.search(round)->getChancesSpent() + PLINKO_CHANCE_COST);
                    p1.setPocket(plinko.startPlinko(p1, report.search(round)));
                    cout << "Your pocket now has $" << p1.getPocket() << endl;
                    round += ROUND_INCREMENT;
                }
            }
            else {
                cout << "Alright, maybe next time then!" << endl;
            }
        }
        //roulette
        else if (mode == "r") {
            wheel.setQueue(WHEEL_SIZE);
            cout << "Let's start the Wheel!" << endl;
            cout << "How many chances will you enter?" << endl;
            cin >> userInt;
            int validChance = p1.validChanceInput(userInt);
            if (wheel.queueAvailable(validChance, wheel.getWheel())) {
                p1.setChances(p1.getChances() - validChance);
                report.search(round)->setChancesSpent(report.search(round)->getChancesSpent() + validChance);
                cout << wheel.getResult(validChance, p1, report.search(round)) << endl;
                cout << "This is now your current pocket: $" << p1.getPocket() << endl;
                if (validChance != ZERO) {round += ROUND_INCREMENT;}
            }
        }
        //player
        else if (mode == "b") {
            cout << p1.printTitle() << endl;
        }
        //quit
        else if (mode == "q") {
            cout << "Thanks for playing!" << endl;
            cout << "Here is a report of your decisions and stats from the game!" <<
                "\nWould you like a chronological report or incremental based on Earnings, choose 1 or 2 for respective options." << endl;
            cin >> userString;
            cout << "Final Stats: \n" << p1.printTitle() << endl;
            if (userString == "1") {cout << report.printList(round) << endl;}
            else if (userString == "2") {cout << report.printEarnedLtoH(round) << endl;}
            else {cout << "Printing chronological report by default... " << report.printList(round) << endl;}
            break;
        }
        else {
            cout << "I'm sorry, there doesn't seem to be an option for " << mode << " . Please try again with the following options." << endl;
        }
        cout << "Select a mode from the following...\n" <<
            "r - Let's you play the roulette again!\np - Let's you play plinko to multiply all your money!" <<
            " However there is a chance to lose it all...\ns - Let's you go to the store to purchase items!\n" <<
            "b - Let's you look at your bio of how much money and chances you have.\nq - Let's you quit the game." << endl;
        cin >> mode;
    }
    if (!cin) {
        cout << "Looks like something went wrong!. Try again another time." << endl;
    }
    if (round == MAX_ROUNDS) {
        cout << "Thanks for playing!" << endl;
        cout << "Here is a report of your decisions and stats from the game!" <<
            "\nWould you like a chronological report or incremental based on Earnings, choose 1 or 2 for respective options." << endl;
        cin >> userString;
        cout << "Final Stats: \n" << p1.printTitle() << endl;
        if (userString == "1") {cout << report.printList(round) << endl;}
        else if (userString == "2") {cout << report.printEarnedLtoH(round) << endl;}
        else {cout << "Printing chronological report by default... " << report.printList(round) << endl;}
    }
    return 0;
}
