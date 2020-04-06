# -*- coding: cp1252 -*-
#
# This file is part of Zhockon Platform project.
# 
# Copyright (C) 2009 William Oliveira de Lagos <williamx64@gmail.com>
# Copyright (C) 2003 Nilo Menezes <nilo@nilo.pro.br>
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

import pygame.mixer

pygame.mixer.init()

sons = {}

def carregue(nome,local):
	global sons
	if not sons.has_key(nome):
		try:
			sons[nome] = pygame.mixer.Sound(local)
		except:
			pass
	return sons[nome]

def reproduza(nome):
	global sons
	try:
		sons[nome].play()
	except:
		pass
	
def canais(nome=None):
	global sons
	if nome == None:
		return pygame.mixer.get_num_channels()
	else:
		return sons[nome].get_num_channels()

