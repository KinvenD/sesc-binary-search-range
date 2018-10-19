run: prog
	./prog
prog: prog.c
	gcc -Wall -std=c11 prog.c -o prog
build: prog
