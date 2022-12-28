CC = gcc
EXE = sga_example_x11
SOURCES = main.c
SOURCES += ../../sga_impl_x11.c
OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

CFLAGS = -I../ -I../../
CFLAGS += -g -Wall -Wformat
LIBS = -lX11

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