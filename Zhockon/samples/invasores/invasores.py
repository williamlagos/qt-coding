#!/usr/bin/python
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

# Modulos do PyGame

import os

import pygame

import pygame.joystick
#import pygame.mixer
from pygame.locals import *

# Modulos do Python


# Modulos do jogo
from universo import *
from objetodojogo import *
from nave import *
from objetosbonus import *
from laser import *
from alienigena import *
from score import *

import video
import som
import naleatorios

# local = os.path.join("samples","invasores","")
local = ""
class Invasores:
    """
        Classe Invasores
        ----------------
        Esta classe e responsavel pelo jogo em si.
        Toda customizacao deve ser feita aqui
    """
    def __init__(self, tela):
        self.tamanho = tela
        self.universo = Universo(tela)
        self.video = self.universo.video
        self.carregue_imagens()
        self.jogador = Nave("Nave", [400,400], self.iJogador)
        self.placar = ScoreComFPS("Placar", [0,0])
        #self.placar = Score("Placar", [0,0])
        self.placar.jogador = self.jogador
        self.nova_partida()
        self.universo.quadros = 30
        self.universo.calcule_pontos = self.calcula_pontos
        self.video.titulo("Invasores")
        try:
            pygame.joystick.init()
            self.joystick = pygame.joystick.Joystick(0)
            self.joystick.init()
        except:
            pass
        self.sensibilidade_mouse = 5
        
    def carregue_imagens(self):
        self.iJogador = video.carregue("NAVE", "%snave2.bmp"%(local))
        self.iMissil = video.carregue("TIRO", "%slaser.png"%(local))
        self.iInimigo = video.carregue("INIMIGO", "%sinimigo2.bmp"%(local))
        self.iCaixaDeMisseis = video.carregue("CMISSIL", "%scaixademisseis.png"%(local))
        self.iCaixaDeResistencia = video.carregue("CRESITENCIA","%scaixaderesistencia.png"%(local))
        self.logo = video.Imagem("LOGO","%sInvasoreslogo.png"%(local))
        self.logo.ponto_croma(0,0)
        self.fim_de_jogo = video.Imagem("FIMDEJOGO","%sfimdejogo.png"%(local))
        self.fim_de_jogo.ponto_croma(0,0)
        
    def controle_joystick(self):
        pass
    
    def controle_mouse(self):
        pass
    
    def controle_teclado(self):
        pass
        
    def nova_partida(self):
        self.jogador.resistencia = 300
        self.jogador.misseis = 300
        self.jogador.pos = [400,400]
        self.jogador.ix = 0
        self.jogador.iy = 0
        self.universo.score=0
        self.universo.objetos=[]
        self.universo.adicione(self.jogador)
        self.universo.adicione(self.placar)
        self.placar.respire()

    def calcula_pontos(universo, a, b):
        if a.nome <> b.nome:
            a.colida(b)
            b.colida(a)
            return a.valor + b.valor
        else:
            return 0


    #def carregue_imagem(self,nome):
    #   return pygame.image.load(nome).convert()

    def atira(self):
        if self.jogador.misseis > 0:
            self.universo.adicione(Laser("tiro",
                                    [self.jogador.pos[0]-15,
                                self.jogador.pos[1]-15], self.iMissil))
            self.universo.adicione(Laser("tiro",
                                    [self.jogador.pos[0]+self.jogador.lx,
                                    self.jogador.pos[1]-15], self.iMissil))
            self.jogador.misseis -=2


    def cria_alienigena(self):
        self.universo.adicione(Alienigena("Inimigo",
                    [naleatorios.faixa(self.tamanho[0]),
                    naleatorios.faixa(self.tamanho[1]/2)],
                    self.iInimigo))

    def cria_municao(self):
        caixa_m = ObjetosBonus("CaixaDeMisseis",
                    [naleatorios.faixa(self.tamanho[0]),
                    10], self.iCaixaDeMisseis)
        caixa_m.carga=50
        self.universo.adicione(caixa_m)

    def cria_resistencia(self):
        caixa_r = ObjetosBonus("CaixaDeResistencia",
                    [naleatorios.faixa(self.tamanho[0]),
                    10], self.iCaixaDeResistencia)
        caixa_r.carga=50
        self.universo.adicione(caixa_r)

    def tela_inicial(self):
        self.universo.desenhe_fundo()
        #self.universo.escreva([-1,200], "INVASORES", (255,0,0),64)
        #self.video.desenhe(self.logo.imagem, (-1,-1))
        #logo = self.carregue_imagem("Invasoreslogo.png")
        #logo.set_colorkey(logo.get_at((0,0)), RLEACCEL)
        self.universo.desenhe([-1,-1],self.logo.imagem)
        self.universo.escreva([-1,450], "Pressione qualquer tecla para comecar", (255,255,0), 24)
        self.universo.atualize()
        while 1:
            #self.universo.inicie_sincronia()   
            for event in pygame.event.get():
                if event.type == QUIT:
                    return(1)
                if event.type==KEYDOWN or event.type==JOYBUTTONDOWN:
                    self.nova_partida()
                    return(0)
            #self.universo.finalize_sincronia()
            
    def tela_fim_de_jogo(self):
        #self.universo.escreva([-1,200], "Fim de Jogo", (255,0,0),64)
        #fim_de_jogo = self.carregue_imagem("fimdejogo.png")
        #fim_de_jogo.set_colorkey(fim_de_jogo.get_at((0,0)), RLEACCEL)
        self.universo.desenhe([-1,-1], self.fim_de_jogo.imagem)
        self.universo.escreva([-1,450], "Pressione [X] para sair ou [R] para jogar de novo", (255,255,0),24)
        self.universo.atualize()
        while 1:
            for event in pygame.event.get():
                if event.type == QUIT:
                    return(1)
                if event.type==KEYDOWN:
                    teclas = pygame.key.get_pressed()
                    if teclas[K_r]:
                        return(0)
                    elif teclas[K_x]:
                        return(1)
                if event.type==JOYBUTTONDOWN:
                                        if event.button % 2 == 0:
                                            return(0)
                                        else:
                                            return(1)

    def repeticao_do_jogo(self):
        self.universo.desenhe_fundo()
        sair = False
        c = 0
        while self.jogador.resistencia > 0 and not sair:
            c += 1
            self.universo.inicie_sincronia()
            event = pygame.event.poll()
            if event.type == QUIT:
                sair = True
            if event.type == MOUSEBUTTONDOWN:
                                #print "MOUSEBUTTONDOWN"
                                #print event.pos #, event.buttons
                self.atira()
            if event.type == MOUSEBUTTONUP:
                                pass
                                #print "MOUSEBUTTONUP"
                                #print event.pos, event.buttons
            if event.type == MOUSEMOTION:
                                #print "MOUSEMOTION"
                                #print event.pos, event.rel, event.buttons
                                if event.rel[0] < -self.sensibilidade_mouse:
                                    self.jogador.move(1)
                                elif event.rel[0]> self.sensibilidade_mouse:
                                    self.jogador.move(0)
                                if event.rel[1] < -self.sensibilidade_mouse:
                                    self.jogador.move(3)
                                elif event.rel[1] > self.sensibilidade_mouse:
                                    self.jogador.move(2)
                                if event.buttons[0] == 1 and c % 3 == 0:
                                    self.atira()
            if event.type == JOYAXISMOTION:
                            print "JOYAXISMOTION"
                            print event.joy
                            print event.axis
                            print event.value
                            if event.axis == 0:
                                if event.value>0.0:
                                    self.jogador.ix=5
                                    #self.jogador.move(0)
                                    #print "direita"
                                if event.value<-1.0:
                                    self.jogador.ix=-5
                                    #self.jogador.move(1)
                                    #print "esquerda"
                            if event.axis == 1:
                                if event.value>0.0:
                                    self.jogador.iy=5
                                    #self.jogador.move(2)
                                    #print "baixo"
                                if event.value<-1.0:
                                    self.jogador.iy=-5
                                    #self.jogador.move(3)
                                    #print "cima"
            if event.type == JOYBALLMOTION:
                    print "JOYBALLMOTION"
                    pass
            if event.type == JOYHATMOTION:
                    print "JOYHATMOTION" 
                    pass
            if event.type == JOYBUTTONUP:
                    #print "JOYBUTTONUP"
                    pass
            if event.type == JOYBUTTONDOWN:
                    #print "JOYBUTTONDOWN"
                    self.atira()
                
            #if event.type ==  KEYDOWN:
            teclas = pygame.key.get_pressed()
            if teclas[K_LEFT]:
                self.jogador.move(1)
            if teclas[K_RIGHT]:
                self.jogador.move(0)
            if teclas[K_UP]:
                self.jogador.move(3)
            if teclas[K_DOWN]:
                self.jogador.move(2)
            if teclas[K_SPACE] and c%3==0:
                self.atira()
            if teclas[K_x] or teclas[K_ESCAPE]:
                sair = True
            if teclas[K_m]:
                self.jogador.misseis+=1000
            if teclas[K_r]:
                self.jogador.resistencia+=1000
            if teclas[K_KP_PLUS] or teclas[K_PLUS] or teclas[K_EQUALS]:
                self.video.proximo_modo()
            if teclas[K_KP_MINUS] or teclas[K_MINUS]:
                self.video.anterior_modo()
            if teclas[K_KP_MULTIPLY] or teclas[K_ASTERISK] or teclas[K_8]:
                self.video.faz_tela_cheia()
            if c % 30 == 0:
                for x in range(naleatorios.faixa(1, 2 +c / 300)):
                    self.cria_alienigena()
            if c % 300 == 0:
                self.cria_municao()
            if c % 600 == 0:
                self.cria_resistencia()
            self.universo.desenhe_fundo()
            self.universo.desenhe_objetos()
            self.universo.atualize()
            self.universo.finalize_sincronia()
        self.universo.desenhe_fundo()
        self.placar.respire()
        self.universo.desenhe_objetos()
        self.universo.atualize()
        if sair:
            return(1)
        else:
            return(0)

# Jogo - Principal
def jogo():
    try:
        # Cria o jogo em uma janela de 800x600
        jogo = Invasores([800,600])
        pygame.mouse.set_visible(0)
        # Loop principal do Jogo
        while 1:
            if jogo.tela_inicial():
                break;
            pygame.event.set_grab(1)    
            if jogo.repeticao_do_jogo():
                break;
            pygame.event.set_grab(0)
            if jogo.tela_fim_de_jogo():
                break;
    finally:
        pygame.display.quit()


#import profile
#profile.run("jogo()")
jogo()
