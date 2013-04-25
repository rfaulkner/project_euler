//
//  p25.cpp
//  
//
//  Created by Ryan Faulkner on 4/24/13.
//  Copyright (c) 2013 R.Faulkner. All rights reserved.
//

#include <iostream>
#include "helper/big_number.cpp"

using namespace std;


int main() {
    
    BigNumber fn(1000, 1);
    BigNumber fn_minus_1(1000, 1);
    
    long count = 3;
    
    while (1)
    {
        fn = fn - fn_minus_1;
        fn_minus_1 = fn + fn_minus_1;
        fn = fn_minus_1 * 2 - fn;
        
        if (fn.get_digit(999) > 0)
            break;
        
        count++;
    }
    
    fn.print();
    cout << "The " << count << " term of the fibonacci sequence is the first to contain at least 1000 digits." << endl;
    
    return 0;
}


