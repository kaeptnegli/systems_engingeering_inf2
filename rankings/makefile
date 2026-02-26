CC = gcc
CFLAGS = -g -O0
OBJS = rankingApp.o readCSVLine.o listFileIO.o

main.out: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) main.out
