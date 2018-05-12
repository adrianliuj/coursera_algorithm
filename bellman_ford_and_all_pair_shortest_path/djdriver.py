# -*- coding: utf-8 -*-
"""
Created on Mon Mar 26 20:59:56 2018

@author: heyad
"""
import readin as txtread
from queue import PriorityQueue
import Node


def dijikstra(graph,start):
    indices = {start:0}
    PQ = PriorityQueue()
    for initial_node in graph[start-1]:
        PQ.put(initial_node)
    
    while not PQ.empty():
        node = PQ.get()
        if not node.indice in indices:
            indices[node.indice] = node.score
            for j in range(len(graph[node.indice-1])):
                PQ.put(Node.Node(graph[node.indice-1][j].indice,graph[node.indice-1][j].score + node.score))
    return indices          
filename = 'test.txt'#edges = bf.bellman_ford(graph)
graph = txtread.readin(filename)
result = dijikstra(graph,1)