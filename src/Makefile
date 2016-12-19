all:gameOfLife PluginBase.so PluginWar.so PluginLife.so

CXXFLAGS= -std=c++11 -g


PluginBase.so:Cell.cpp Sprite.cpp CellB.cpp SpriteB.cpp PluginBase.cpp Grid.cpp PluginService.cpp PluginManager.cpp PluginBase.hpp PluginInterface.hpp
	g++ -shared -std=c++11 -g -rdynamic -fPIC -Wl,-soname,PluginBase.so Cell.cpp Sprite.cpp CellB.cpp SpriteB.cpp PluginBase.cpp Grid.cpp PluginService.cpp PluginManager.cpp -lc -o ./plugins/PluginBase.so

PluginWar.so:Cell.cpp Sprite.cpp CellW.cpp SpriteW.cpp PluginWar.cpp Grid.cpp PluginService.cpp PluginManager.cpp PluginWar.hpp PluginInterface.hpp
	g++ -shared -std=c++11 -g -rdynamic -fPIC -Wl,-soname,PluginWar.so Cell.cpp Sprite.cpp CellW.cpp SpriteW.cpp PluginWar.cpp Grid.cpp PluginService.cpp PluginManager.cpp -lc -o ./plugins/PluginWar.so

PluginLife.so:Cell.cpp Sprite.cpp CellLife.cpp SpriteLife.cpp PluginLife.cpp Grid.cpp PluginService.cpp PluginManager.cpp PluginLife.hpp PluginInterface.hpp
	g++ -shared -std=c++11 -g -rdynamic -fPIC -Wl,-soname,PluginLife.so Cell.cpp Sprite.cpp CellLife.cpp SpriteLife.cpp PluginLife.cpp Grid.cpp PluginService.cpp PluginManager.cpp -lc -o ./plugins/PluginLife.so


gameOfLife: PluginService.o life.o dialogs.o Grid.o Cell.o PluginManager.o Sprite.o 
	g++ -g -o $@ $^ -ldl `wx-config --cxxflags --libs`

life.o: ../GUI/life.cpp ../GUI/life.h ../GUI/dialogs.h
	g++ ../GUI/life.cpp `wx-config --cxxflags --libs` -c

dialogs.o: ../GUI/dialogs.cpp ../GUI/dialogs.h
	g++ ../GUI/dialogs.cpp `wx-config --cxxflags --libs` -c

main.o: main.cpp Grid.hpp PluginManager.hpp
	g++ $(CXXFLAGS) -c $<

Grid.o: Grid.cpp Cell.hpp PluginService.hpp

Cell.o: Cell.cpp Cell.hpp

Sprite.o:Sprite.cpp Sprite.hpp

CellB.o: CellB.cpp CellB.hpp Cell.hpp

CellW.o: CellW.cpp CellW.hpp Cell.hpp

CellLife.o: CellLife.cpp CellLife.hpp Cell.hpp

PluginManager.o: PluginManager.cpp PluginInterface.hpp

PluginService.o: PluginService.cpp PluginInterface.hpp

PluginBase.o: PluginBase.cpp PluginInterface.hpp

PluginWar.o: PluginWar.cpp PluginInterface.hpp

SpriteB.o: SpriteB.cpp SpriteB.hpp Sprite.hpp

SpriteW.o: SpriteW.cpp SpriteW.hpp Sprite.hpp

SpriteLife.o: SpriteLife.cpp SpriteLife.hpp Sprite.hpp

PluginInterface.hpp:
	@touch $@

.PHONY: clean

clean:
	-rm *.o gameOfLife

