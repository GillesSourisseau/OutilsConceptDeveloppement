all:gameOfLife PluginBase.so

CXXFLAGS= -std=c++11 -g


PluginBase.so:Cell.cpp Sprite.cpp CellB.cpp SpriteB.cpp PluginBase.cpp Grid.cpp PluginService.cpp PluginManager.cpp PluginBase.hpp PluginInterface.hpp
	g++ -shared -std=c++11 -g -rdynamic -fPIC -Wl,-soname,PluginBase.so Cell.cpp Sprite.cpp CellB.cpp SpriteB.cpp PluginBase.cpp Grid.cpp PluginService.cpp PluginManager.cpp -lc -o ./plugins/PluginBase.so

gameOfLife: PluginService.o life.o Grid.o Cell.o PluginManager.o Sprite.o 
	g++ -g -o $@ $^ -ldl `wx-config --cxxflags --libs`

life.o: ../GUI/life.cpp
	g++ ../GUI/life.cpp `wx-config --cxxflags --libs` -c

main.o: main.cpp Grid.hpp PluginManager.hpp
	g++ $(CXXFLAGS) -c $<

Grid.o: Grid.cpp Cell.hpp PluginService.hpp

Cell.o: Cell.cpp Cell.hpp

Sprite.o:Sprite.cpp Sprite.hpp

CellB.o: CellB.cpp CellB.hpp Cell.hpp

PluginManager.o: PluginManager.cpp PluginInterface.hpp

PluginService.o: PluginService.cpp PluginInterface.hpp

PluginBase.o: PluginBase.cpp PluginInterface.hpp

SpriteB.o: SpriteB.cpp SpriteB.hpp

PluginInterface.hpp:
	@touch $@

.PHONY: clean

clean:
	-rm *.o gameOfLife

