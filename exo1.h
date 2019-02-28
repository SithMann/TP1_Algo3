#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define M 3

int max(int a, int b);
int min(int a, int b);
int hypotheseJoueur(int count);
int coupOrdi(int count);
int tourJoueur();
int tourOrdi(int count);
int boucleJeu();
int minmax(int count);