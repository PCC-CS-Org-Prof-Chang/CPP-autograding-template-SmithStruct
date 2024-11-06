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

	if (entry.signCharacters.length() > FREE_LETTERS) {
		totalCharge += (entry.signCharacters.length() - FREE_LETTERS) * LETTER_CHARGE;
	}

	if (entry.colorOfCharacters == "old-leaf") {
		totalCharge += GOLD_LEAF_CHARGE;
	}

	return totalCharge;
}

// Exercise 2: TODO: calculate the order pricing based on sign order struct
void calcSignOrderPricing(SignOrder &signOrder) {
	// TODO: reuse the caclSignOrderPricing function
	double totalCharge = 0;
	for (int i = 0; i < signOrder.numEntries; i++) {
		double singleCharge = calcSignEntryPricing(signOrder.entries[i]);
		cout << "Single charge: " << singleCharge << endl;
		totalCharge += singleCharge;
		//totalCharge += signOrder.entryCharge[i];
	}
	signOrder.signOrderCharge = totalCharge;
}

// Exercise 3: TODO: calculate the order pricing based on order struct	
void calcOrderPrice(Order &order) {
	// TODO: reuse the calcSignOrderPricing function
	double totalCharge = 0;
	for (int i = 0; i < order.numOrders; i++) {
		calcSignOrderPricing(order.signOrders[i]);
		totalCharge += order.signOrders[i].signOrderCharge;
	}	
	order.totalCharge = totalCharge;
}

void printSignOrder(SignOrder sign){
	for (int i = 0; i < sign.numEntries; i++){
		cout << "Entry " << i << ": " << sign.entries[i].woodType << " " << sign.entries[i].signCharacters << " " << sign.entries[i].colorOfCharacters << endl;
	}
	cout << "Total charge: " << sign.signOrderCharge << endl;
}

// main function using multi-dimensional arraysarray
int main(){

	// refactor the code to allow multiple sign orders storing in Order struct	
	Order order;
	order.numOrders = 2;
	order.signOrders[0].numEntries = 2;
	order.signOrders[0].entries[0].woodType = "oak";
	order.signOrders[0].entries[0].signCharacters= "Hello";
	order.signOrders[0].entries[0].colorOfCharacters = "red";
	order.signOrders[0].entries[1].woodType = "pine";
	order.signOrders[0].entries[1].signCharacters= "World";
	order.signOrders[0].entries[1].colorOfCharacters = "blue";
	order.signOrders[1].numEntries = 2;
	order.signOrders[1].entries[0].woodType = "oak";
	order.signOrders[1].entries[0].signCharacters= "HelloWorld";
	order.signOrders[1].entries[0].colorOfCharacters = "red";
	order.signOrders[1].entries[1].woodType = "pine";
	order.signOrders[1].entries[1].signCharacters= "World";
	order.signOrders[1].entries[1].colorOfCharacters = "blue";

	calcSignOrderPricing(order.signOrders[0]);
	calcSignOrderPricing(order.signOrders[1]);
	double entry1Price = calcSignEntryPricing(order.signOrders[0].entries[0]);
	double entry2Price = calcSignEntryPricing(order.signOrders[0].entries[1]);
	cout << "Entry 1 charge: " << entry1Price << endl;
	cout << "Entry 2 charge: " << entry2Price << endl;
	printSignOrder(order.signOrders[0]);
	cout << "Order 1 charge: " << order.signOrders[0].signOrderCharge << endl;
	cout << "Order 2 charge: " << order.signOrders[1].signOrderCharge << endl;
	
	// TODO: implement your interactive main function here

	return 0;
}