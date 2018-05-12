# -*- coding: utf-8 -*-
"""
Created on Wed Feb 28 19:17:24 2018

@author: heyad
"""

def hashFun(num):
    return num%1000000

def search(num,ht):
    index = hashFun(num)
    return num in ht[index]

filename = 'array.txt'
ht = [[]]*1000000
nums = []
count = 0

f = open(filename)
while True:
    line = f.readline()
    if line:
        line = int(line)
        index = hashFun(line)
        ht[index] = ht[index] + [line]
        nums.append(int(line))
    else:
        break       

for target in range(-100,100):
    for minus in nums:
        num = target-minus
        if search(num,ht):
            count += 1
            break
         
      