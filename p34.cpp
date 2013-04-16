//
//  p34.cpp
//  
//  Project Euler Problem 34
//
//  Created by Ryan Faulkner on 4/16/13.
//  Copyright (c) 2013. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;


inline int Factorial(int x) {
    /* Helper method to produce a factorial
     */
    
    return (x <= 1 ? 1 : x * Factorial(x - 1));
}


int main() {
    /* Main.  Sum up all the curious numbesr.
     */
    
    int val, digit, digit_sum, total_sum;
    int factorial [10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    
    // Iterate through all numbers up to 9! * 7 ... all values greater than this will
    // exceed the sum of the factorials of their digits
    for (int i=3; i < 1000000; i++) {
        
        digit_sum = 0;
        val = i;
        
        // Iterate through the digits of val - generate the digit_sum
        while (val > 0) {
            
            // Get the digit, add to digit_sum
            digit = val % 10;            
            digit_sum += factorial[digit];
            val /= 10;
        }
        
        // Emit the value if it is curious
        if (digit_sum == i) {
            total_sum += i;
            cout << i << " is a curious number." << endl;
        }
    }
    
    cout << "The total sum is " << total_sum << endl;

    return 0;
}