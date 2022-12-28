CC = g++
EXE = sga_example_sfml
SOURCES = main.cpp sga_impl_sfml.cpp
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)

CXXFLAGS += -I../ -I../../ -DDEBUG -g
CXXFLAGS += -g -Wall -Wformat
LIBS = 

##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS += -lsfml-graphics -lsfml-window -lsfml-system
endif

ifeq ($(findstring MINGW64,$(UNAME_S)),MINGW64)
	LIBS += -lgdi32 -lsfml-graphics -lsfml-window -lsfml-system
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

%.o:%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

%.o:../%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

%.o:../../%.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo build complete

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
