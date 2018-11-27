EXECUTABLE := Database

SOURCES := databaseDriver.cpp ./Records/*.cpp Database.cpp ./Questioner/Questioner.cpp ./Saves/ReaderWriter.cpp

INCLUDES := -I ..\include
EXT := exe
CC := g++

syntax:
	$(CC) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE).$(EXT)
