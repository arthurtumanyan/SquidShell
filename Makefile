CC = gcc
CFLAGS = -g -Wall -Xlinker -zmuldefs -fPIC -ffreestanding -std=gnu99
RM = /bin/rm -f
L_PATH = /usr/lib
SRCS = SquidShell.c commands.c functions.c log.c network.c
PROG = SquidShell
CP = cp

all: $(PROG)

	$(CC) $(CFLAGS) $(SRCS) -L.  -o  $(PROG)
clean:
	$(RM) $(PROG)
uninstall:
	$(RM) $(PROG)
	$(RM)  *.o

$(PROG): SquidShell.o commands.o functions.o log.o network.o
	$(CC) $(CFLAGS) $(SRCS) -o $(PROG)
	$(RM) *.o
#
SquidShell.o: SquidShell.c
	$(CC)  -Wall  -c SquidShell.c
#
commands.o: commands.c
	$(CC)  -Wall -c commands.c

#
functions.o: functions.c
	$(CC)  -Wall  -c functions.c
#
log.o: log.c
	$(CC)  -Wall  -c log.c
#
network.o: network.c
	$(CC)  -Wall  -c network.c

install:

