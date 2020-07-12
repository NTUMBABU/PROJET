#include<stdio.h>
#include<stdlib.h>
#include<string.h>			// les librerie qui contienent les 
#include<sys/types.h>		// fonctionnalite pour pouvoir fair
#include<sys/socket.h>		// la connection entre les client et le serveur
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<ctype.h>

void error(const char *msg)
{
	perror(msg);
	exit(0);
}
int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	
	char buffer[255];
	if(argc < 3)
	{
		fprintf(stderr, "usage %s hostname port \n", argv[0]);
		exit(0);
	}
	
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);// creation du soket
	if(sockfd < 0)
		error("erreur de l'ouverture du socket");
		
		server = gethostbyname(argv[1]);
		if(server == NULL)
		{
		fprintf(stderr, "Error, no such host");
		
}
		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *) server ->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
		serv_addr.sin_port = htons(portno);
		if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0)
			error("connection echoue");
		////////////////////////////////////
		/*Si vous souaite avoir une conversation intane avec le serveur 
		il vous faut mettre en commentaire  la ligne 52 jusqu a la ligne
		 74 puis enleve le commentaire qui se trouve a ligne 78 jusqu a la ligne 98 fait de mm pour le serveur*/
		FILE *f;
		int words = 0;
		
		char c;
		
		f = fopen("test.txt", "r");
		while((c = getc(f)) != EOF)
		{
			fscanf(f , "%s" , buffer);
			if(isspace(c) || c =='\t')
			words++;
		}
		
		write(sockfd , &words , sizeof(int));
		rewind(f);
		
		char ch;
		while(ch != EOF)
		{
			fscanf(f , "%s" , buffer);
			write(sockfd , buffer , 255);
			ch = fgetc(f);
		}
		printf("Le fihier est arrive avec succes \n\n");
		////////////////////////////////////////////
		//lancement de la convertion instantene avec la boucle while
		/*	
		while(1)
		{
			bzero(buffer, 255);
			fgets(buffer, 255 , stdin);
			n = write(sockfd, buffer , strlen(buffer));
			if(n < 0)
				error("Eroor on writing");
				
			bzero(buffer, 255);
			n = read(sockfd, buffer, 255);
			if(n < 0)
				error("Error on reading");
				
			printf("Server : %s", buffer);
			
			int i = strncmp("Bye", buffer, 3);
			if(i == 0)
			break;
		}
		*/
		
		close(sockfd);
		return 0;
		
}
