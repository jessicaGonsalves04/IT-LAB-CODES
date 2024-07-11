#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define MAXSIZE 50

int main() {
    int sockfd, retval;
    int recedbytes, sentbytes;
    struct sockaddr_in serveraddr;
    char buff[MAXSIZE];
    char c[MAXSIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("\nSocket Creation Error");
        return -1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3398);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    retval = connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (retval == -1) {
        printf("Connection error");
        return -1;
    }

    printf("Enter data to be sent:\n");
    fgets(buff, MAXSIZE, stdin);
    buff[strcspn(buff, "\n")] = '\0';  // Removing the newline character

    int count = 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '1')
            count++;
    }

    char par[2];
    if (count % 2 == 0) {
        sprintf(par, "0");
    } else {
        sprintf(par, "1");
    }

    strcat(buff, par);

    printf("Data to be sent: %s\n", buff);

    sentbytes = send(sockfd, buff, strlen(buff), 0);
    if (sentbytes == -1) {
        printf("Error sending data\n");
        close(sockfd);
        return -1;
    }

    recedbytes = recv(sockfd, c, sizeof(c), 0);
    if (recedbytes == -1) {
        printf("Error receiving response\n");
        close(sockfd);
        return -1;
    }

    printf("Response from server: %s\n", c);

    close(sockfd);

    return 0;
}
