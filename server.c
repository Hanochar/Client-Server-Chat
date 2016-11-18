#include "defs.h"

#define MY_PORT 60002

int main()
{
   int listenSocket, clientSocket;
   struct sockaddr_in myAddr, clientAddr;
   int i, addrSize, bytesRcv;

   char buffer[30];

//Create a socket
   listenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(listenSocket < 0)
   {
	printf("Socket Error. Can't be opened.");
	exit(-1);
   }

//Setup server
  memset(&myAddr, 0, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  myAddr.sin_port = htons((unsigned short) MY_PORT);

//Bind listenSocket
  i = bind(listenSocket, (struct sockaddr*) &myAddr, sizeof(myAddr));
  if(i < 0)
  {
	printf("Binding error.");
	exit(-1);
  }

//Listen
  i = listen(listenSocket, 1);
  if(i < 0)
  {
	printf("Listening error.");
	exit(-1);
  }

//Wait for request

  addrSize = sizeof(clientAddr);
  clientSocket = accept(listenSocket, (struct sockaddr*) &clientAddr, &addrSize);
  if(clientSocket < 0)
  {
    printf("Connection error.");
    exit(-1);
  }

//Read message from client
   while(1)
   {
	bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);
	buffer[bytesRcv] = 0;
	printf("\nClient: %s", buffer);
	if(strcmp(buffer, "exit") == 0)
	   break;
   }

//Close sockets
close(listenSocket);
close(clientSocket);
}