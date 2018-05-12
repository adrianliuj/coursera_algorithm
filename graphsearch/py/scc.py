# -*- coding: utf-8 -*-
"""
Created on Fri Mar  2 16:05:27 2018

@author: heyad
"""

def dfs2(reverse_graph,visited,order,size_scc):
    stack = []
    while not len(order) == 0:
        while visited[order[-1]]:
            order.pop()
            if len(order) == 0:
                break
        stack.append(order[-1])
        visited[order[-1]] = True
        current_scc = 0
        while not len(stack) == 0:
            head = stack[-1]
            i = 0
            new_push = False
            while True:
                if len(reverse_graph[head-1]) == 0 or len(reverse_graph[head-1]) == i:
                    break
                end = reverse_graph[head-1][i]
                if not visited[end]:
                    stack.append(end)
                    visited[end] = True
                    new_push = True
                    break
                i += 1
            if not new_push:
                current_scc += 1
                stack.pop()
        size_scc.append(current_scc)
        print(current_scc)

        
#def readin2(filename,visited):
#    f = open(filename)
#    while True:
#        line = f.readline()
#        if not line:
#            return
#        start,end = int(line.split()[0]),int(line.split()[1])
#        visited[start] = False
#        visited[end] = False
#        
#visited = {}
#readin2('scc.txt',visited)
size_scc = []
dfs2(reverse_graph,visited,order,size_scc)