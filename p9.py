
#/env/bin/python
# -*- coding: utf-8 -*-

"""
    Project Euler - problem 9
"""

__author__ = "ryan faulkner"
__date__ = "11/6/2012"
__license__ = "GPL (version 2 or later)"

import math

def find_pythagorean_triplet(n):
    k = int(math.ceil(n**0.5))
    for a in xrange(1,k+1):
        for b in xrange(a,k+1):
            for c in xrange(b,k+1):
                # print " ".join(["triplet values = ", str(a),str(b),str(c)])
                if a**2 + b**2 - c**2 == 0 and a+b+c == 1000:
                   print " ".join(["triplet values = ", str(a),str(b),str(c)])
                   return [a,b,c]
    return [0]

def main():
    print reduce(lambda x,y: x*y, find_pythagorean_triplet(1000**2))

if __name__ == "__main__":
    main()