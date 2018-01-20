all: main_mm main_malloc 

main_mm: main_mm.c mm.o
	gcc -o main_mm main_mm.c mm.o

main_malloc: main_malloc.c mm.o
	gcc -o main_malloc main_malloc.c mm.o

mm.o: mm.c
	gcc -c -o mm.o mm.c 

clean:
	rm -f mm.o main_mm main_malloc 
