
//
//  p20.cpp
//  
//
//  Created by Ryan Faulkner on 1/6/13.
//  Copyright (c) 2012 R.Faulkner. All rights reserved.
//

#include <iostream>

using namespace std;

class BigNumber {

public:
        
    BigNumber(int dim) {
        this->digits = new int[dim];
        this->size = dim;        
        for (int i = 0; i < dim; i++) this->digits[i] = 0;
    }
    
    BigNumber(int dim, long val) {
        int i;
        
        this->digits = new int[dim];
        this->size = dim;
        for (i = 0; i < dim; i++) {            
            this->digits[i] = val % 10;
            val /= 10;
        }
        
    }
    
    // Prints the number
    void print() {
        for (int i = this->size; i >= 0; i--) cout << this->digits[i];
        cout << endl;
    }
    
    int get_size() { return this->size; }
    int get_digit(int index) { return this->digits[index]; }
    
    /*
     const BigNumber operator*(const BigNumber &other) {
        BigNumber result();
        return result;
    } */
    
    /*
     * Multiplies this big number by the arg
     */
    
    BigNumber* multiply(int other) {
        
        int i, new_val, carry = 0;
        
        for (i=0; i < this->size; i++) {
            new_val = digits[i] * other + carry;

            this->digits[i] = new_val % 10;
            if (new_val >= 10) 
                carry = new_val / 10;
            else
                carry = 0;
        }
        
        return this;
    }
    
private:
    int* digits;
    int size;
};



int main() {
    
    BigNumber* a = new BigNumber(200, 1); 
    int sum = 0;
    
    a->print();

    for (int i = 1; i <= 100; i ++) a->multiply(i);
    a->print();
    
    for (int i = 0; i <= 200; i ++) sum += a->get_digit(i);
    cout << "Digit sum = " << sum << endl;
    
    delete a;
    
    return 0;
}