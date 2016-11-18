#Client-Server-Chat

Author:		Ryan Samaroo

Purpose:	Allows two users to communicate with each other while networked together

Instruction:	


  You will be given a prompt to indicate they're in 'chat' and will be asked to enter a command:
    the wait command: this turns the user’s process into a 'server', and waits for a connection request
    the talk command: this turns that user’s process into a 'client', and sends connection request to the user specified
second host
      when a connection has been established, both user processes go into 'talk' mode
      the client process user enters a message which is sent to the server process
      the server process receives the message and prints it to the screen
      the server process user enters a reply message which is sent to the client process
      the client process receives the message and prints it to the screen
      both processes exchange user-entered messages back-and-forth until one of the users enters the 'close' command
      the 'close' command, when it is entered in 'talk' mode, closes all sockets for both processes
      once the connection is closed, 'talk' mode is terminated; both processes are placed back in the 'chat' feature where either process can initiate a connection to another process or wait for a connection request
    the 'exit' command: this terminates the chat process
