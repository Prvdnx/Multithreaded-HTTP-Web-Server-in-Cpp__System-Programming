
#include <arpa/inet.h> 	// socket(), bind(), accept(), inetntop(), listen()
#include <stdio.h>		// perror(), stderr
#include <stdlib.h>		// exit(), EXIT_FAILURE
#include <unistd.h>		// close()

int	main(int argc, char const *argv[])
{
	int	server_socket;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket <= 0)
	{
		perror("error in socket: ");
		exit(EXIT_FAILURE);
	}

	close(server_socket);

	return (0);
}