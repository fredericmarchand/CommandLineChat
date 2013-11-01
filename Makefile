main:		main.o  server.o  client.o
		gcc -o main main.o server.o client.o

main.o:		main.c  types.h
		gcc -c main.c

client.o: 	client.c  types.h
		gcc -c client.c

server.o:	server.c  types.h
		gcc -c server.c

clean:
	rm -f *.o main 
