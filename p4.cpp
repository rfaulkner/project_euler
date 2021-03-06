//
//  p4.cpp
//
//
//  Created by Ryan Faulkner on 10/31/12.
//  Copyright (c) 2012 RFaulkner. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

// Flags `pal` for being a palindrome
bool is_palindrome(int pal) {
  string str = static_cast<ostringstream*>( &(ostringstream() << pal) )->str();
  int n = str.length();
  int mid = n / 2;
  bool is_pal = true;
  
  if (n % 2 != 0)
    mid++;

  for (int k = 0; k < mid; k++) {
    if (str[k] != str[n-(k+1)]) {
      is_pal = false;
      break;
    }
  }
  return is_pal;
}

int main() {
  int p,i,j;
  int pal = 0;
  
  // look for all pairs starting at 999 x 999
  for (i=999; i >= 100; i--)
    for (j = i; j >= 100; j--)
    {
      p = i*j;
      if (is_palindrome(p) && p > pal)
        pal = p;
    }

  cout << pal << endl;
  return 0;
};
 
