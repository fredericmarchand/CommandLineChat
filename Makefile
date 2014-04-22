main:		main.o  server.o  client.o
		gcc -o main main.o server.o client.o -Wno-cpp

main.o:		main.c  types.h
		gcc -c main.c -Wno-cpp

client.o: 	client.c  types.h
		gcc -c client.c -Wno-cpp

server.o:	server.c  types.h
		gcc -c server.c -Wno-cpp

clean:
	rm -f *.o main 
