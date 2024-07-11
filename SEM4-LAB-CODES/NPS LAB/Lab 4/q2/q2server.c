#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAXSIZE 90

char data[MAXSIZE];
char check_value[MAXSIZE];
char gen_poly[10];
int data_length, i, j, N;

void XOR() {
    for (j = 1; j < N; j++)
        check_value[j] = ((check_value[j] == gen_poly[j]) ? '0' : '1');
}

void receiver() {
    printf("Data Received: %s\n", data);
    CRC();
    for (i = 0; i < N - 1; i++) {
        if (check_value[i] == '1') {
            printf("Error Detected\n");
            return;
        }
    }
    printf("No error detected\n");
}

void CRC() {
    for (i = 0; i < N; i++) {
        check_value[i] = data[i];
    }
    do {
        if (check_value[0] == '1')
            XOR();
        for (j = 0; j < N - 1; j++)
            check_value[j] = check_value[j + 1];
        check_value[j] = data[i++];
    } while (i <= data_length + N - 1);
}

int main() {
    int sockfd, newsockfd, retval;
    socklen_t actuallen;
    int recedbytes;
    struct sockaddr_in serveraddr, clientaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("\nSocket creation error");
        exit(EXIT_FAILURE);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8898);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    retval = bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

    if (retval == -1) {
        printf("Binding error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    retval = listen(sockfd, 1);

    if (retval == -1) {
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    actuallen = sizeof(clientaddr);
    newsockfd = accept(sockfd, (struct sockaddr*)&clientaddr, &actuallen);

    if (newsockfd == -1) {
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    recedbytes = recv(newsockfd, data, sizeof(data), 0);

    if (recedbytes == -1) {
        close(sockfd);
        close(newsockfd);
        exit(EXIT_FAILURE);
    }

    recedbytes = recv(newsockfd, gen_poly, sizeof(gen_poly), 0);

    if (recedbytes == -1) {
        close(sockfd);
        close(newsockfd);
        exit(EXIT_FAILURE);
    }

    data_length = strlen(data);
    N = strlen(gen_poly);

    receiver();

    close(sockfd);
    close(newsockfd);

    return 0;
}
