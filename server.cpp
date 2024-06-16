
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