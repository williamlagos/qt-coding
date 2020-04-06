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

from objetodojogo import *

class ObjetosBonus(ObjetoDoJogo):
    """
        Classe utilizada para representar os objetos de recarga de municao ou resistencia
    """
    def __init__(self, nome, pos, imagem=None,tipo="INIMIGO"):
        ObjetoDoJogo.__init__(self,nome, pos, imagem,tipo)
        self.iy = 5
        self.ix = 0
        self.resistencia = 1000
        self.dano = 0
        self.carga = 0
        
    def respire(self):
        ObjetoDoJogo.respire(self)
        self.pos[1] += self.iy
        if self.pos[1]>self.universo.altura:
            self.resistencia = 0
            self.visivel = 0
            try:
                self.universo.objetos.remove(self)
            except:
                pass
                
    def colida(self, objeto):
        if objeto.nome == "Nave":
            self.resistencia = 0
