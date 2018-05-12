# -*- coding: utf-8 -*-
"""
Created on Mon Feb 26 21:32:17 2018

@author: heyad
"""

import heap_based
#the minheap is the bigger half, and the maxheap is the smaller half
min_heap = heap_based.MinHeap()
min_heap.buildHeap([])
        
max_heap = heap_based.MaxHeap()
max_heap.buildHeap([])

result = []

f = open('array.txt')

while True:
    line = f.readline()
    if len(line) == 0:
        break
    
    num = int(line)
    small_top = max_heap.top()
    large_top = min_heap.top()
    small_size = max_heap.currentSize
    large_size = min_heap.currentSize 
    
    if large_size - small_size == 1:
        if num < small_top:
            max_heap.insert(num)
        elif num > small_top and large_top > num:
            max_heap.insert(num)
        elif num > large_top:
            max_heap.insert(min_heap.delMin())
            min_heap.insert(num)
        mid = max_heap.top()
        result.append(mid)
        
    elif large_size - small_size == 0:
        if num < small_top:
            max_heap.insert(num)
            min_heap.insert(max_heap.delMin())
        elif num > small_top and large_top > num:
            min_heap.insert(num)
        elif num > large_top:
            min_heap.insert(num)
        mid = min_heap.top()
        result.append(mid)
            
f.close()

a = sum(result)%10000
