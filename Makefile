C = g++
LGL = -lglut

openball: main.cpp
	$(C) main.cpp $(LGL) -o openball 
clean: 
	rm openball
