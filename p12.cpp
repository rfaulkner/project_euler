
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
typedef __gnu_cxx::hash_map <long, int> :: iterator iter_t;

map_t map;
iter_t iter;

int count_divisors(long n) {
    
    int count = 2; // 1 & n are divisors
    long i = 2;
    long limit = n/2 + 1;
    
    // Check whether this value has a already a stored number of divisors
    iter = map.find(n); 
    if (iter != map.end())
        return iter->second;
    
    while (i < limit) 
        if (n % i++ == 0) 
            if (map.find(i) != map.end()) {
                n /= i;
                limit = n/2 + 1;
                count += map[i];
                i = 2;
            }
            else count++;
    
    map[n] = count; // store the divisors in 
    return count;
}

int main() {
    
    long index = 2;
    int n, n_plus_1;    

    // note that for triangle number k, T(k) = n(n+1) / 2
    n = count_divisors(index);
    while (true) {
        n_plus_1 = (count_divisors(++index)); // count the divisors for the factor n+1
        
        // the divisors of n and n+1 are disctinct, so add them, remove one, and compare to 500
        if (n + n_plus_1 - 3 > 500) 
            break;
        
        n = n_plus_1;        
        cout << "The " << (index - 1) << "th triangle number is: " << (index - 1) * (index) / 2 << endl;
        cout << "Number of divisors: " << n + n_plus_1 - 3 << endl;
        if (index == 20) break;
    };
    
    

    // for (iter = map.begin(); iter != map.end(); iter++)
    //    cout << iter->first << " : " << iter->second >> endl;

    return 0;
}


/*
 
 Examples of how to work with the hash_map:
 
 map[4] = 2;
 map[2] = 1;
 iter = map.find(4);
 
 if (iter == map.end())
 cout << "key does not exist." << endl;
 else {
 cout << iter->first << endl;
 cout << iter->second << endl;
 } 
 */
