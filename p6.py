#/env/bin/python
# -*- coding: utf-8 -*-
"""
    Project Euler - problem 5
"""
__author__ = "ryan faulkner"
__date__ = "11/4/2012"
__license__ = "GPL (version 2 or later)"

import math

def get_prime_factors(k):
    """ Computes whether an integer is prime """
    cnt = 2
    limit = k
    primes = []

    # Find prime factors
    while cnt < limit:
        if not k % cnt:
            primes.append(k)
            limit = math.ceil(limit / cnt)
        cnt += 1

    # The number is prime
    if not primes:
        primes = [k]
    return primes

def reduce_by_even_factors(k, factor_list):
    """ Determines if factor_list contains factors of k. Returns factor. """
    div = k
    for f in factor_list:
        if div == 1: return 1
        if not div % f:
            div /= f
    return div

def main():
    factors = []
    for i in xrange(2,20):
        f = reduce_by_even_factors(i,factors)
        if f > 1:
            factors.extend(get_prime_factors(f))

    print reduce(lambda x,y: x*y, factors)

if __name__ == "__main__":
    main()