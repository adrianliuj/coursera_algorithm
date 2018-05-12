# -*- coding: utf-8 -*-
"""
Created on Thu Mar  1 09:04:09 2018

@author: heyad
"""

filename = 'array.txt'
size = 1000000
ht = {}
arr = [None]*size
i = 0
count =0
low = -10000
high = 10000
and_set = set()

f = open(filename)
while True:
    line = f.readline()
    if line:
        ht[int(line)] = i
        arr[i] = int(line)
        i+=1
    else:
        break    

arr.sort()

for i in range(0,size):
    and_set = set(list(range(low-arr[i],high-arr[i]))) | and_set
    