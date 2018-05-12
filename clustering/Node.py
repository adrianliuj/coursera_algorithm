# -*- coding: utf-8 -*-
"""
Created on Mon Mar 26 19:45:01 2018

@author: heyad
"""


class Node(object):
  """docstring for  Node."""
  def __init__(self, vertice1,vertice2, distance):
      self.vertice1 = vertice1
      self.vertice2 = vertice2
      self.distance = distance
  def __gt__(self, other):
    return other.distance <= self.distance    