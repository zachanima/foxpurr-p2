PROJECT = foxpurr
IN      = src/*.cpp src/**/*.cpp
OUT     = bin/$(PROJECT)

CC      = g++
CFLAGS  = -O2 -ansi -pedantic -g -Wall
LFLAGS  = -lGL -lGLU -lGLEW -lSDL -lSDL_image

all: $(PROJECT)

$(PROJECT): $(IN)
	$(CC) $(CFLAGS) $(IN) -o "$(OUT)" $(LFLAGS)

