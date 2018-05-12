# -*- coding: utf-8 -*-
"""
Created on Tue Feb 27 11:42:20 2018

@author: heyad
"""

class MinHeap:
    def __init__(self):
        self.heapList = [0]
        
    def floatUp(self,i):
      while i>1:
          if self.heapList[i]<=self.heapList[i//2]:
              self.heapList[i],self.heapList[i//2] = self.heapList[i//2],self.heapList[i]
          i = i//2
          
    def sinkDown(self,i):
        while 2*i<= len(self.heapList)-1:
            if 2*i<len(self.heapList)-1:
                if self.heapList[i] > min(self.heapList[2*i],self.heapList[2*i+1]):
                    if self.heapList[2*i]<=self.heapList[2*i+1]:
                        self.heapList[i],self.heapList[2*i] = self.heapList[2*i],self.heapList[i]
                        i*=2
                    else:
                        self.heapList[i],self.heapList[2*i+1] = self.heapList[2*i+1],self.heapList[i]
                        i = 2*i+1
                else:
                    return
            elif 2*i == len(self.heapList)-1:
                if self.heapList[i] > self.heapList[2*i]:
                    self.heapList[i],self.heapList[2*i] = self.heapList[2*i],self.heapList[i]
                else:
                    return 
                
    def insert(self,num):
        self.heapList.append(num)
        self.floatUp(len(self.heapList)-1)
              
    def delMin(self):
        top = self.heapList[1]
        self.heapList[1],self.heapList[-1] = self.heapList[-1],self.heapList[1]
        self.heapList.pop()
        self.sinkDown(1)
        return top
        
    def top(self):
        return self.heapList[1]
    
min_heap = MinHeap()    
f = open('array.txt')
while True:
    line = f.readline()
    if len(line) == 0:
        break
    
    num = int(line)
    min_heap.insert(num)
            
f.close()

for i in range(0,len(min_heap.heapList)):
    print(min_heap.delMin())