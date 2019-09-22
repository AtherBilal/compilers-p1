all: *.c
	gcc -g -Wall -o P0 *.c

clean:
	rm P0 *.preorder *.inorder *.levelorder tempFile
