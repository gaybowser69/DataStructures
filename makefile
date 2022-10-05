compile: a.out
a.out: main.o node.o linkedlist.o queue.o stack.o
	gcc main.o node.o linkedlist.o queue.o stack.o 
graph.o:  
	gcc -c ./inc/graph/graph.c 
node.o: 
	gcc -c ./inc/node/node.c
linkedlist.o: 
	gcc -c ./inc/linkedList/linkedlist.c
queue.o:  
	gcc -c ./inc/queue/queue.c
stack.o:  
	gcc -c ./inc/stack/stack.c
main.o: main.c
	gcc -c main.c

run:
	clear
	./a.out
clean:
	rm *.out *.o