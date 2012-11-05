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
    p = 2
    latest = p

    n = 10001
    cnt = 0

    while cnt < n:
        if is_prime(p):
            latest = p
            cnt += 1
        p += 1
    print latest

if __name__ == "__main__":
    main()