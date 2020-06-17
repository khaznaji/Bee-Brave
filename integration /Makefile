prog: main.o fonction.o enigme.o
	gcc main.o fonction.o enigme.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_gfx -lm

fonction.o: fonction.c
	gcc -c fonction.c -g
enigme.o:enigme.c
	gcc -c enigme.c  -g

main.o: main.c
	gcc -c main.c -g
