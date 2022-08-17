SOURCE_DIR=../../source
INCLUDE_DIR=../../include
3RD_PARTY_DIR=../../3rd-party
NAME=phidippus_core
INCLUDES= \
	-I$(INCLUDE_DIR)/ \
	-I$(INCLUDE_DIR)/kinematics/ \
	-I$(INCLUDE_DIR)/servo/ \
	-I$(INCLUDE_DIR)/network/ \
	-I$(INCLUDE_DIR)/logging/ \
	-I$(INCLUDE_DIR)/util/ \
	-I$(3RD_PARTY_DIR)/eigen/Eigen \
	-I$(3RD_PARTY_DIR)/easyloggingpp/src
LIB_DIRS=-L/usr/local/lib/
LIBS=-lwiringPi -lpthread -lrt -lm -lcrypt
CXX=g++
CXX_FLAGS=$(INCLUDES) $(LIB_DIRS) $(LIBS) -std=c++17
CP=cp
RM=rm -f

SOURCES_CPP=\
	$(SOURCE_DIR)/PCA9685.cpp \
	$(SOURCE_DIR)/kinematics/kinematics.cpp \
	$(SOURCE_DIR)/kinematics/kinematic_configuration.cpp \
	$(SOURCE_DIR)/kinematics/link.cpp \
	$(SOURCE_DIR)/util/util.cpp \
	$(SOURCE_DIR)/servo/servo.cpp \
	$(SOURCE_DIR)/network/socket.cpp \
	./main.cpp
SOURCES_CC=$(3RD_PARTY_DIR)/easyloggingpp/src/easylogging++.cc

OBJECTS_CPP=$(SOURCES_CPP:.cpp=.o)
OBJECTS_CC=$(SOURCES_CC:.cc=.o)
OBJECTS=$(OBJECTS_CPP) $(OBJECTS_CC)

all:$(NAME)

.PHONY:install
install:$(NAME)
	$(CP) $(NAME) /usr/local/bin
	
.PHONY:clean
clean:
	$(RM) $(OBJECTS)
	$(RM) $(NAME)

$(NAME):$(OBJECTS)
	$(CXX) -o $(NAME) $(OBJECTS) $(CXX_FLAGS)

.cpp.o:
	@ echo [Compile] $<
	$(CXX) -c $(CXX_FLAGS) $< -o $@

.cc.o:
	@ echo [Compile] $<
	$(CXX) -c $(CXX_FLAGS) $< -o $@