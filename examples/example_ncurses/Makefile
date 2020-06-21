CC = gcc
EXE = example_ncurses
SOURCES = main.c
SOURCES += ../../sga_impl_ncurses.c
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

CFLAGS = -I../ -I../../
CFLAGS += -g -Wall -Wformat
LIBS = -lncurses

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

%.o:%.c
		$(CC) $(CFLAGS) -c -o $@ $<

%.o:../../%.c
		$(CC) $(CFLAGS) -c -o $@ $<

all: $(EXE)
		@echo build complete

$(EXE): $(OBJS)
		$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
		rm -f $(EXE) $(OBJS)
