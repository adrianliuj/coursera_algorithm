# -*- coding: utf-8 -*-
"""
Created on Sun Apr  1 08:06:04 2018

@author: heyad
"""

import read

nodes = read.readin('mwis.txt')
included = [False for i in range(len(nodes))]

max_list = [nodes[0],max(nodes[1],nodes[0])]
for i in range(2,len(nodes)):
    max_list.append(max(max_list[i-2]+nodes[i],max_list[i-1]))    

i = len(nodes)-1
while i>1:
    if max_list[i-2]+nodes[i] >= max_list[i-1]:
        included[i] = True
        i -= 2
    else:
        i -= 1    
if max_list[0] + nodes[2] >= max_list[1]:
    included[0] = True
else:
    includef[1] = True

sequence = [1,2,3,4,17,117,517,997] 
for i in sequence:
    print(sequence,':',included[i-1])
    