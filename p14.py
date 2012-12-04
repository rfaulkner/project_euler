#/env/bin/python
# -*- coding: utf-8 -*-

"""
    Project Euler - problem 14
"""

__author__ = "ryan faulkner"
__date__ = "12/3/2012"
__license__ = "GPL (version 2 or later)"

import sys

def compute_path_len(k, max_val=0):
    steps = 0
    while not k == 1:
        if k % 2 == 0:
            k /= 2
        else:
            k *= 3
            k += 1
        steps += 1

        if max_val and steps > max_val:
            break
    return steps

def find_seq_lengths(range_min, range_max):

    max_len = 0
    range_len = range_max - range_min + 1

    indices = set(range(range_len))
    current = range(range_min, range_max+1)
    curr_len = [0] * range_len
    end_count = 0

    ind_iter = indices.__iter__()

    while end_count < range_len - 1:

        try:
            curr_ind = ind_iter.next()
        except StopIteration:
            ind_iter = indices.__iter__()
            curr_ind = ind_iter.next()

        if curr_len[curr_ind] <= max_len:

            steps = 0
            n = current[curr_ind]

            # keep going until either:
            #   1) the sequence terminates at 1
            #   2) picks up another completed sequence
            #   3) exceeds the current maximum

            while 1:

                if n >= range_min and n <= range_max and n-range_min not in indices:
                    curr_len[curr_ind] += curr_len[n-range_min] + steps

                    ind_iter = None
                    indices.remove(curr_ind)
                    ind_iter = indices.__iter__()

                    end_count += 1
                    if curr_len[curr_ind] > max_len:
                        max_len = curr_len[curr_ind]
                    break

                # iterate
                if n % 2 == 0: n /= 2
                else: n = n * 3 + 1
                steps += 1

                if n == 1:
                    curr_len[curr_ind] += steps

                    ind_iter = None
                    indices.remove(curr_ind)
                    ind_iter = indices.__iter__()

                    end_count += 1
                    if curr_len[curr_ind] > max_len:
                        max_len = curr_len[curr_ind]
                    current[curr_ind] = n
                    break

                if steps + curr_len[curr_ind] >= max_len:
                    curr_len[curr_ind] += steps
                    current[curr_ind] = n
                    max_len += 1
                    break

    # compute the path length of the final index
    ind = int(indices.pop())
    curr_len[ind] += compute_path_len(current[ind])
    print 'max seq len is ' + str(max(curr_len)) + ' for ' + str(curr_len.index(max(curr_len)) + range_min)
    return

def main():
    # print compute_path_len(95)
    segement_len = 10**5
    for i in range(10):
         find_seq_lengths(i * segement_len + 1, (i + 1) * segement_len)

if __name__ == "__main__":
    sys.exit(main())