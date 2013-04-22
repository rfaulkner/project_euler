
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

using namespace std;


class BigNumber {

    public:

        BigNumber(int dim) {
            this->digits = new int[dim];
            this->size = dim;
            this->is_neg = false;
            for (int i = 0; i < dim; i++) this->digits[i] = 0;
        }

        BigNumber(int dim, long val) {
            int i;

            this->digits = new int[dim];
            this->size = dim;
            this->is_neg = false;
            for (i = 0; i < dim; i++) {
                this->digits[i] = val % 10;
                val /= 10;
            }
        }

        BigNumber(BigNumber& other) {

            this->size = other.get_size();
            this->digits = new int[this->size];
            this->is_neg = other.is_negative_number();
            for (int i = 0; i < this->size; i++)
                digits[i] = other.get_digit(i);
        }

        ~BigNumber() { delete[] this->digits; }

        // Prints the number
        void print() {
            for (int i = this->size; i >= 0; i--) cout << this->digits[i];
            cout << endl;
        }

        bool is_negative_number() const { return this->is_neg; }
        int get_size() const { return this->size; }
        int get_digit(int index) const { return this->digits[index]; }

        BigNumber & operator=(const BigNumber &rhs)
        {
            delete[] this->digits;

            this->size = rhs.get_size();
            this->digits = new int[this->size];
            this->is_neg = rhs.is_negative_number();

            return *this;
        }

        /*
         * Adds this big number by the arg - size of operands
         */
        BigNumber & operator+(const BigNumber& other)
        {
            int i, new_val, carry = 0;

            // TODO - throw exception instead
            if (this->size != other.get_size())
            {
                cout << "BigNumber::operator+ - Mismatched sizes." << endl;
                return *(new BigNumber(1,0));
            }

            for (i=0; i < this->size; i++)
            {
                new_val = digits[i] + other.get_digit(i) + carry;

                this->digits[i] = new_val % 10;
                if (new_val >= 10)
                    carry = new_val / 10;
                else
                    carry = 0;
            }

            // TODO - throw exception instead
            if (carry > 0)
                cout << "BigNumber::operator- - Overflow." << endl;

            return *this;
        }

        /*
         * Multiplies this big number by the arg
         */
        BigNumber & operator*(const int &other) {

            int i, new_val, carry = 0;

            for (i=0; i < this->size; i++) {
                new_val = digits[i] * other + carry;
                this->digits[i] = new_val % 10;
                if (new_val >= 10)
                    carry = new_val / 10;
                else
                    carry = 0;
            }

            return *this;
        }

    private:
        int* digits;
        int size;
        bool is_neg;
};
