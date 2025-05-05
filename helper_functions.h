#include <string>
#include <iostream>

using namespace std;

// TODO: revise the constants per your discretion
const double MINIMUM_CHARGE = 30;
const double OAK_CHARGE = 15;
const int FREE_LETTERS = 6;
const double LETTER_CHARGE = 3;
const double OLD_LEAF_CHARGE = 12;

const int MAX_SIGN_ENTRY_ATTRIBUTES = 3;    // attribites include wood type, number of letters, and letter color
const int MAX_ORDERS = 2;
const int MAX_SIGN_ENTRIES_PER_ORDER = 2;

struct Entry {
	string woodType;
	string signCharacters;
	string colorOfCharacters;
};

struct SignOrder {
    Entry entries[MAX_SIGN_ENTRIES_PER_ORDER];
    int numEntries=0;
    double entryCharge[MAX_SIGN_ENTRIES_PER_ORDER]={0,0};
    double signOrderCharge=0;
};

struct Order {
    SignOrder signOrders[MAX_ORDERS];
    int numOrders=0;
    double totalCharge=0;
};

// TODO: add helper functions prototype here per your discretion
double calculateTotalEntryCharge(double entryCharge[]);