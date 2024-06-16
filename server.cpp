
#include <stderr.h>
#include <arpa/inet.h>  // socket(), bind(), accept(), inetntop(), listen()

int	main(int argc, char const *argv[])
{
	int	server_socket;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket <= 0)
	{
		perror("error in socket: ");
		exit(EXIT_FAILURE);
	}

	return (0);
}