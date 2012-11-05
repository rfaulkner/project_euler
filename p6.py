#/env/bin/python
# -*- coding: utf-8 -*-
"""
    Project Euler - problem 6
"""
__author__ = "ryan faulkner"
__date__ = "11/4/2012"
__license__ = "GPL (version 2 or later)"

import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def main():
    n = 100
    sum = 0
    prod_sum = reduce(lambda x,y: x+y, range(1,n+1))
    for k in xrange(1,n+1):
        sum += prod_sum * k - k**2
    print sum

if __name__ == "__main__":
    main()