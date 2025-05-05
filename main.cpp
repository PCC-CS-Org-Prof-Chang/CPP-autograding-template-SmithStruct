#include "helper_functions.h"

// ===============
// implementations before porting to student.hpp; 

using namespace std;

// Exercise 1: TODO: calculate the sign order pricing based on given sign entry attributes	
double calcSignEntryPricing(Entry entry) {

	double totalCharge = MINIMUM_CHARGE;

	if (entry.woodType == "oak") {
		totalCharge += OAK_CHARGE;
	}

	int numLetters = entry.signCharacters.length();
	if (numLetters > FREE_LETTERS) {
		totalCharge += (numLetters - FREE_LETTERS) * LETTER_CHARGE;
	}

	if (entry.colorOfCharacters == "gold-leaf") {
		totalCharge += GOLD_LEAF_CHARGE;
	}

	return totalCharge;
}

// Exercise 2: TODO: calculate the order pricing based on sign order struct
void calcSignOrderPricing(SignOrder &signOrder) {
	// TODO: reuse the caclSignOrderPricing function
	signOrder.signOrderCharge = 0.0;

	for (int i = 0; i< signOrder.numEntries; i++) {
		signOrder.entryCharge[i] = calcSignEntryPricing(signOrder.entries[i]);
		signOrder.signOrderCharge += signOrder.entryCharge[i];
	}
}

// Exercise 3: TODO: calculate the order pricing based on order struct	
void calcOrderPrice(Order &order) {
	// TODO: reuse the calcSignOrderPricing function
	order.totalCharge = 0.0;

	for (int i = 0; i < order.numOrders; i++) {
		calcSignOrderPricing(order.signOrders[i]);
		order.totalCharge += order.signOrders[i].signOrderCharge;
	}
}

// main function using structs
int main(){

	// TODO: implement your interactive main function here
	Order order;
	order.numOrders = 1;

	SignOrder signOrder;
	signOrder.numEntries = 2;

	cout << "Enter wood type for first entry (eg. oak, pine): ";
	cin >> signOrder.entries[0].woodType;
	cout << "Enter sign characters for first entry: ";
	cin.ignore();
	getline(cin, signOrder.entries[0].signCharacters);
	cout << "Enter color of characters for first entry(e.g. white, black, gold-leaf): ";
	cin >> signOrder.entries[0].colorOfCharacters;

	//second entry
	cout << "Enter wood type for second entry (eg. oak, pine): ";
	cin >> signOrder.entries[1].woodType;
	cout << "Enter signcharacters for second entry: ";
	cin.ignore();
	getline(cin, signOrder.entries[1].signCharacters);
	cout << "Enter color of characters for second entry(e.g. white, black, gold-leaf): ";
	cin >> signOrder.entries[1].colorOfCharacters;

	order.signOrders[0] = signOrder;

	calcOrderPrice(order);

	cout << "\nTotal charge for the order is $ " << order.totalCharge << endl;

	return 0;
}