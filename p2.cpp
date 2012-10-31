//
//  p2.cpp
//  
//
//  Created by Ryan Faulkner on 10/27/12.
//  Copyright (c) 2012 RFaulkner. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
  int n = 1;
  int n_p_1 = 2;
  int temp;
  int sum = 0;  
  
  while (n_p_1 <= 4000000) {
    if (n_p_1 % 2 == 0)
      sum += n_p_1;
    temp = n;
    n = n_p_1;
    n_p_1 += temp;
  }
  cout << sum << endl;
  return 0;
}

