CC = gcc
EXE = sga_example_allegro5
SOURCES = main.c sga_impl_allegro5.c
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
UNAME_S := $(shell uname -s)

CFLAGS += -I../ -I../../ -DDEBUG -g
CFLAGS += -g -Wall -Wformat
LIBS = 

##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS += -lGL -ldl -lallegro -lallegro_primitives
endif

ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
	ECHO_MESSAGE = "MinGW"
	LIBS += -lgdi32 -lopengl32 -limm32 `pkg-config --static --libs sdl2`

	CFLAGS += `pkg-config --cflags sdl2`
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
