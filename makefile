functions.o : functions.c functions.h
	gcc -c -Wall functions.c

libfunction.a : functions.o functions.h
	ar rcu libfunction.a functions.o

main.o : main.c  functions.h
	gcc -c -Wall main.c

stringProg : main.o libfunction.a
	gcc -Wall main.o ./libfunction.a -o stringProg

.PHONY: clean

clean:
	rm *.o *.a stringProg

all : stringProg
