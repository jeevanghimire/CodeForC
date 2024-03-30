CC = gcc
CPPFLAGS = -I.

run: linkedlist runAll  clean


linkedlist: LinkedList.c 
	$(CC) -o linkedlist linkedlist.c $(CPPFLAGS)

runAll: linkedlist 
	./linkedlist

clean:
	rm -f Linkedlist
