CC = gcc
CPPFLAGS = -I.
clean = rm -f	

fileHandel: 1stfileHandel run1stFileHandel cleanFileHandel

1stfileHandel: 1st.c
		$(CC) -o 1stfile 1st.c $(CPPFLAGS)

run1stFileHandel:1stfile
	./1stfile

cleanFileHandel:
	$(clean) ./1stfile

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
