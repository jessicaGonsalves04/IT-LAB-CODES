#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXSIZE 90

char data[MAXSIZE];
char check_value[MAXSIZE];
char gen_poly[10];
int data_length, i, j, N;

void XOR() {
    for (j = 1; j < N; j++)
        check_value[j] = ((check_value[j] == gen_poly[j]) ? '0' : '1');
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
    int sockfd, retval;
    int sentbytes;
    struct sockaddr_in serveraddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("\nSocket Creation Error");
        exit(EXIT_FAILURE);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8898);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    retval = connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    if (retval == -1) {
        printf("Connection error");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Enter the data to be sent: ");
    fgets(data, MAXSIZE, stdin);
    data[strcspn(data, "\n")] = '\0'; // Removing the newline character

    printf("Enter the generating polynomial: ");
    fgets(gen_poly, sizeof(gen_poly), stdin);
    gen_poly[strcspn(gen_poly, "\n")] = '\0'; // Removing the newline character

    // Calculate CRC for the original data
    data_length = strlen(data);
    N = strlen(gen_poly);
    CRC();

    // Print CRC
    printf("CRC: %s\n", check_value);

    // Append CRC to the original data
    strcat(data, check_value);

    // Final data to be sent
    printf("Final data to be sent: %s\n", data);

    // Send the final data
    sentbytes = send(sockfd, data, strlen(data), 0);
    if (sentbytes == -1) {
        printf("Error sending data\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return 0;
}
