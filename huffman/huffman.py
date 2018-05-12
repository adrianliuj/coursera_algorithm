# -*- coding: utf-8 -*-
"""
Created on Sat Mar 31 21:09:17 2018

@author: heyad
"""

import read
import Node

huff = read.readin('huffman.txt')

for i in range(999):
    node1 = huff.get()
    node2 = huff.get()
    
    parent_node = Node.Node(node1.weight + node2.weight,min(node1.height,node2.height)+1,node1,node2)
    huff.put(parent_node)
    
root = huff.get()
depth = root.height


        
