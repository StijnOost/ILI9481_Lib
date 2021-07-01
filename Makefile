#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := ILI9481.cpp Line.cpp Drawable.cpp wall.cpp Peddle.cpp Ball.cpp

# header files in this project
HEADERS := ILI9481.hpp Line.hpp Drawable.hpp wall.hpp Peddle.hpp Ball.hpp

# other places to look for files for this project
SEARCH  := 

# set RELATIVE to the next higher directory 
# and defer to the Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.due
