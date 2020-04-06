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

import urllib2,tarfile,shutil,os.path,sys,platform
from structure import Map,ListMultimap,DictMultimap
from ConfigParser import ConfigParser,NoSectionError
from subprocess import Popen, PIPE

class Reader:
	def __init__(self):
		self.modules = []
		self.version = []
		self.folders = []
		self.address = []
		self.archive = []
		self.names = []
		self.packages = ListMultimap();
	def read_config(self):
		conf = ConfigParser()
		sect = "Build"
		try:
			conf.read("../config/zkn.cfg")
			items = conf.items("Mirrors")
		except NoSectionError, e:
			print "Problems with Zhockon configuration. Check the zkn.cfg file."
			sys.exit(1)
		for f in conf.get(sect,"folders").split(","): self.folders.append(f)
		for m in conf.get(sect,"modules").split(","): self.modules.append(m)
		for v in conf.get(sect,"version").split(","): self.version.append(v)
		for a in conf.get(sect,"archive").split(","): self.archive.append(a)
		for n in conf.get(sect,"names").split(","): self.names.append(n)
		items.sort()
		for i in items:
			self.address.append(i[1])
	def update_versions(self):
		i = 0
		while i < len(self.address):
			self.address[i] = self.version[i].join(self.address[i].split("*"))
			self.folders[i] = self.version[i].join(self.folders[i].split("*"))
			i += 1
	def build_structure(self,modules,filename,folders,version,site):
		i = 0
		for pkg in self.names:
			self.packages[pkg] = modules[i]
			self.packages[pkg] = filename[i]
			self.packages[pkg] = folders[i]
			self.packages[pkg] = site[i]
			self.packages[pkg] = self.names[i]
			#self.packages[pkg] = version[i]
			i += 1

class Builder:
	def __init__(self):
		pass
	def next_package(self,pack):
		self.module = pack[0]
		self.archiv = pack[1]
		self.folder = pack[2]
		self.site = pack[3]
		self.modfol = pack[4]
	def download(self):
		if os.path.exists(self.archiv):
			print "%s is already downloaded."%(self.archiv)
			return True
		else:
			try:
				download = urllib2.urlopen("http://"+self.site)
			except urllib2.URLError:
				print "Server unavailable, unable to download %s file."%(self.archive)
				return False
			file = open(self.archiv,"w")
			file.write(download.read())
			file.close()
			return True
	def extract(self):
		if os.path.exists(os.path.join("build",self.folder)):
			print "%s is already extracted."%(self.archiv)
		else:
			tarball = tarfile.open(self.archiv,"r:gz")
			tarball.extractall(path="build")
	def build(self):
		path = os.path.join("build",self.folder,"")
		sys.path.append(path)
		os.chdir(path)
		command = "python setup.py build"
		p = Popen(command.split())
		return_code = p.wait()
		os.chdir(os.path.join("..",".."))
	def install(self):
		try:
			plat = os.uname()
			buil = plat[0].lower()+"-"+plat[4]+"-"+plat[2][:3]
			path = os.path.join("build",self.folder,"build","lib.%s"%buil,"")
			dpth = os.path.join(self.module,"")
			sys.path.append(path)
			shutil.move("%s%s"%(path,self.modfol),"%s"%(dpth))
		except shutil.Error, s:
			print "%s already installed."%(self.modfol)
		except IOError, i:
			shutil.copytree("%s"%(path),"%s%s"%(dpth,self.modfol))
	def prepare(self):
		print "[%s] Downloading files" % self.modfol
		self.download()
		print "[%s] Extracting archives" % self.modfol
		self.extract()
		print "[%s] Building packages" % self.modfol
		self.build()
		print "[%s] Instaling libraries" % self.modfol
		self.install()

def main():
	r = Reader()
	r.read_config()
	r.update_versions()
	r.build_structure(r.modules,r.archive,r.folders,r.version,r.address)
	b = Builder(); u = 0
	print "Zhockon Bakebur - Dependency killer"
	while u < 4:
		b.next_package(r.packages[r.names[u]])
		b.prepare()
		u += 1

if __name__ == "__main__":
	sys.exit(main())
