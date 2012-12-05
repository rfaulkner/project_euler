//
//  p15.cpp
//  
//
//  Created by Ryan Faulkner on 12/4/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef std::vector <long long> my_vec;

const int MAX_X = 20;
const int MAX_Y = 20;

/* 
 *  Recursive (slow) way to compute walks.
 */
long grid_walk_slow(int x, int y) {
    // cout << x << "," << y << "  ";
    if (x < MAX_X && y < MAX_X) 
        return grid_walk_slow(x+1, y) + grid_walk_slow(x, y+1);
    else if (x < MAX_X)
        return grid_walk_slow(x+1, y);
    else if (y < MAX_Y)
        return grid_walk_slow(x, y+1);
    else
        return 1;        
}

/* 
 *  Iterative solution:
 *
 *  Cycles through path lengths to determine the number of paths of a given length at a given point.  
 *  Builds `l` rows of Pascal's triangle.
 *
 */
long grid_walk_fast(int l) {
    my_vec row_curr, row_prev;
    my_vec::iterator it;
    
    long long k;
    
    row_prev.push_back(1); // populate the first row
    row_prev.push_back(1);
    
    // iterate through all path lengths
    for (int i=0; i<l; i++) {
        
        // compute terms
        for (it=row_prev.begin(); it!=row_prev.end(); it++) {
            if (it == row_prev.begin()) 
                row_curr.push_back((long long)*it);                
            else if ((long long)*it == row_prev.back()) {
                row_curr.push_back(k+(long long)*it);
                row_curr.push_back((long long)*it);                
            } else                 
                row_curr.push_back(k+(long long)*it);                        
            k=(long long)*it;            
        }
        row_prev.erase(row_prev.begin(),row_prev.end());
        for (it=row_curr.begin(); it!=row_curr.end(); it++)
            row_prev.push_back((long long)*it);
                
        // cout << row_curr.size() << endl;
        row_curr.erase(row_curr.begin(),row_curr.end());
    }
    
    // output max term from last row
    k = 0;
    for (it=row_prev.begin(); it!=row_prev.end(); it++) 
        if((long long)*it > k)
            k = (long long)*it; 
    return k;
}

int main() {
    cout << endl << grid_walk_fast(39) << endl;
    return 0;
}

