C = g++
LGL = -lglut
DEBUG = -g

openball: main.h main.cpp items.h items.cpp tools.h tools.cpp io.h io.cpp keymap.h
	$(C) main.cpp items.cpp tools.cpp io.cpp $(LGL) $(DEBUG) -o ../openball 
clean: 
	rm ../openball
