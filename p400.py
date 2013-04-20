
#/env/bin/python
# -*- coding: utf-8 -*-
"""
    Project Euler - problem 8
"""
__author__ = "ryan faulkner"
__date__ = "11/6/2012"
__license__ = "GPL (version 2 or later)"


class Node:
    def __init__(self,name, l=None,p=None,r=None):
        self.__name = name
        self.__l = l
        self.__r = r
        self.__p = p

    @property
    def name(self): return self.__name
    @property
    def l(self): return self.__l
    @l.setter
    def l(self, val):
        if hasattr(val,'l'):
            self.__l = val
            val.p = self
        elif val is None:
            self.__l = val
        else: raise Node

    @property
    def r(self): return self.__r
    @r.setter
    def r(self, val):
        if hasattr(val,'p'):
            self.__r = val
            val.p = self
        elif val is None:
            self.__r = val
        else: raise Node

    @property
    def p(self): return self.__p
    @p.setter
    def p(self, val):
        if hasattr(val,'p'):
            if val.__l == self or val.__r == self:
                self.__p = val
        else: raise Node

def preorder(node, count):
    if not node is None:
        count += 1
        # print node.name
        count += preorder(node.l,0)
        count += preorder(node.r,0)
        return count
    else:
        return 0

def main():
    root_1 = Node("0")
    root_2 = Node("1",l=root_1)
    for i in xrange(1000):
        root = Node(str(i+2), l=root_2,r=root_1)
        root_1 = root_2
        root_2 = root

    count = preorder(root_2,0)
    print count

if __name__ == "__main__":
    main()