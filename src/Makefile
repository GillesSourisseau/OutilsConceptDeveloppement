all:gameOfLife PluginBase.so

CXXFLAGS= -std=c++11

PluginBase.so:PluginBase.cpp CellB.cpp PluginBase.hpp PluginInterface.hpp SpriteB.hpp
	g++ -shared -fPIC -o ./plugins/PluginBase.so PluginBase.cpp CellB.cpp

gameOfLife: PluginService.o main.o Grid.o Cell.o CellB.o PluginManager.o 
	g++ -o $@ $^ -ldl

main.o: main.cpp Grid.hpp PluginManager.hpp
	g++ $(CXXFLAGS) -c $<

Grid.o: Grid.cpp Cell.hpp PluginService.hpp

Cell.o: Cell.cpp

CellB.o: CellB.cpp Cell.hpp

PluginManager.o: PluginManager.cpp PluginInterface.hpp

PluginService.o: PluginService.cpp PluginInterface.hpp

PluginInterface.hpp:
	@touch $@
