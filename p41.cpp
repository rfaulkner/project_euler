
//
//  p40.cpp
//  
//  Project Euler Problem 40
//
//  Created by Ryan Faulkner on 10/10/13.
//  Copyright (c) 2013. All rights reserved.
//

#include <iostream>
#include <string>
#include "helper/big_number.cpp"

using namespace std;


int main() {

    BigNumber* largest;
    BigNumber* curr = new BigNumber(9, 2143);

    // Find largest pandigital
    while (1)
    {
        // Check for overflow
        if (curr == 0)
           break;

        // Check for prime
        if (curr->is_prime() && curr->is_pandigital) {
            largest = curr;
        }

        curr++;
    }

    cout << "The largest pandigital prime is:" << endl;
    largest->print();

    return 0;
}
