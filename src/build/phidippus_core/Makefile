SOURCE_DIR=../../source
INCLUDE_DIR=../../include
3RD_PARTY_DIR=../../3rd-party

INCLUDES= \
	-I$(INCLUDE_DIR)/ \
	-I$(INCLUDE_DIR)/kinematics/ \
	-I$(INCLUDE_DIR)/servo/ \
	-I$(INCLUDE_DIR)/network/ \
	-I/$(3RD_PARTY_DIR)/eigen/Eigen 
LIB_DIRS=-L/usr/local/lib/
LIBS=-lwiringPi -lpthread -lrt -lm -lcrypt
CXX=g++
CXX_FLAGS=$(INCLUDES) $(LIB_DIRS) $(LIBS)
CP=cp


SOURCES=\
	$(SOURCE_DIR)/PCA9685.cpp \
	$(SOURCE_DIR)/kinematics/kinematics.cpp \
	$(SOURCE_DIR)/kinematics/kinematic_configuration.cpp \
	$(SOURCE_DIR)/kinematics/link.cpp \
	$(SOURCE_DIR)/servo/servo.cpp \
	$(SOURCE_DIR)/network/socket.cpp \
	./main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

all:phidippus_core

.PHONY:install
install:phidippus_core
	$(CP) phidippus_core /usr/local/bin

phidippus_core:$(OBJECTS)
	$(CXX) -o phidippus_core $(OBJECTS) $(CXX_FLAGS)

.cpp.o:
	@ echo [Compile] $<
	$(CXX) -c $(CXX_FLAGS) $< -o $@
