compile:
	clear
	gcc main.c config.c io.c manobras.c -w -o tp1

executa:
	./tp1

clean:
	rm -r tp1
	clear