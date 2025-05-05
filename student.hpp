#pragma once // prevents multiple definitions

#include <iostream> // print library
#include "helper_functions.h" // helper functions

/* derive from helper_functions.cpp
#include <string> // string library
using namespace std; // use the standard namespace
*/


// Exercise 1: implement smith shop order calculation per requirements from assignment
double calcSignEntryPricing(Entry entry);

// ===============
// implementations
double calcSignEntryPricing(Entry entry) {

	double totalCharge = MINIMUM_CHARGE;

	if (entry.woodType == "oak") {
		totalCharge += OAK_CHARGE;
	}

	int numLetters = entry.signCharacters.length();
	if (numLetters > FREE_LETTERS) {
		totalCharge += (numLetters - FREE_LETTERS) * LETTER_CHARGE;
	}

	if (entry.colorOfCharacters == "old-leaf") {
		totalCharge += OLD_LEAF_CHARGE;//test case typo (suppose to be gold-leaf)
	}

	return totalCharge;
}

// Exercise 2: TODO: calculate the order pricing based on sign entries and store entry charge in the entryCharge array
void calcSignOrderPricing(SignOrder &signOrder);

// ===============
// implementations
void calcSignOrderPricing(SignOrder &signOrder) {
	// TODO: reuse the caclSignOrderPricing function
	signOrder.signOrderCharge = 0.0;

	for (int i = 0; i< signOrder.numEntries; i++) {
		signOrder.entryCharge[i] = calcSignEntryPricing(signOrder.entries[i]);
		signOrder.signOrderCharge += signOrder.entryCharge[i];
	}
}

// Exercise 3: TODO: calculate the total order charge based on the entryCharge array
void calcOrderPrice(Order &order);

// ===============
// implementations
void calcOrderPrice(Order &order) {
	// TODO: reuse the calcSignOrderPricing function
	order.totalCharge = 0.0;

	for (int i = 0; i < order.numOrders; i++) {
		calcSignOrderPricing(order.signOrders[i]);
		order.totalCharge += order.signOrders[i].signOrderCharge;
	}
}