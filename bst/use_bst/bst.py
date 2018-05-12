# -*- coding: utf-8 -*-
"""
Created on Tue Feb 27 17:05:22 2018

@author: heyad
"""

#ultimate goal: implement a red black tree 
class Node:
    def __init__(self, key = None, ltree = None, rtree = None):
        self.key = key
        self.ltree = ltree
        self.rtree = rtree
    
def search(root, val):
    if root == None:
        return None
    elif root.key == val:
        return root
    elif root.key > val:
        search(root.ltree,val)
    search(root.rtree,val)

def insert(root,val):
    if root == None:
        return Node(val)
    elif root.key >=val:
        if root.ltree != None:
            insert(root.ltree,val)
        else:
            root.ltree = Node(val)
    else:
        if root.rtree != None:
            insert(root.rtree,val)
        else:
            root.rtree = Node(val)
            
def inOrder(root):
    if root:
        inOrder(root.ltree)
        print (root.key)
        inOrder(root.rtree)
        
def findMax(root):
    current = root
    while current.rtree:
        current = current.rtree  
    return current

def findMin(root):
    current = root
    while current.ltree:
        current = current.rtree  
    return current

def delete(root,val):
    #if the node has no subtree, just delete
    #if the node has one subtree, use that subtree to fillup the vacance
    #if the node had two subtrees, swap(node,predecessor), then delete the node
    pass

def pred(root, node):
    pass
    #if the node has a left subtree, pred = max(ltree)
    #if the node doesnot have a left subtree, go up and search its parent until you turn left
    #for successor, its the same thing
    
r = Node(50)
insert(r,30)
insert(r,20)
insert(r,40)
insert(r,70)
insert(r,60)
insert(r,80)
inOrder(r)
print(findMax(r).key)