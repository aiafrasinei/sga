CC = gcc
EXE = sga_example_sdl3 
SOURCES = main.c sga_impl_sdl3.c
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)

CFLAGS += -I../ -I../../
CFLAGS += -g -Wall -Wformat
LIBS =

##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux)
	ECHO_MESSAGE = "Linux"
	LIBS += -lGL -ldl `pkg-config --libs sdl3`
endif

ifeq ($(shell uname), Darwin)
	ECHO_MESSAGE = "Darwin"
	LIBS += `pkg-config --libs sdl3`
endif

ifeq ($(findstring MINGW64,$(UNAME_S)),MINGW64)
	LIBS += -lgdi32 -lopengl32 -limm32 `pkg-config --libs sdl3`
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o:../%.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o:../../%.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(EXE)
	@echo build complete

$(EXE): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
