C = g++
LGL = -lglut

openball: main.cpp items.h items.cpp
	$(C) main.cpp items.cpp $(LGL) -o openball 
clean: 
	rm openball
