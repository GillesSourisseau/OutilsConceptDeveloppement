all:gameOfLife PluginBase.so

CXXFLAGS= -std=c++11

PluginBase.so:Cell.cpp Sprite.cpp CellB.cpp SpriteB.cpp PluginBase.cpp Grid.cpp PluginService.cpp PluginBase.hpp PluginInterface.hpp
	g++ -shared -std=c++11 -rdynamic -fPIC -Wl,-soname,PluginBase.so Cell.cpp Sprite.cpp CellB.cpp SpriteB.cpp PluginBase.cpp Grid.cpp PluginService.cpp -lc -o ./plugins/PluginBase.so

gameOfLife: PluginService.o main.o Grid.o Cell.o PluginManager.o Sprite.o 
	g++ -o $@ $^ -ldl

main.o: main.cpp Grid.hpp PluginManager.hpp
	g++ $(CXXFLAGS) -c $<

Grid.o: Grid.cpp Cell.hpp PluginService.hpp

Cell.o: Cell.cpp Cell.hpp

Sprite.o:Sprite.cpp Sprite.hpp

CellB.o: CellB.cpp CellB.hpp Cell.hpp

PluginManager.o: PluginManager.cpp PluginInterface.hpp

PluginService.o: PluginService.cpp PluginInterface.hpp

PluginInterface.hpp:
	@touch $@

