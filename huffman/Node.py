# -*- coding: utf-8 -*-
"""
Created on Mon Mar 26 19:45:01 2018

@author: heyad
"""
from queue import Queue

class Node(object):
  """docstring for  Node."""
  def __init__(self,weight,height=0,ltree=None,rtree=None):
    self.ltree = ltree
    self.rtree = rtree
    self.weight = weight
    self.height = height
  def __gt__(self, other):
    return other.weight < self.weight    

  def bfs(self):
    depth = 0
    queue = Queue()
    queue.put(self)
    while not queue.empty():
        root = queue.get()
        if root.ltree != None:
            queue.put(root.ltree)
        if root.rtree != None:
            queue.put(root.rtree)
    return depth  

#
#class Tree(object):
#    def __init__(self,weight,ltree=None,rtree=None):
#        self.weight = weight
#        self.ltree = ltree
#        self.rtree = rtree
#    