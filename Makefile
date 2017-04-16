CPP=g++

EXE=bibleblack

BUILD_DIR=build
SRC_DIRS=src

SRCS=$(wildcard $(SRC_DIRS)/*.cpp)
OBJS=$(addprefix obj/, $(notdir $(SRCS:.cpp=.o)))

INC_DIRS=include/external include
INC_FLAGS=$(addprefix -I,$(INC_DIRS))

LIB_DIRS=-L lib
LIBS=-lcryptopp

CPPFLAGS=-std=c++11 -ggdb -w -Wall

all: obj/$(EXE)

obj/$(EXE): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@ $(LIB_DIRS) $(LIBS)

$(OBJS): $(SRCS)
	$(CPP) $(CPPFLAGS) $(INC_FLAGS) -c $(patsubst %.o,%.cpp,$(subst obj,src,$@)) -o $@

.PHONY: clean
clean:
	$(RM) $(EXE) $(OBJS)
