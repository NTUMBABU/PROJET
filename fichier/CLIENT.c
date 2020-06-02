#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>

typedef struct User
{
	char nom[50];
}User;

int main(void)
{
	int socketClient = socket(AF_INET, SOCK_STREAM, 0);// creation d'un socket client pareille que celluis de serveur
	struct sockaddr_in addrClient;
	addrClient.sin_addr.s_addr = inet_addr("127.0.0.1");// adreeer du deveur
	addrClient.sin_family = AF_INET;
	addrClient.sin_port = htons(2020);// la connection au port
	connect(socketClient, (const struct sockaddr *)&addrClient, sizeof(addrClient));//connection client a l'adresse addrClient;
	printf("connecte\n");

	User user;
	recv(socketClient, &user, sizeof(User), 0);
	printf("%s \n",user.nom);
	
	close(socketClient);

	return 0;
}
