
//
//  p12.cpp
//
//  http://projecteuler.net/problem=12
//
//  Created by Ryan Faulkner on 11/23/12.
//  Copyright (c) 2012 R.Faulkner. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>

#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif

using namespace std;

// Hash that stores number of divisors
typedef std::vector <long> my_vec;
typedef __gnu_cxx::hash_map <long, bool> map_t;

my_vec divisors_set(long n) {
    
    my_vec divisors;
    long i = 2;
    
    divisors.push_back(1);
    divisors.push_back(n);
    
    while (i <= n/2) 
        if (n % i == 0) {
            divisors.push_back(i);
            i++;
        } else
            i++;
    return divisors;
}

int main() {
    
    long index = 3, prod, compound_divisor;
    map_t all_divisors;
    long tri_num;
    
    my_vec n_factors, n_plus_1_factors;
    
    // note that for triangle number k, T(k) = n(n+1) / 2

    n_factors = divisors_set(index);
    
    // for (my_vec::iterator it = n_factors.begin(); it != n_factors.end(); it++) cout << (long)*it << " ";
    // cout << endl;
    
    while (true) {
        
        all_divisors.clear();

        prod = (++index % 2 == 0) ? index / 2 : index; 
        n_plus_1_factors = divisors_set(prod);
        tri_num = (index - 1) * (index) / 2;

        for (my_vec::iterator s(n_factors.begin()), e(n_factors.end()); s!=e; s++) all_divisors[(long)*s] = true;
        for (my_vec::iterator s(n_plus_1_factors.begin()), e(n_plus_1_factors.end()); s!=e; s++) all_divisors[(long)*s] = true;             
            
        for (my_vec::iterator s1(n_factors.begin()), e1(n_factors.end()); s1!=e1; s1++)
            for (my_vec::iterator s2(n_plus_1_factors.begin()), e2(n_plus_1_factors.end()); s2!=e2; s2++) {
                // cout << (long)*s1 << " , " << (long)*s2 << " : ";
                compound_divisor = (long)*s1 * (long)*s2;
                if (tri_num % compound_divisor == 0)
                    all_divisors[compound_divisor] = true;
            }
                        
        if (all_divisors.size() >= 500) break; // break condition         
        n_factors = n_plus_1_factors;
        
        if (index % 1000 == 0) cout << tri_num << ", the " << index-1 << "th triangle number has " << all_divisors.size() << " divisors." << endl; // logging
        // for (map_t::iterator i(all_divisors.begin()), j(all_divisors.end()); i!=j; ++i) cout << i->first << " , "; cout << endl; // testing
    };

    cout << endl << "The " << index-1 << "th triangle number is: " << tri_num << endl;
    cout << "Number of divisors: " << all_divisors.size() << endl;
    //  for (map_t::iterator i(map.begin()), j(map.end()); i!=j; ++i) cout << i->first << " : " << i->second << ", ";
    // cout << endl << endl;

    return 0;
}


