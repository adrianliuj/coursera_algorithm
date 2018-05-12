# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 16:17:47 2018

@author: heyad
"""
import Node as nd

#here node represents an edge

def readin(filename):
    f = open(filename)
#    read the first line to get the number of vertices and edges
    firstline = f.readline()
    v_and_e = firstline.split()
    vertices = int(v_and_e[0])
    edges = int(v_and_e[1])
    
#   readin the edges and store it in a list
    graph =[[] for i in range(vertices)]
    while(True):
        line = f.readline()
        if not line:
            break
        line = line.split()
#        head = line[0]  tail = line[1]      weight = line[2]
        graph[int(line[0]) -1].append(nd.Node(int(line[1]),int(line[2]))) 
    return graph
        
