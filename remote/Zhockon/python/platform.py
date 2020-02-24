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

import sys
from graphics import *
from elements import *
from physics import *

class SDLHandler:
	def __init__(self,size):
		'''Initialize the game'''
		self.elements = []
		self.video = Video(size)
		self.video.add(self.reconfigure_video(0))
		self.width = size[0]
		self.height = size[1]
		self.gamespace = Space()
		pygame.display.set_caption("Zhockon SDL")
	def start_sync(self):
		'''Controls the game time'''
		self.gamespace.start_sync()
	def stop_sync(self):
		'''Stops controlling the time'''
		self.gamespace.stop_sync()
	def reconfigure_video(self, message):
		''''''
		if message == 0:
			self.width = self.video.size[0]
			self.height = self.video.size[1]
	def create_element(self, image, anim, position = [0,0], speed = [1,0]):
		'''Add a element in the game scenario'''
		element = Element(image,anim,position)
		element.which_speed(speed)
		self.elements.append(element)
		element.space = self
	def remove_element(self, element):
		'''Remove a element in the game scenario'''
		if element.type != None:
			self.collisions[element.type].remove(element)
		self.elements.remove(element)
	def draw_image(self,image,position=[0,0]):
		'''Draw a image in the game screen'''
		img = Image(image,image).image
		if position[0] == -1: position[0] = (self.width - image.get_width()) /2
		if position[1] == -1: position[1] = (self.height - image.get_height()) /2
		self.video.draw(img, position)
	def write_text(self, position, text, color, size = None):
		'''Write a text in the game screen'''
		if size != None:
			self.video.font(size)
		image = self.video.text(text,color)
		if position[0] == -1: position[0] = (self.width - image.get_width()) /2
		if position[1] == -1: position[1] = (self.height - image.get_height()) /2
		self.draw(position, image)
	def draw_background(self,figure):
		'''Draw a background image in the game screen'''
		self.video.clear()
		image = Image("bkg",figure)
		self.video.draw(get_image("bkg"),(0,0))
	def draw_elements(self):
		'''Draw the added elements to game display''' 
		for element in self.elements:
			if element.visible:
				self.video.screen.blit(element.image, element.pos)
	def update(self):
		'''Animate the game'''
		#self.video.clear()
		objects = pygame.sprite.RenderUpdates(self.elements)
		for element in self.elements:
			if len(self.gamespace.handle_collisions(element,objects)) > 1:
				if ~element.collided:
					element.reverse_speed()
				element.collided = True
		objects.update(); objects.draw(self.video.screen)
		self.video.update()
