
//
//  big_number.cpp
//
//  Class that implements a BigNumber representation.
//
//  Created by Ryan Faulkner on 4/16/13.
//  Copyright (c) 2013. All rights reserved.
//

#include <iostream>
#include <string>

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
     * Adds this big number by the arg - size of operands
     */
    BigNumber operator+(const BigNumber& other){
        int size, i, new_val, carry = 0;

        // TODO - throw exception instead
        if (this->size != other->size)
            cout << "BigNumber::operator+ - Mismatched sizes." << endl;

        for (i=0; i < this->size; i++) {
            new_val = digits[i] + other + carry;

            this->digits[i] = new_val % 10;
            if (new_val >= 10)
                carry = new_val / 10;
            else
                carry = 0;
        }

        // TODO - throw exception instead
        if (carry > 0)
            cout << "BigNumber::operator+ - Overflow." << endl;

        return this;
    }

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