
#include "helper_functions.h"

// TODO: Implement helper functions here per your discretion
double calculateTotalEntryCharge(double entryCharge[]){
    double totalCharge = 0;
    for (int i = 0; i < MAX_SIGN_ENTRIES_PER_ORDER; i++) {
        totalCharge += entryCharge[i];
    }
    return totalCharge;
}