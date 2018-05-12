# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 16:17:47 2018

@author: heyad
"""

def readin(filename):
    f = open(filename)
#    read the first line to get the number of vertices and edges
    firstline = f.readline()
    num = int(firstline)
    nodes = []
    
    for i in range(num):
        weight = int(f.readline())
        nodes.append(weight)
    return nodes
        
