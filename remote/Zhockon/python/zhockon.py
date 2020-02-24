#
# This file is part of Zhockon Platform project.
# 
# Copyright (C) 2009-2010 William Oliveira de Lagos <william.lagos1@gmail.com>
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

import os, sys
from structure import Node,Path,Tree
from ConfigParser import *

class Zhockon:
	def __init__(self):
		self.tree = Tree()
		self.root = self.tree.root
		self.conf = ConfigParser()
	def read_config(self):
		try:
			self.conf.read("../config/zkn.cfg")
			file = open("../config/zkn.cfg","r")
			items = self.conf.items("Engine")
		except NoSectionError, e:
			print "Problems with zkn.cfg while reading configuration. Check the file."
			sys.exit(1)
		for i in items:
			if '2' in i[1]:
				self.tree.add(Path(i[1][:7],2,i[1][10:]))
			else:
				self.tree.add(Path(i[1]))
		file.close()
	def create_game(self,gname):
		try:
			self.conf.read("../config/zkn.cfg")
			file = open("../config/zkn.cfg","w")
			self.conf.set("Creation",gname[:4],gname)
			self.conf.write(file)
			os.mkdir(gname)
		except NoSectionError, e:
			print "Problems with zkn.cfg. Check the file."
			sys.exit(1)
		except OSError, e:
			print "Folder %s exists. Your game may have already been created."%(gname)
		finally:
			file.close()
	def delete_game(self,gname):
		try:
			raise NotImplementedError
		except NotImplementedError, e:
			print "Option not already implemented."
	def zhockon_some(self,object):
		node = self.search(object)
		sys.path.append(node.get_item().get_path())
	def zhockon_all(self):
		self.zhockon_all_nodes(self.root)
	def zhockon_all_nodes(self,node):
		if(node != None):
			sys.path.append(node.get_item().get_path())
			self.zhockon_all_nodes(node.from_left())
			self.zhockon_all_nodes(node.from_right())
	def zhockoff_some(self,name):
		cont = len(sys.path)-1
		spath = os.path.abspath(name)
		while cont != self.cnt:
			if(spath == sys.path[cont]):
				sys.path[cont] = ""
			cont -= 1

zkn = Zhockon()
zkn.read_config()
zkn.zhockon_all()
