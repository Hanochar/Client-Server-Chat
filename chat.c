#include "defs.h"
#define MAX_ARR 10

int main()
{

   printf("Welcome to the Chat feature.\n\n");

   
   while(1)
   {
	char input[MAX_ARR];
	printf("Enter a command: ");
	scanf("%s", input);
	if(strcmp(input, "exit") == 0)
	{
	   printf("\nClosing\n");
	   break;
	}
	else if(strcmp(input, "wait") == 0)
	{
	   //Become server
	}
	else if(strcmp(input, "talk") == 0)
	{
	   //Become client
	printf("\nEnter the server's IP: ");
	scanf("%s", input);
	}
   }

}
