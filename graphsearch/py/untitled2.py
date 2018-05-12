# -*- coding: utf-8 -*-
"""
Created on Fri Mar  2 21:48:21 2018

@author: heyad
"""

def dfs(graph,visited,order):
    stack = [1]
    visited[1] = True
    while not len(stack) == 0:
        head = stack[-1]
        i = 0
        new_push = False
        while True:
            if len(graph[head-1]) == 0 or len(graph[head-1]) == i:
                break
            end = graph[head-1][i]
            if not visited[end]:
                stack.append(end)
                visited[end] = True
                new_push = True
                break
            i += 1
        if not new_push:
            order.append(stack.pop())




def readin(filename,graph,reverse_graph,visited):
    f = open(filename)
    while True:
        line = f.readline()
        if not line:
            return
        start,end = int(line.split()[0]),int(line.split()[1])
        graph[start-1] = graph[start-1] + [end]
        reverse_graph[end-1] = reverse_graph[end-1] + [start]
        visited[start] = False
        visited[end] = False
 
size = 8785714
graph = [[]]*size 
reverse_graph = [[]]*size
visited = {} 
order = []     
readin('scc.txt',graph,reverse_graph, visited)
dfs(graph,visited,order)