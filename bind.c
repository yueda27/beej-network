
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
struct addrinfo hints, *res;
int sockfd;
int connect_status;

// first, load up address structs with getaddrinfo():

memset(&hints, 0, sizeof hints);
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM;
hints.ai_flags = AI_PASSIVE;

getaddrinfo("www.example.com", "3490", &hints, &res);

// make a socket:

sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

// connect!

if((connect_status = connect(sockfd, res->ai_addr, res->ai_addrlen)) == -1){
    fprintf(stderr, "connect - %d: %s\n", connect_status,gai_strerror(connect_status));
};

}