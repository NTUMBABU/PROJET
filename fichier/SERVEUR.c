#include<stdio.h>
#include<stdlib.h>
#include<string.h>			// les librerie qui contienent les 
#include<sys/types.h>		// fonctionnalite pour pouvoir fair
#include<sys/socket.h>		// la connection entre deux machine
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
	int socketServer = socket(AF_INET, SOCK_STREAM, 0); // les socket qui permetront la liason 
	struct sockaddr_in addrServer;						// entre deux programme.
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.1"); // l'addrese local de la machine
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(2020); // la reservation ou l'ouvture d'un port pour pouvoir se
										//se connecte a une machine(elle est un peu comme un recepteur des donnees.)
	bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer)); // connection au serveur

	listen(socketServer, 1);// ici le serveur va etre en attente d'une connection
	printf("En attente d'une liaison .....\n");

	struct sockaddr_in addrClient;
	socklen_t csize = sizeof(addrClient);
	int socketClient = accept(socketServer, (struct sockaddr *) &addrClient, &csize);// ici le serveur a accepte la liaison avec l'autre machine
	printf("Connecte\n");
	
	int *argument = malloc(sizeof(int));
	*argument = socketClient;
	
	User user = {
		.nom = "salut! NTUMBABU TSHITEYA Joas",
	};

	send(socketClient, &user, sizeof(user), 0);

	close(socketClient);// fermeture du socket .
	close(socketServer);// feremeture du serveur.
	printf("Fin du processus\n");

	return 0;
}