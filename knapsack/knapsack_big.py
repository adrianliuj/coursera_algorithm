# -*- coding: utf-8 -*-
"""
Created on Sun Apr  1 17:35:29 2018

@author: heyad
"""

import read

data = read.Data()
data.readin('knapsack_big.txt')

capacity = data.knapsack_size
value = 0
while capacity >= 0:
    if 