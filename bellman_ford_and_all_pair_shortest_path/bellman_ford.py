# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 16:15:29 2018

@author: heyad
"""
import Node
import math

def bellman_ford(graph):
#now edges is a list contains all the edges;
    edges = []
    for i in range(len(graph)):
        for node in graph[i]:
            edges.append([i+1,node.indice,node.score])
            
    current_length = [math.inf for i in range(len(graph))]
    current_length[-1] = 0
    
    for i in range(len(graph)-1):
        for edge in edges:
            if current_length[edge[1]-1] > current_length[edge[0]-1] + edge[2]:
                current_length[edge[1]-1] = current_length[edge[0]-1] + edge[2]
            
    for edge in edges:
        if current_length[edge[1]-1] > current_length[edge[0]-1] + edge[2]:
            return False
        
    return current_length
                
    