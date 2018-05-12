# -*- coding: utf-8 -*-
"""
Created on Thu Mar  1 22:06:13 2018

@author: heyad
"""
from queue import PriorityQueue
class Job:
    def __init__(self,weight,length):
        self.weight = weight
        self.length = length
        self.difference = weight-length
        self.ratio = weight/length
#     think this   
#    def __gt__(self,other):
#        if (self.difference == other.difference):
#            return self.weight < other.weight
#        return self.difference < other.difference
    def __gt__(self,other):
        return self.ratio < other.ratio
def readin(filename):
    f = open(filename)
    size = int(f.readline())
    jobs = [None]*size
    i = 0
    PQ = PriorityQueue()
    while True:
        line = f.readline()
        if not line:
            break
        job = Job(int(line.split()[0]),int(line.split()[1]))
        jobs[i] = job
        PQ.put(job)
        i += 1 
    return PQ
    #def readin(graph, filename, size):
#    f = open(filename)
#    i = 0
#    while True:
#        line = f.readline()
#        if not line:
#            break
#        
#        
     
jobs = readin('jobs.txt')   
time = 0
sum = 0
while not jobs.empty():
    job = jobs.get()
    time += job.length
    sum += time*job.weight

print (sum)