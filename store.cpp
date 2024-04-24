#include <store.h>

//constructor&destructor
Store::Store() {
    chances = 0;
    bank = 0;
}
Store::~Store() {}
//setters
void Store::setChances(int chancesBought) {
    chances = chancesBought;
}
void Store::setBank(int moneySpent) {
    bank = moneySpent;
}
//getters
int Store::getBank() const {
    return bank;
}
int Store::getChances() const {
    return chances;
}

// gives the player a chance to buy chances for roulette
void Store::buyStuff(Player &name, ReportNodes* node) {
    string response = "";
    int chancesWanted = 0;
    cout << "Welcome to the store where you can buy chances!" << endl;
    cout << "Would you like to purchase items? yes or no" << endl;
    cin >> response;
    if (response != "yes") {
        cout << "Okay, see you next time!" << endl;
    }
    // buying process needs double verification
    else {
        cout << "The price of a chance at roulette is $25. Would you like to buy? yes or no" << endl;
        cin >> response;
        // exits when not yes
        if (response != "yes") {
            cout << "Okay, see you next time!" << endl;
        }
        // exits when pocket cannot buy 1 chance
        else if (name.getPocket() < 25){
            cout << "Sorry, it seems you have insufficient funds to buy anything! Come back next time." << endl;
        }
        else {
            cout << "How many chances would you like?" << endl;
            cin >> chancesWanted;
            // if cannot afford amount of wanted chances
            if ((25*chancesWanted) > name.getPocket()) {
                cout << "Sorry. Insufficient funds. Come back next time." << endl;
            }
            // buys chances, updates info, and prints player info
            else {
                name.setPocket(name.getPocket()-(25*chancesWanted));
                name.setChances(name.getChances()+chancesWanted);
                bank += 25*chancesWanted;
                chances += chancesWanted;
                node->setMoneySpent(25*chancesWanted);
                cout << "Here's your inventory now!\n" << name.printTitle() << endl;
            }
        }
    }
}
