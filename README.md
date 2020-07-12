  # CECI EST LE PROJET DE FIN COURS DE SE

## Cette page vous donnera les instruction pour pouvoir execute le programme

### 1
ouvre un document dans le terminale et tapez la comande 
```sh
$ git clone https://github.com/NTUMBABU/PROJET.git
```
### 2
Apres avoir donwload les dossier ouvre le et allais dans
le document 'fichier'

### 3
Arrive dans le document vous trouverez 4 fichier
les fichier terminant avec le (.c) sont les codes source 
Et celle sans le (.c) a la fin sont les executable

### 4
pour lancer lancer le programme :
il faut ouvrir deux termineaux dans le dossier 'fichier', un terminale pour le serveur et un autres pour le client
il est a savoir qu'il faut d'abord executer le serveur en premier puis suivie du client.

## pour executer les serveur dans le terminal il faut tout simplement tapez la comande
```sh
$./SERVEUR 2020

```
### A savoir : le '2020' est le numero du port

## ensuite dans le second terminal tapez la commande
```sh
$./CLIENT 127.0.0.1 2020

``` 
### A savoir : le "127.0.0.1" est l'adresse IP du serveur et le '2020' est le numero de port du serveur...

A la fin du lancement du programme vous remarquere un nouveau fichier text qui a etait cree
