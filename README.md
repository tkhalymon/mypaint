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

## Usage

You have 3 windows:

* Picture
* Palette
* Toolbox

**Note: If you'll close one of the windows by "X", all windows will be closed.**

### Picture

This is a window for drawing. Here you place figures.

### Palette

In this window you can select drawing color. First scale is a shade.
Second scale is brightness - from black to selected shade color.
Third is lightness - from color selected on second scale to white.

### Toolbox

Here you can select drawing instrument (pencil, line, ellipse, rectangle),
line width, transparency level, etc.

Pencil doesn't support line width

### Hot keys

|	Key		|	Action					|
|-----------|---------------------------|
| `Ctrl-z`	| Remove last added figure	|
| `Ctrl-y`	| Revert last action		|
| `Esc`		| Close current window		|