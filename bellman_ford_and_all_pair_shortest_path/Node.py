# -*- coding: utf-8 -*-
"""
Created on Mon Mar 26 19:45:01 2018

@author: heyad
"""


class Node(object):
  """docstring for  Node."""
  def __init__(self, indice, score=0):
    self.score = score
    self.indice = indice
  def __gt__(self, other):
    return other.score < self.score      