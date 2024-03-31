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
* Description : An application roulette style game for the
* final project of the class.
*            Input: string text
*            Ouput: String text to terminal
*            BigO: Linear Time 0(N)
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access
* to my program.
***************************************************************/
#include <iostream>
#include <player.h>
#include <store.h>
#include <roulette.h>
using namespace std;

int main()
{
    //interface testing
    // variables 
    string userName;
    int userMoney;
    int userresponse;
    Store store;
    Roulette wheel;
    // prompt for player data
    cout << "Welcome to the Relief Roulette game!" << endl;
    cout << "To start please enter a name and amount of money you would like to start with..." << endl;
    cin >> userName;
    cin >> userMoney;
    // prints player data
    Player p1(userName, userMoney);
    cout << p1.printTitle() << endl;
    // roulette tests
    store.buyStuff(p1);
    cout << "Let's start the games!" << endl;
    cout << "How many chances will you enter?" << endl;
    cin >> userresponse; // left off
    p1.setChances((p1.getChances()-userresponse));


    cout << wheel.getResult(userresponse) << endl;

    return 0;
}
