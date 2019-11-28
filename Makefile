EXECUTABLE := Database

SOURCES := databaseDriver.cpp ./Records/*.cpp

INCLUDES := -I ..\include
EXT := exe
CC := g++

syntax:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)
