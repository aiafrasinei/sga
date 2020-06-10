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
		gcc $(CFLAGS) -c -o $@ $<

%.o:../../%.c
		gcc $(CFLAGS) -c -o $@ $<

all: $(EXE)
		@echo build complete

$(EXE): $(OBJS)
		gcc -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
		rm -f $(EXE) $(OBJS)
