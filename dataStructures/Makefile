binaryTree:  binaryTree.o testTree.o
	gcc -g -Wall binaryTree.o testTree.o -o out
	
binaryTree.o: binaryTree.c binaryTree.h
	gcc -g -Wall -c binaryTree.c

testTree.o: testTree.c binaryTree.h
	gcc -g -Wall -c testTree.c

clean:
	rm -f *.o out *~
