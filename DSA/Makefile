CC = gcc
CPPFLAGS = -I.
clean = rm -f	

run: linkedlist runAll  clean

RunQ: Queue runQueue clean

Queue: Queue.c 
	$(CC) -o Queue Queue.c $(CPPFLAGS)

runQueue: Queue
	./Queue

linkedlist: LinkedList.c 
	$(CC) -o linkedlist linkedlist.c $(CPPFLAGS)

runAll: linkedlist 
	./linkedlist

clean:
	$(clean) ./Queue
