#/env/bin/python
# -*- coding: utf-8 -*-
"""
    Project Euler - problem 7
"""
__author__ = "ryan faulkner"
__date__ = "11/4/2012"
__license__ = "GPL (version 2 or later)"

import math

def is_prime(k):
    """ Computes whether an integer is prime """
    cnt = 2
    limit = k

    # Find prime factors
    while cnt < limit:
        if not k % cnt:
            return False
        limit = math.ceil(k / cnt)
        cnt += 1

    return True

def main():
    sum = 0
    for i in xrange(2,2*10**6+1):
        if is_prime(i):
            sum += i
    print sum
if __name__ == "__main__":
    main()