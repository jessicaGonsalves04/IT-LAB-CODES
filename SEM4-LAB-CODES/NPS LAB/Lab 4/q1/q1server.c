#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define MAXSIZE 50

int main() {
    int sockfd, newsockfd, retval;
    socklen_t actuallen;
    int recedbytes, sentbytes;
    struct sockaddr_in serveraddr, clientaddr;
    char buff[MAXSIZE];
    char response[MAXSIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("\nSocket creation error");
        return -1;
    }
    printf("Socket Created");
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(3398);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    retval = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (retval == -1) {
        printf("Binding error");
        close(sockfd);
        return -1;
    }
    printf("Socket Binded");
    retval = listen(sockfd, 1);
    if (retval == -1) {
        close(sockfd);
        return -1;
    }
    printf("Socket Listening");
    actuallen = sizeof(clientaddr);
    newsockfd = accept(sockfd, (struct sockaddr*)&clientaddr, &actuallen);

    if (newsockfd == -1) {
        close(sockfd);
        return -1;
    }
    printf("Socket Accepting");
    recedbytes = recv(newsockfd, buff, sizeof(buff), 0);
    printf("Received:%s",buff);
    if (recedbytes == -1) {
        close(sockfd);
        close(newsockfd);
        return -1;
    }

    int count = 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '1')
            count++;
    }

    if (count % 2 == 0)
        sprintf(response, "Data received correctly");
    else
        sprintf(response, "Data wasn't received correctly");

    sentbytes = send(newsockfd, response, strlen(response), 0);
    if (sentbytes == -1) {
        close(sockfd);
        close(newsockfd);
        return -1;
    }

    close(sockfd);
    close(newsockfd);

    return 0;
}
