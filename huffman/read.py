# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 16:17:47 2018

@author: heyad
"""
import Node
from queue import PriorityQueue

def readin(filename):
    f = open(filename)
#    read the first line to get the number of vertices and edges
    firstline = f.readline()
    num = int(firstline)
    nodes = PriorityQueue()
    
    for i in range(num):
        weight = int(f.readline())
        nodes.put(Node.Node(weight))
    return nodes
        
