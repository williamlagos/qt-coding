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

import pygame

clock = pygame.time.Clock()

from objetodojogo import *

class Score(ObjetoDoJogo):
    """
        Classe Score
        ------------
        Utilizada para exibir o score do jogo.
        Implementada como um objeto normal, podendo inclusive suportar
        animacao.
    """
    def __init__(self, nome, pos=[0,0]):
        ObjetoDoJogo.__init__(self,nome, pos)
        self.fonte = pygame.font.Font(None, 24)
        self.fonte.set_bold(True)
        self.jogador = None
        
    def respire(self):
        #ObjetoDoJogo.respire(self)
        self.imagem = self.fonte.render("Pontos: %d Resistencia: %d M�sseis: %d" % \
                                        (self.universo.score,
                                        self.jogador.resistencia,
                                        self.jogador.misseis),
                                        True, (255,255,0,0))
                                        
class ScoreComFPS(Score):
    def __init__(self, nome, pos):
        Score.__init__(self,nome,pos)
        
    def respire(self):
        #ObjetoDoJogo.respire(self)
        clock.tick(60)
        self.imagem = self.fonte.render("Pontos: %d Resistencia: %d M�sseis: %d FPS: %d" % \
                                        (self.universo.score,
                                        self.jogador.resistencia,
                                        self.jogador.misseis, clock.get_fps()),
                                        True, (255,255,0,0))        
    
