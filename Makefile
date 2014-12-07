C = g++
LGL = -lglut
DEBUG = -g

openball: main.cpp items.h items.cpp
	$(C) main.cpp items.cpp $(LGL) $(DEBUG) -o openball 
clean: 
	rm openball
