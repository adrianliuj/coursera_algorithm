# -*- coding: utf-8 -*-
"""
Created on Wed Mar 28 21:24:10 2018

@author: heyad
"""

import readin
import unionfind


graph = readin.Graph()

graph.readin('cluster.txt')
size = graph.size

u = unionfind.unionfind(500)

for i in range(size-4):
    edge = graph.graph.get()
    v1 = edge.vertice1
    v2 = edge.vertice2
    u.unite(v1-1,v2-1)
    



