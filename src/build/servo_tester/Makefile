SOURCE_DIR=../../source
INCLUDE_DIR=../../include

INCLUDES=-I$(INCLUDE_DIR)/ -I/usr/local/include/ -I/usr/include/
LIB_DIRS=-L/usr/local/lib/
LIBS=-lwiringPi -lpthread -lrt -lm -lcrypt -lncurses
CXX=g++
CXX_FLAGS=$(INCLUDES) $(LIB_DIRS) $(LIBS)

SOURCES=\
	$(SOURCE_DIR)/PCA9685.cpp\
	./main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

CP=cp
RM=rm


all:servo_tester

.PHONY:install
install:servo_tester
	$(CP) -f servo_tester /usr/local/bin

.PHONY:uninstall
uninstall:
	$(RM) /usr/local/bin/servo_tester

servo_tester:$(OBJECTS)
	$(CXX) -o servo_tester $(OBJECTS) $(CXX_FLAGS)

.cpp.o:
	@ echo [Compile] $<
	$(CXX) -c $(CXX_FLAGS) $< -o $@
