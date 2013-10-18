
//
//  p41.cpp
//  
//  Project Euler Problem 41
//
//  Created by Ryan Faulkner on 10/10/13.
//  Copyright (c) 2013. All rights reserved.
//

#include <iostream>
#include <string>
#include "helper/big_number.cpp"

using namespace std;


int main() {

    const int size = 10;
    const BigNumber one(size, 1);
    BigNumber curr(size, 1000000000);

    //
    // TODO!  This is inefficient, it would be even
    //          better find a way to list all of the
    //          the pandigitals rathe than check for 
    //          them
    //
    
    // Find largest pandigital prime
    while (1)
    {
        // curr.print();
        // Check for prime
        if (is_pandigital(curr))
            if (is_prime(curr)) {                
                break;
            }
        curr -= one;
    }

    cout << "The largest pandigital prime is:" << endl;
    curr.print();

    return 0;
}
