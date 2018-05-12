# -*- coding: utf-8 -*-
"""
Created on Sun Apr  1 16:09:05 2018

@author: heyad
"""
import read

data = read.Data()
data.readin('knapsack1.txt')

results = [[0 for j in range(len(data.item_list)+1)] for i in range(data.knapsack_size + 1)]
for i in range(1,len(data.item_list)+1):
    for j in range(1,data.knapsack_size+1):
        item = data.item_list[i-1]
        if j-item.weight >= 0:
            results[j][i] = max(results[j][i-1],results[j-item.weight][i-1]+item.value)
        else:
            results[j][i] = results[j][i-1]

print(results[-1][-1])
