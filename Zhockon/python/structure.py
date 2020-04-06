#
# This file is part of Zhockon Platform project.
# 
# Copyright (C) 2009-2011 William Oliveira de Lagos <william.lagos1@gmail.com>
#
# Zhockon is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Zhockon is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Zhockon.  If not, see <http://www.gnu.org/licenses/>.
#

import os, sys, collections

class Map(object):
    """ Map wraps a dictionary. It is essentially an abstract class from which
    specific multimaps are subclassed. """
    def __init__(self):
        self._dict = {}       
    def __repr__(self):
        return "%s(%s)" % (self.__class__.__name__, repr(self._dict))
    __str__ = __repr__
    def __getitem__(self, key):
        return self._dict[key]
    def __setitem__(self, key, value):
        self._dict[key] = value
    def __delitem__(self, key):
        del self._dict[key]
    def remove(self, key, value):
        del self._dict[key]
    def dict(self):
        """ Allows access to internal dictionary, if necessary. Caution: multimaps 
        will break if keys are not associated with proper container."""
        return self._dict

class ListMultimap(Map):
    """ ListMultimap is based on lists and allows multiple instances of same value. """
    def __init__(self):
        self._dict = collections.defaultdict(list)
    def __setitem__(self, key, value):
        self._dict[key].append(value)
    def remove(self, key, value):
        self._dict[key].remove(value)

class DictMultimap(Map):
    """ DictMultimap is based on dicts and allows fast tests for membership. """
    def __init__(self):
        self._dict = collections.defaultdict(dict)
    def __setitem__(self, key, value):
        self._dict[key][value] = True
    def remove(self, key, value):
        del self._dict[key][value]


class Node:
        def __init__(self,object):
                self.object = object
                self.father = None
                self.left = None
                self.right = None
        def to_father(self,node):
                self.father = node
        def to_left(self,node):
                self.left = node
        def to_right(self,node):
                self.right = node
        def from_father(self):
                return self.father
        def from_right(self):
                return self.right
        def from_left(self):
                return self.left
        def get_item(self):
                return self.object
        def set_item(self,item):
                self.object = item

class Module(object):
	def __init__(self,n,s):
		self.name = n
		self.status = s

class Path(Module):
        def __init__(self,path,layer=1,spath="",):
                if(layer == 2):
                        self.path = os.path.abspath(os.path.join(path,spath))
                else:
                        self.path = os.path.abspath(path)
        def set_path(self,path):
                self.path = path
        def another_path(self,apath):
                self.path = os.path.join(self.path,"",apath)
        def get_path(self):
                return self.path
        def get_layer(self):
                return self.layer
        def __cmp__(self,other):
                try:
                        if(self.path > other.getPath()):
                                return 1
                        elif(self.path < other.getPath()):
                                return -1
                        else:
                                return 0
                except AttributeError, a:
                        return 1

class Tree:
        def __init__(self):
                self.cnt = 0
                self.root = Node(Path(""))
        def get_root(self):
                return self.root
        def add(self,object):
                self.add_node(object,self.root)
                self.cnt += 1
        def add_node(self,object,target):
                if(target == None):
                        node = Node(object)
                        node.to_father(target)
                        return node
                if(target.get_item().__cmp__(object) < 0):
                        node = self.add_node(object,target.from_right())
                        target.to_right(node)
                else:
                        node = self.add_node(object,target.from_left())
                        target.to_left(node)
                return target
        def count(self):
                return self.cnt
        def read(self):
                return self.read_nodes(self.root)
        def read_node(self,node):
                list = ""
                if(node != None):
                        left = node.from_left(); right = node.from_right()
                        list = node.get_item().get_path()+"\n"+self.read_node(left)+self.read_node(right)
                return list
        def search(self,object):
                return self.search_node(object,self.root)
        def search_node(self,object,target):
		if(object == None or target == None):
                        return None
                comp = target.get_item().__cmp__(object)
                if(comp == 0):
                        return target
                elif(comp > 0):
                        return self.search_node(object,target.from_left())
                else:
                        return self.search_node(object,target.from_right())
        def contains(self,object):
                node = self.search(object)
                return node != None
