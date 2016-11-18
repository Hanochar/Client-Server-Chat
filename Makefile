all:	server client chat

chat:	chat.c defs.h
	gcc  -o chat chat.c

client:	client.c defs.h
	gcc  -o client client.c

server:	server.c defs.h
	gcc  -o server server.c

clean:
	rm -f client server