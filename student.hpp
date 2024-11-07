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

	double totalCharge = 0;
	
	return totalCharge;
}

// Exercise 2: TODO: calculate the order pricing based on sign entries and store entry charge in the entryCharge array
void calcSignOrderPricing(SignOrder &signOrder);

// ===============
// implementations
void calcSignOrderPricing(SignOrder &signOrder) {
	// TODO: reuse the caclSignOrderPricing function
}

// Exercise 3: TODO: calculate the total order charge based on the entryCharge array
void calcOrderPrice(Order &order);

// ===============
// implementations
void calcOrderPrice(Order &order) {
	// TODO: reuse the calcSignOrderPricing function
}
