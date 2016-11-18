#include "defs.h"


#define SERVER_PORT 60002

int main(int argc, char* argv[])
{
   int mySocket;
   struct sockaddr_in addr;
   int i;

   char inStr[30];
   char buffer[30];

   char SERVER_IP[10];
   if(argc < 1)
   {
	strcpy(SERVER_IP,"10.0.2.15");
   }
   else
   {
	strcpy(SERVER_IP, argv[0]);
   }
//Create a socket
   mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(mySocket < 0)
   {
	printf("Socket Error. Can't be opened.");
	exit(-1);
   }

//Setup address
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons((unsigned short) SERVER_PORT);

//Connect to server
  i = connect(mySocket, (struct sockaddr*) &addr, sizeof(addr));
  if(i < 0)
  {
	printf("Client connection failed.");
	exit(-1);
  }

//Get input from user and send to server
  while(1)
  {
	printf("What's your message?: ");
	scanf("%s", inStr);
	fgets(inStr, sizeof(inStr), stdin);
	inStr[strlen(inStr)-1] = 0;
	strcpy(buffer, inStr);
	send(mySocket, buffer, strlen(buffer), 0);

	if(strcmp(inStr, "exit") == 0)
	   break;

  }

//Close socket
close(mySocket);
}