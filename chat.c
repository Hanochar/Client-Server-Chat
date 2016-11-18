#include "defs.h"
#define MAX_ARR 10

int main()
{
   printf("Welcome to the Chat feature.\n\n");

   
   while(1)
   {
	char* input[2];
	input[1] = NULL;
	printf("Enter a command: ");
	scanf("%s", input[0]);
	if(strcmp(input[0], "exit") == 0)
	{
	   printf("\nClosing\n");
	   break;
	}
	else if(strcmp(input[0], "wait") == 0)
	{
	   //Become server
	   int rc = execvp("./server", input);
	   if(rc < 0){printf("ERROR!");}
	}
	else if(strcmp(input[0], "talk") == 0)
	{
	   //Become client
	printf("\nEnter the server's IP: ");
	scanf("%s", input[0]);
	int rc = execvp("./client", input);
	if(rc < 0){printf("ERROR!");}
	}
   }

}