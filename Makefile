CPP=g++
CPPFLAGS= -std=c++11 -ggdb -w
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXE=bibleblack

all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CPP) $(OBJECTS) -o $@

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $*.cpp

clean:
	rm $(EXE)
	rm *.o
