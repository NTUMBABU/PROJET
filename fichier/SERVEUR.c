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
	char nom[51];
}User;

int main(void)
{
	pthread_t clientThread;
	int socketServer = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrServer;
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(2020);

	bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
	//printf("bind : %d\n", socketServer);

	listen(socketServer, 1);
	printf("En attente d'une liaison .....\n");

	struct sockaddr_in addrClient;
	socklen_t csize = sizeof(addrClient);
	int socketClient = accept(socketServer, (struct sockaddr *) &addrClient, &csize);
	printf("Connecte\n");
	//printf("Client : %d\n", socketClient);
	int *argument = malloc(sizeof(int));
	*argument = socketClient;
	
	User user = {
		.nom = "salut! NTUMBABU TSHITEYA Joas",
	};

	send(socketClient, &user, sizeof(user), 0);

	close(socketClient);
	close(socketServer);
	printf("Fin du processus\n");

	return 0;
}