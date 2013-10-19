#/env/bin/python
# -*- coding: utf-8 -*-

"""
    Project Euler - problem 14
"""

__author__ = "ryan faulkner"
__date__ = "12/3/2012"
__license__ = "GPL (version 2 or later)"

import sys
from datetime import datetime, timedelta

def main():
    end = datetime(year=2000, month=12, day=31)
    cur_time = datetime(year=1901, month=1, day=1)
    day = timedelta(days=1)

    count = 0

    while cur_time <= end:
        if int(cur_time.day) == 1 and int(cur_time.weekday()) == 6:
            count += 1
        cur_time += day
    print count

if __name__ == "__main__":
    sys.exit(main())