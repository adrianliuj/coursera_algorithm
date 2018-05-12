# -*- coding: utf-8 -*-
"""
Created on Thu Mar  1 11:51:10 2018

@author: heyad
"""

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