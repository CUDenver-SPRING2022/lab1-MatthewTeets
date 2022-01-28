// Student: Matthew Teets
// Date: 1/19/22
// Class: CSCI 3800
// Description: This program generates a simple datagram server that will be compatible with a datagram client program.

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    
    int sd; // Functions as the socket descriptor
    int rc; // Functions as the return code recieved from the recvfrom
    struct sockaddr_in server_address; // Provides the address for the datagram server
    struct sockaddr_in from_address; // Provides the address from sender
    char buffer[100]; // Where data is stored
    int flags = 0; // Used for socket calls
    socklen_t fromLength = sizeof(struct sockaddr);
    
    // Error checking arguments
    if (argc < 2)
    {
        printf("Usage is: server <portnumber> \n");
        exit(1);
    }
    
    sd = socket(AF_INET, SOCK_DGRAM, 0); // Creates the socket
    
    // Set the address of the DGRAM server
    int portNumber = atoi(argv[1]);
    server_address.sin_family = AF_INET; // Sets the address family for the transport address
    server_address.sin_port = htons(portNumber); // Changes the portNumber to a network order byte and binds it
    server_address.sin_addr.s_addr = INADDR_ANY; // Allows connections from any internet address
    
    
    // Now pass address to the OS/Network
    rc = bind(sd, (struct sockaddr *) &server_address, sizeof(server_address));
    
    // Error checking the return code
    if (rc < 0)
    {
        perror("bind");
        exit(1);
    }
    
    // Run indefinitely receiving data from client machine.
    for(;;)
    {
        memset(buffer, 0, 100);
        rc = recvfrom(sd, buffer, sizeof(buffer), flags, (struct sockaddr *) &from_address, &fromLength);
        
        // Error checking the return code one last time
        if (rc <= 0)
        {
            printf("Some kind of error on recvfrom(). Exiting program...\n");
            break;
        }
        
        printf("Message received: %s \n", buffer);
        printf("I received %d bytes from the client. \n \n", rc);
        
    }
    
    return 0;
}
