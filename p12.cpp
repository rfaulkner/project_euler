
//
//  p12.cpp
//
//  http://projecteuler.net/problem=12
//
//  Created by Ryan Faulkner on 11/23/12.
//  Copyright (c) 2012 R.Faulkner. All rights reserved.
//

#include <iostream>
#include <string>

#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
#else
#include <hash_map>
#endif


using namespace std;

// Hash that stores number of divisors
typedef __gnu_cxx::hash_map <long, int> map_t;

map_t map;
map_t::iterator iter;

int count_divisors(long n) {
    
    int count = 2; // 1 & n are divisors
    long i = n/2;
    
    // Check whether this value has a already a stored number of divisors
    iter = map.find(n); 
    if (iter != map.end())
        return iter->second;
    
    while (i > 1)
        if (n % i-- == 0)
            count++;

    map[n] = count; // store the divisors in the hash_map
    return count;
}

int main() {
    
    long index = 2;
    int n, n_plus_1;    
    int num_divisors;
    long tri_num;
    
    // note that for triangle number k, T(k) = n(n+1) / 2
    n = count_divisors(index);
    while (true) {
        n_plus_1 = (count_divisors(++index)); // count the divisors for the factor n+1
        tri_num = (index - 1) * (index) / 2;
        
        num_divisors = n + n_plus_1;
        num_divisors -= (tri_num % 2 == 0) ? 1 : 2;
        map[tri_num] = num_divisors;
        
        // map[(index - 1) * (index) / 2] = num_divisors;
        if (num_divisors >= 500) 
        n = n_plus_1;        
        
        cout << "The " << (index - 1) << "th triangle number is: " << tri_num << endl;
        cout << "Number of divisors: " << num_divisors << endl;
        for (map_t::iterator i(map.begin()), j(map.end()); i!=j; ++i) cout << i->first << " : " << i->second << ", ";
        cout << endl << endl;
        
        if (index == 10) break;
    };
    
    return 0;
}


