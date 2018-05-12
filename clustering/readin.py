# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 16:17:47 2018

@author: heyad
"""
import Node as nd
from queue import PriorityQueue

#here node represents an edge
class Graph:
    def __init__(self):
        self.graph = PriorityQueue()
        self.size = 0

    def readin(self,filename):
        f = open(filename)
    #    read the first line to get the number of vertices and edges
        firstline = f.readline()
        self.size = int(firstline)  
    #   readin the edges and store it in a list

        while(True):
            line = f.readline()
            if not line:
                break
            line = line.split()
    #        head = line[0]  tail = line[1]      weight = line[2]
            self.graph.put(nd.Node(int(line[0]),int(line[1]),int(line[2])))