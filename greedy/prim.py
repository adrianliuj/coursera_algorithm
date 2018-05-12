# -*- coding: utf-8 -*-
"""
Created on Fri Mar  2 09:20:08 2018

@author: heyad
"""

from queue import PriorityQueue

class Edge:
    def __init__(self,v1,v2,weight):
        self.v1 = v1
        self.v2 = v2
        self.weight = weight
    def __lt__(self,other):
        return self.weight < other.weight
    
def readin(filename):
    f = open(filename)
    line = f.readline()
    num_of_vertice,num_of_edges = int(line.split()[0]),int(line.split()[1])
    graph = [[]]*num_of_vertice
    while True:
        line = f.readline()
        if not line:
            break
        v1,v2,weight = int(line.split()[0]),int(line.split()[1]),int(line.split()[2])
        graph[v1-1] = graph[v1-1] + [[v2,weight]]
        graph[v2-1] = graph[v2-1] + [[v1,weight]]
        
    return graph
        

graph = readin('graph.txt')
total = 0
PQ = PriorityQueue()
vertices = {}
#initialize
vertices[1] = 0
for edge in graph[0]:
    PQ.put(Edge(1,edge[0],edge[1]))
    
while not PQ.empty():
    safe_edge = PQ.get()
    if not safe_edge.v1 in vertices:
        vertices[safe_edge.v1] = safe_edge.weight
        total += safe_edge.weight
        for edge in graph[safe_edge.v1-1]:
            PQ.put(Edge(safe_edge.v1,edge[0],edge[1]))
    elif not safe_edge.v2 in vertices:   
        vertices[safe_edge.v2] = safe_edge.weight
        total += safe_edge.weight
        for edge in graph[safe_edge.v2-1]:
            PQ.put(Edge(safe_edge.v2,edge[0],edge[1]))
            
print(total)