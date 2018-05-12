# -*- coding: utf-8 -*-
"""
Created on Thu Mar  1 11:51:10 2018

@author: heyad
"""

from queue import PriorityQueue

class Node(object):
  """docstring for  Node."""
  def __init__(self, indice, score=0):
    self.score = score
    self.indice = indice
  def __gt__(self, other):
    return other.score < self.score


#def readin(graph, filename, size):
#    f = open(filename)
#    i = 0
#    while True:
#        line = f.readline()
#        if not line:
#            break
#        
#        
        
    
    

def dijikstra(graph,start):
    indices = {start:0}
    PQ = PriorityQueue()
    for i in range(0,len(graph[start-1])):
        PQ.put(graph[start-1][i])
    
    while not PQ.empty():
        node = PQ.get()
        if not node.indice in indices:
            indices[node.indice] = node.score
            print(node.indice,node.score)
            for j in range(0,len(graph[node.indice-1])):
                PQ.put(Node(graph[node.indice-1][j].indice,graph[node.indice-1][j].score + node.score))

lis = [[Node(2,1),Node(3,4),Node(4,7)],[Node(4,9)],[Node(4,10)],[]]
dijikstra(lis,1)

#next step:
#pop the minimum from pq, 
#if this node is not visited
#insert pq into indice list and mark it as visited
#update its dijikstra score
#for all the arrows start from that indice,
#insert a new node into the heap