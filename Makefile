CC=gcc
CFLAGS=-lSDL2

fate-engine: main.o mapViewer.o eventHandler.o renderEngine.o
	$(CC) -o fate-engine main.o mapViewer.o eventHandler.o renderEngine.o -lSDL2 -lm