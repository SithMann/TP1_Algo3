#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define M 3

/* Fonction tour de jeu pour le joueur
*  Demande une saisie et renvoie la valeur jouée
*/
int tourJoueur(){
    int num;
    do{
        printf("Joueur A, ajoutez un nombre entre 1 et 3 :");
        scanf("%d", &num);
        if(num < 1 || num > 3) printf("Le nombre doit etre compris entre 1 et 3 !\n");
    }while(num < 1 || num > 3);
    return num;
}

/* Fonction tour de jeu pour l'ordi
*  Tire un nombre aléatoire et renvoie la valeur jouée
*/
int tourOrdi(int count){
    if(count <=17)
        return rand()%M+1;
    else return N - count;
}

/* Fonction du jeu, fait appel aux fonctions de tours de jeu
*  Met le compte à jour à chaque tour et renvoie le vainqueur (1 joueur, 2 ordi)
*/
int boucleJeu(){
    int count = 0, numA, numB;
    while(1){
        numA = tourJoueur();
        count += numA;
        printf("Joueur A joue : %d          Total : %d\n", numA, count);
        if(count==20) return 1;
        else if(count>20) return 2;
        else {
            numB = tourOrdi(count);
            count += numB;
            printf("Joueur B joue : %d          Total : %d\n", numB, count);
            if(count==20) return 2;
        }
    }
}

int main(){
    srand(time(NULL));

    switch(boucleJeu()){
        case 1: printf("Le joueur A gagne !\n");
                break;
        case 2: printf("Le joueur B (Ordi) gagne !\n");
                break;
        default: printf("erreur\n");
    }

    return 0;
}