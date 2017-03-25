CPP=g++
CPPFLAGS= -std=c++11 -ggdb -w
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
INCLUDE=-I include -I include/external
LIBDIRS=-L lib
LIBS= -lcryptopp
EXE=bibleblack

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CPP) $(OBJECTS) $(LIBDIRS) $(LIBS) -o $@

.cpp.o:
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c $*.cpp

clean:
	rm $(EXE)
	rm *.o
