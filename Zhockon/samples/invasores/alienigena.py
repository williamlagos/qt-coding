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

import os

import pygame.mixer
import naleatorios


from objetodojogo import *

import som

local = os.path.join("samples","invasores","")

class Alienigena(ObjetoDoJogo):
    def __init__(self, nome, pos, imagem,tipo="INIMIGO"):
        ObjetoDoJogo.__init__(self,nome, pos, imagem, tipo)
        self.iy = 3 + naleatorios.faixa(0,5)
        self.ix = 3 + naleatorios.faixa(0,5)
        self.resistencia = 50
        self.dano = 10
        self.valor = 10
        som.carregue("ALIENIGENA_EXP","%ssons/boom.wav"%(local))

    def move(self, direcao):
        pass
            
    def respire(self):
        #self.ix = sinal(self.ix) * whrandom.randrange(3,10)
        ObjetoDoJogo.respire(self)
        if self.resistencia<=0:
            som.reproduza("ALIENIGENA_EXP")
        self.pos[0] += self.ix
        self.pos[1] += self.iy
        if self.pos[0]+self.lx > self.universo.largura or self.pos[0]<0:
            if self.pos[0]<0:
                self.pos[0]=0
            else:
                self.pos[0] = self.universo.largura-self.lx
            self.ix *= -1
        if self.pos[1]+self.ly > self.universo.altura or self.pos[1]<0:
            if self.pos[1]<0:
                self.pos[1]=0
            else:
                self.pos[1] = self.universo.altura-self.ly
            self.iy *= -1
