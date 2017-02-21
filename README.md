# My Paint

## Description

It is a test task for CQG.

## Build

### Ubuntu

First you need to install following packages:

	sudo apt-get install freeglut3-dev libxi-dev libxmu-dev cmake

Build by cmake:

	# create build directory
	mkdir build
	# enter it
	cd build
	# generate makefile using Cmake
	cmake ..
	# build
	make

Run:

	./mypaint
