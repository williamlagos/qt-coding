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

import time
import sys


class Temporizador:
    def __init__(self,nome, descricao, cabecalho=""):
        self.arquivo = open(nome, "w")
        self.arquivo.write("%s - %s\n\n" % (cabecalho, time.ctime()))
        self.descricao = descricao
    
    def inicio(self,valores=[]):
        self.valores = valores
        self.tempo_i = time.time()
        
    def fim(self):
        self.tempo_f = time.time()
        linha = ""
        for x in range(len(self.descricao)):
            linha += "%s=%s " % (self.descricao[x], self.valores[x])
        self.arquivo.write(("%10.5f - " % (self.tempo_f - self.tempo_i)) + linha+"\n")
    
    def __del__(self):
        self.arquivo.close()

