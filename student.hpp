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

	if (entry.signCharacters.length() > FREE_LETTERS) {
		totalCharge += (entry.signCharacters.length() - FREE_LETTERS) * LETTER_CHARGE;
	}

	if (entry.colorOfCharacters == "old-leaf") {
		totalCharge += GOLD_LEAF_CHARGE;
	}

	return totalCharge;
}

// Exercise 2: TODO: calculate the order pricing based on sign entries and stor teh charge in the entryCharge array
void calcSignOrderPricing(SignOrder &signOrder);

// ===============
// implementations
void calcSignOrderPricing(SignOrder &signOrder) {
	// TODO: reuse the caclSignOrderPricing function
	double totalCharge = 0;
	for (int i = 0; i < signOrder.numEntries; i++) {
		signOrder.entryCharge[i] = calcSignEntryPricing(signOrder.entries[i]);
		totalCharge += signOrder.entryCharge[i];
	}
	signOrder.signOrderCharge = totalCharge;
}

// Exercise 3: TODO: calculate the total order charge based on the entryCharge array
void calcOrderPrice(Order &order);

// ===============
// implementations
void calcOrderPrice(Order &order) {
	// TODO: reuse the calcSignOrderPricing function
	double totalCharge = 0;
	for (int i = 0; i < order.numOrders; i++) {
		calcSignOrderPricing(order.signOrders[i]);
		totalCharge += order.signOrders[i].signOrderCharge;
	}	
	order.totalCharge = totalCharge;
}
