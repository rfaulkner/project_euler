//
//  p3.cpp
//  
//
//  Created by Ryan Faulkner on 10/27/12.
//  Copyright (c) 2012 RFaulkner. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

long top_prime(long n) {
  long limit = n / 2 + 1;
  long i = 2;
  
  while (i < limit) {
    if (n % i == 0)
      return top_prime(n / i);
    i++;
  }
  return n;
}

int main() {
  long n = 600851475143;
  cout << top_prime(n) << endl;
  return 0;
}

