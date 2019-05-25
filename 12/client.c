#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#define MAX 80

int main(int argc, char* argv[])
{
    char buffer[MAX];
    int in, out, n;

    in = open("server_to_client", O_RDWR,0777);
    out = open("client_to_server", O_RDWR,0777);

    printf("\nSending the message.");
    n = strlen(argv[1]);
    write(out, argv[1], n);

    read(in, buffer, n);
    buffer[n] = '\0';
    printf("\nMessage received: %s", buffer);
    
    close(in);
    close(out);
}
