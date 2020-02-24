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

import pygame,OpenGL,os
from OpenGL.GL import *
from OpenGL.GLU import *
from pygame.locals import *

images = {}
modes = [(640,480),(800,600),(1024,768),(1280,800)]
screen = None

def load_graphics(name,local):
	global images,screen
	local = os.path.abspath(os.path.join("euphoria",local))
	if not images.has_key(name):
		images[name] = pygame.image.load(local).convert(screen)
	return images[name]
def get_image(name):
	global images
	return images[name]

class OGL:
	def test_opengl():
		try:
			raise NotImplementedError
		except NotImplementedError, e:
			print "Option not already implemented."
class Camera:
    def __init__(self):
        try:
            raise NotImplementedError
        except NotImplementedError, e:
            print "Option not already implemented."
class Depth:
    def __init__(self):
        pass
    def draw_polygon(self,points,colors,verts,edges):
        allpoints = zip(points,colors)
        glBegin(GL_QUADS)
        for face in verts:
            for vert in face:
                pos, color = allpoints[vert]
                glColor3fv(color)
                glVertex3fv(pos)
        glEnd()
        glColor3f(1.0, 1.0, 1.0)
        glBegin(GL_LINES)
        for line in edges:
            for vert in line:
                pos, color = allpoints[vert]
                glVertex3fv(pos)
        glEnd()

class Image:
	'''Euphoria Image Class'''
	image = None
	posx = 0
	posy = 0
	def __init__(self,name,local):
		'''Initialize the image'''
		self.load_image(name,local)
	def image_position(self,x,y):
		self.image.set_colorkey(self.image.get_at((x,y)))
	def load_image(self,name,local):
		'''Load image attributes to class'''
		self.image = load_graphics(name,local)
		self.posx = self.image.get_width()
		self.posy = self.image.get_height()
	def position(self):
		'''Returns position of image'''
		return self.posy,self.posx
	def height(self):
		'''Height of image'''
		return self.posy
	def width(self):
		'''Width of image'''
		return self.posx
class Video:
	'''Euphoria Video Class'''
	def __init__(self,size,fullscreen = False):
		'''Initialize the video'''
		pygame.init()
		self.notify = []
		self.mode(size,fullscreen)
		self.imfont = pygame.font.Font(None,24)
		self.actual_mode = 1
	def add(self,function):
		'''Add notification'''
		self.notify.append(function)
	def notificate(self,message):
		'''Print notifications'''
		for m in self.notify:
			m(message)
	def mode(self,size,fullscreen = None):
		'''Set screen mode in size and type'''
		global screen
		self.size = size
		if fullscreen == None:
			fullscreen = self.fullscreen
		else:
			self.fullscreen = fullscreen
		flags = DOUBLEBUF | HWSURFACE
		if fullscreen:
			flags = flags | FULLSCREEN
		self.screen = pygame.display.set_mode(size,flags)
		screen = self.screen
		self.notificate(0)
	def next_mode(self):
		'''Get next screen mode'''
		self.actual_mode = (self.actual_mode + 1) % len(modes)
		self.mode(modes[self.actual_mode])
	def previous_mode(self):
		'''Get previous screen mode'''
		self.actual_mode -= 1
		if self.actual_mode < 0:
			self.actual_mode = len(modes) - 1
		self.mode(modes[self.actual_mode])
	def toggle_fullscreen(self,yes = None):
		'''Turn into fullscreen'''
		if sim == None:
			sim = ~ self.fullscreen
		self.mode(self.size, yes)
	def update(self):
		'''Animate the display'''
		pygame.display.flip()
	def clear(self, color = (0,0,0,0)):
		'''Clear the screen with black'''
		self.screen.fill(color)
	def draw(self,image,position):
		'''Draw image in screen'''
		self.screen.blit(image,position)
	def font(self,size):
		'''Change font size of text'''
		self.imfont = pygame.font.Font(None,size)
	def text(self,message,color):
		'''Print message to the screen'''
		image = self.imfont.render(message,True,color)
		return image
	def title(self,name):
		'''Set the window title'''
		pygame.display.set_caption(name)
