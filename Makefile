all:	server client chat

chat:	chat.c defs.h
	gcc -c -o chat chat.c

client:	client.c defs.h
	gcc -c -o client client.c

server:	server.c defs.h
	gcc -c -o server server.c

clean:
	rm -f client server
