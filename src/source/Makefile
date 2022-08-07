INCLUDES=-I../include -I/usr/include/
LIB_DIRS=-L/usr/local/lib/
LIBS=-lwiringPi -lpthread -lrt -lm -lcrypt
CXX=g++
CXX_FLAGS=$(INCLUDES) $(LIB_DIRS) $(LIBS)
NAME=phidippus_core

all:
	$(CXX) main.cpp PCA9685.cpp -o $(NAME) $(CXX_FLAGS)
