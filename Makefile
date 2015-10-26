


OBJS=myls.o
CC=gcc
XFILE=myls

all:$(OBJS)
	$(CC) -o $(XFILE) $(OBJS)

clean:
	rm -f $(XFILE) *.o




