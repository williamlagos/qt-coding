/*
 * This file is part of Zhockon Platform project.
 * 
 * Copyright (C) 2009-2011 William Oliveira de Lagos <william.lagos1@gmail.com>
 *
 * Zhockon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Zhockon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Zhockon.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <zhockon.h>
using namespace Zhockon;

int main(int argc,char* argv[])
{
	createGame("Hello World");
	SDL *sdlHandler = new SDL("HW",0,0);
	sdlHandler->baseMove();
	Python p("Test");
	p.helloPython();
	return 0;
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	main(0,NULL);
	return 0;
}
#endif