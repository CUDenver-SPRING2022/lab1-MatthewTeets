# Makefile for datagram server and client

CC = gcc
OBJCSS = server1.c
OBJCS = client1.c

CFLAGS = -g -Wall
#setup for system
nLIBS = 

all: server1 client1

server1: $(OBJCSS)
	$(CC) $(CFLAGS) -o $@ $(OBJCSS) $(LIBS)
client1: $(OBJCS)
	$(CC) $(CFLAGS) -o $@ $(OBJCS) $(LIBS)

clean:
	rm server1 client1