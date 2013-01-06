//
//  p16.cpp
//  
//
//  Created by Ryan Faulkner on 12/5/12.
//  Copyright (c) 2012 R.Faulkner. All rights reserved.
//

#include <iostream>

using namespace std;

// Multiplies integers with array representation
int* multiply(int* val, int size) {

    int i,new_val;
    int carry = 0;
    
    // int size = sizeof(val) / sizeof(val[0]);
    // cout << size << endl;
    
    for (i = 0; i < size; i++) {
                
        new_val = val[i] * 2 + carry;        
        if (new_val >= 10) {
            carry = 1;
            val[i] = new_val % 10;            
        } else {
            val[i] = new_val;
            carry = 0;
        }
    }
    return val;
}

int main() {
    
    int i, j, exponent=1000, digits=500;
    int* large_number = new int[digits]; 
    
    // initialize
    for (i = 1; i < digits; i++) large_number[i] = 0;
    large_number[0] = 1;
    
    // compute 2^1000
    for (i = 0; i < exponent; i++) {
        large_number = multiply(large_number, digits);
        if (i % 50 == 0) {
            for (j = 0; j < digits; j++) cout << large_number[j];
            cout << endl;
        }
    }
        
    // Count the digits
    int digit_sum = 0;
    for (i = 0; i < digits; i++) digit_sum += large_number[i];
    
    cout << "Digit sum = " << digit_sum << endl;

    return 0;
}
