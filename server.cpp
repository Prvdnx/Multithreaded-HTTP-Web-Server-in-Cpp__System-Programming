
#include <arpa/inet.h> 	// socket(), bind(), accept(), inetntop(), listen()
#include <stdio.h>		// perror(), stderr
#include <stdlib.h>		// exit(), EXIT_FAILURE
#include <unistd.h>		// close()
#include <string.h>		// memset()

#define PORT 8080

int	main(int argc, char const *argv[])
{
	int	server_socket;
	int	randomPORT = PORT;
	struct sockaddr_in	server_address;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket <= 0)
	{
		perror("error in socket: ");
		exit(EXIT_FAILURE);
	}

	// set SO_REUSEADDR to allow reuse of local addresses
	// int	yes = 1;
	// if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1)
	// {
	// 	perror("setsockopt");
	// 	close(server_socket);
	// 	exit(EXIT_FAILURE);
	// }

	randomPORT = 8080 + (rand() % 10);	// generate a random port btw 8080 & 8090 to avoid scenarios where 8080 is busy
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(randomPORT);

	while (bind(server_socket, (struct sockaddr *)&server_address,sizeof(server_address)) < 0)
	{
		randomPORT = 8080 + (rand() % 10);
		server_address.sin_port = htons(randomPORT);
	}

	close(server_socket);

	return (0);
}

/*
 int server_fd = socket(domain, type, protocol);
	"domain", also referred to as the address family - is the communication domain in which the socket should be created.
Some of address families includes AF_INET (IP), AF_INET6 (IPv6), AF_UNIX (local channel, similar to pipes), AF_ISO
(ISO protocols), and AF_NS (Xerox Network Systems protocols). AF_INET and AF_INET6 are most common.
	"type", type of service. This is selected according to properties required by the application: for TCP transmission
it can be SOCK_STREAM (for virtual circuit service), for UDP transmission it can be a SOCK_DGRAM (for datagram service),
SOCK_RAW (for direct IP service). Check with your address family to see whether a particular service is available.
	"protocol", indicates a specific protocol to use in supporting the sockets operation. This is useful in cases where
some families may have more than one protocol to support a given type of service. The return value is a file descriptor
(a small integer). The analogy of creating a socket is that of requesting a telephone line from the phone company.
*/