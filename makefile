compile:
	clear
	gcc main.c config.h config.c io.h io.c manobras.h manobras.c -w -Wall -o tp1

execute:
	./tp1

clean:
	rm -r tp1
	clear