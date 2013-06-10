#
# This file is part of Zhockon Platform project.
# 
# Copyright (C) 2009-2010 William Oliveira de Lagos <williamx64@gmail.com>
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

import sys,os
zhockon_folder = os.path.abspath(os.path.join("..","..","..")) 
sys.path.append(zhockon_folder)
from zhockon.python.graphics import *

CUBE_POINTS = ((0.5, -0.5, -0.5),  (0.5, 0.5, -0.5),
               (-0.5, 0.5, -0.5),  (-0.5, -0.5, -0.5),
               (0.5, -0.5, 0.5),   (0.5, 0.5, 0.5),
               (-0.5, -0.5, 0.5),  (-0.5, 0.5, 0.5))

CUBE_COLORS = ((1, 0, 0), (1, 1, 0), (0, 1, 0), (0, 0, 0),
               (1, 0, 1), (1, 1, 1), (0, 0, 1), (0, 1, 1))

CUBE_QUAD_VERTS = ((0, 1, 2, 3), (3, 2, 7, 6), (6, 7, 5, 4),
                   (4, 5, 1, 0), (1, 5, 7, 2), (4, 0, 3, 6))

CUBE_EDGES = ((0,1), (0,3), (0,4), (2,1), (2,3), (2,7),
              (6,3), (6,4), (6,7), (5,1), (5,4), (5,7),)

'''Runs the demonstration'''
SDL = pygame
SDL.init()
SDL.display.set_mode((640,480), OPENGL|DOUBLEBUF)
OpenGL.GL.glEnable(GL_DEPTH_TEST)
glMatrixMode(GL_PROJECTION)
gluPerspective(45.0,640/480.0,0.1,100.0)
glTranslatef(0.0, 0.0, -3.0)
glRotatef(25, 1, 0, 0)
cube = Depth()
while 1:
	event = pygame.event.poll()
	if event.type == QUIT or (event.type == KEYDOWN and event.key == K_ESCAPE):
		break
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
	glRotatef(1, 0, 1, 0)                    
	cube.draw_polygon(CUBE_POINTS,CUBE_COLORS,CUBE_QUAD_VERTS,CUBE_EDGES)
	SDL.display.flip()
	SDL.time.wait(10)