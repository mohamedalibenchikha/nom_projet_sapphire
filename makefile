p:main.o  enigme.o 
	gcc main.o   enigme.o  -o en -lSDL -lSDL_image -lm
main.o:main.c
	gcc -c main.c  -g
enigme.o:enigme.c
	gcc -c enigme.c  -g

