# -*- coding: utf-8 -*-
"""
Created on Sun Mar 25 16:12:08 2018

@author: heyad
"""

import readin as txtread
import bellman_ford as bf
import dijikstra as dj
import math

#readin files
filename = 'g3.txt'#edges = bf.bellman_ford(graph)
graph = txtread.readin(filename)

#add an extra node
extra_node = []
for i in range(len(graph)):
    extra_node.append(bf.Node.Node(i+1,0))
    
graph.append(extra_node)

#do bellman_ford
bfscore = bf.bellman_ford(graph)

if bfscore:
    #make all the edge length to be possitive
    current_min = math.inf
    graph.pop()
    for i in range(len(graph)):
        head_score = bfscore[i]
        for node in graph[i]:
            node.score = node.score + head_score - bfscore[node.indice-1]
    
    #do dijikstra for n times
    result = []
    for i in range(len(graph)):
        dj_dict = dj.dijikstra(graph,i+1)
        destnations = list(dj_dict.keys())
        scores = list(dj_dict.values())
        for j in range(len(scores)):
            source = i+1
            dest = destnations[j]
            scores[j] = scores[j] + bfscore[dest-1] - bfscore[source-1]
            result.append([source,dest,scores[j]])
            if scores[j] < current_min:
                current_min = scores[j]
    print(current_min)     
    
else:
    print('There are negative cycles')


