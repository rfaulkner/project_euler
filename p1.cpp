//
//  p1.cpp
//  
//
//  Created by Ryan Faulkner on 10/27/12.
//  Copyright (c) 2012 RFaulkner. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
  int sum = 0;  
  for (int i=0; i <= 1000; i++)
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;
  cout << sum << endl;
  return 0;
}
