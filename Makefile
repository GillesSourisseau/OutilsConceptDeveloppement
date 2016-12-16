all:gameOfLife

gameOfLife_SOURCES = main.cpp PluginManager.cpp Sprite.cpp Grid.cpp Cell.cpp
gameOfLife_OBJECTS = $(gameOfLife_SOURCES:.cpp=.o)
gameOfLife_HEADERS = $(gameOfLife_SOURCES:.cpp=.hpp)

CXXFLAGS = -std=c++11

gameOfLife:$(gameOfLife_OBJECTS)
	g++ -o $@ $^ -ldl

main.o:main.cpp PluginManager.hpp

PluginManager.o: PluginManager.cpp PluginManager.hpp PluginInterface.hpp

Sprite.o:Sprite.cpp Sprite.hpp

Grid.o:Grid.cpp Grid.hpp Cell.hpp 

Cell.o: Cell.cpp Cell.hpp 


.PHONY: clean

clean:
	-rm $(gameOfLife_OBJECTS) gameOfLife
