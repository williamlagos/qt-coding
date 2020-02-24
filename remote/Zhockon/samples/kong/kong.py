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

import os, sys
zhockon_folder = os.path.abspath(os.path.join("..","..","..")) 
sys.path.append(zhockon_folder)
from zhockon.python.platform import *

branch = os.path.join(os.path.abspath(""),"frames","")
iarray = ["%s0.png"%(branch),"%s1.png"%(branch),"%s2.png"%(branch)]
animation = SDLHandler([800,600])
animation.create_element("%s1.png"%(branch),iarray)
animation.create_element("%s1.png"%(branch),iarray,[256,192],[0,1])
animation.create_element("%s1.png"%(branch),iarray,[480,320])

while 1:
	animation.draw_background("%sbg.png"%(branch))
	for event in pygame.event.get():
		if event.type == QUIT:
			sys.exit()
	#animation.start_sync()
	animation.update()
	#animation.stop_sync()