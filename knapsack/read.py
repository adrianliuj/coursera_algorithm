# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 16:17:47 2018

@author: heyad
"""
import Node
class Data(object):
    def __init__(self,item_list=[],knapsack_size=0):
        self.item_list = item_list
        self.knapsack_size = knapsack_size
            
    def readin(self,filename):
        f = open(filename)
    #    read the first line to get the number of vertices and edges
        firstline = f.readline()
        firstline = firstline.split()
        size = int(firstline[0])
        items = int(firstline[1])
        
        item_list = []
        
        for i in range(items):
            line = f.readline().split()
            item_list.append(Node.Node(int(line[1]),int(line[0])))
        self.item_list = item_list
        self.knapsack_size = size
            
