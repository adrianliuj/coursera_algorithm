# -*- coding: utf-8 -*-
"""
Created on Mon Feb 26 11:30:56 2018

@author: heyad
"""

def quickSort(arr,low,high):
    if (high-low>1):
        pivot = arr[low]
        pos = low
        for i in range(low+1,high):
            if arr[i]<pivot:
                arr[i],arr[pos+1] = arr[pos+1],arr[i]
                pos = pos+1
        
        arr[pos],arr[low] = arr[low],arr[pos]
        quickSort(arr,low,pos)
        quickSort(arr,pos+1,high)       
            
#arr = [5,4,3,2,1]
#quickSort(arr,0,5)  
f = open('array.txt')
arr = []
while True:
    line = f.readline()
    if len(line) == 0:
        break
    
    arr.append(int(line))

f.close()
quickSort(arr,0,len(arr)-1)