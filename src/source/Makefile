INCLUDES=-I../include -I/usr/include/
LIB_DIRS=-L/usr/local/lib/
LIBS=-lwiringPi -lpthread -lrt -lm -lcrypt
CXX=g++
CXX_FLAGS=$(INCLUDES) $(LIB_DIRS) $(LIBS)
NAME=phidippus_core

all:main.cpp
	$(CXX) main.cpp -o $(NAME) $(CXX_FLAGS)
