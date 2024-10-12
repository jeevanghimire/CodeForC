CC = g++
CFLAGS = -Wall -g
Run: inheritance  clean

classes: classes.cpp cleanclasses
	$(CC) -o classes classes.cpp && ./classes

inheritance: polymorphism.cpp 
	$(CC) -o inheritance polymorphism.cpp && ./inheritance
clean:
	rm inheritance
cleanclasses:
	rm classes