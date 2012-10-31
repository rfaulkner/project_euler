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

int main() {
  int factor = 2;
  int temp;
  int sum = 0;  
  
  long n = 600851475143;
  long limit = n;
  bool flag = false;
 
  while (factor <= limit) {
    limit = n / factor; 
    if (n % factor == 0) {
       flag = true;
       break;
    }
    factor++;
  }

  if (!flag)
    cout << "No prime factor" << endl;
  else
    cout << limit << endl;

  return 0;
}

