C = g++
LGL = -lglut
DEBUG = -g

openball: main.h main.cpp items.h items.cpp tools.h tools.cpp io.h io.cpp keymap.h menus.h \
menus.cpp
	$(C) main.cpp items.cpp tools.cpp io.cpp menus.cpp $(LGL) $(DEBUG) -o ../openball 
clean: 
	rm ../openball
