#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<ctype.h>

void error(const char *msg)
{
	perror(msg);
	exit(1);
}


int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "port No provided progam termined \n");
		exit(1);
	}
	
	int sockfd , newsockfd , portno , n;
	char buffer[255];
	
	struct sockaddr_in serv_addr , cli_addr;
	socklen_t clilen;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		error("Echec de l'ouverture du Socket ");
	}
	bzero((char *) &serv_addr , sizeof(serv_addr));
	portno = atoi(argv[1]);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	if(bind(sockfd , (struct sockaddr *)&serv_addr , sizeof(serv_addr)) < 0)
		error("Bind FAiled.");
	listen(sockfd , 5);
	clilen = sizeof(cli_addr);
	
	newsockfd = accept(sockfd , (struct sockaddr *) &cli_addr, &clilen);
	
	if(newsockfd < 0)
	error("Erreur lors de la connexion");
	//////////////////////////////////
	/*Si vous souaite avoir une conversation intane avec le client 
		il vous faut mettre en commentaire  la ligne 58 jusqu a la ligne
		 72 puis enleve le commentaire qui se trouve a ligne 74 jusqu a la ligne 93 fait de mm pour le serveur*/
	FILE *fp;
	
	int ch = 0;
	fp = fopen("test_recu.txt" , "a");
	int words;
	
	read(newsockfd , &words , sizeof(int));
	
	while(ch != words)
	{
		read(newsockfd , buffer , 255);
		fprintf(fp , "%s " , buffer);
		ch++;
	}
	printf("Les fichier est recu avec succes \n\n");
	//////////////////////////////////////
	/*
	while(1)
	{
		bzero(buffer , 256);
		n = read(newsockfd , buffer ,255);
		if(n < 0)
			error("Error on reading "); 
		printf("Client : %s\n", buffer);
		bzero(buffer, 255);
		fgets(buffer , 255, stdin);
		
		n= write(newsockfd, buffer, strlen(buffer));
		if(n < 0)
			error("Error on writing ");
			
		int i = strncmp("Bye",buffer, 3);
		if(i == 0)
		break;
	}
	*/
	close(newsockfd);
	close(sockfd);
	return 0;
	
}