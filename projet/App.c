#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Launcher.h"

int main() {
    Start();
    Menu();
    // Initialisation du générateur de nombres aléatoires
    srand(time(0));

    // Tableau des numéros de roulette
    int numeros[37] = {
        0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30,
        8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7,
        28, 12, 35, 3, 26
    };
    int TiersUn[12] = {
        3,6,9,12,15,18,21,24,27,30,33,36
    };
    int TiersDeux[12] = {
        2,5,8,11,14,17,20,23,26,29,32,35
    };
    int TiersTrois[12] = {
        1,4,7,10,13,16,19,22,25,28,31,34
    };

    // Boucle du jeu 
    while (1) {
        printf("0 - Quitter le jeu\n");
        printf("1 - Jouer\n");

        printf("Choisissez une option : ");
        int choix;
        scanf_s("%d", &choix);

        if (choix == 0) {
            printf("Merci d'avoir joué !\n");
            printf("Au revoir.\n");
            break;
        }
        else if (choix == 1) {
            int mise;
            printf("Entrez votre mise : ");
            scanf_s("%d", &mise);

            if (mise <= 0) {
                printf("Mise invalide. La mise doit être supérieure à zéro.\n");
                continue;
            }

            int numeroGagnant = rand() % 37; // Génère un numéro aléatoire entre 0 et 36

            printf("La roulette tourne...\n");
            //printf("Le numéro gagnant est : %d\n", numeroGagnant);
            //affiche le numéro gagnant de la roulette
            int numeroChoisi = numeros[numeroGagnant];
            printf("Le numéro gagnant est : %d\n", numeroChoisi);


            // Couleur des numéros
            printf("La couleur du numéro gagnant est : ");
            if (numeroChoisi == 0) {
                printf("vert\n");
            }
            else if (numeroChoisi % 2 == 0) { // Numéros sont noirs
                printf("noir\n");
            }
            else { // Numéros sont rouges
                printf("rouge\n");
            }

            // Pair ou impair du numéro gagnant
            printf("La parité du numéro gagnant est : ");
            if (numeroChoisi == 0) {
                printf("neutre\n");
            }
            else if (numeroChoisi % 2 == 0) {
                printf("pair\n");
            }
            else {
                printf("impair\n");
            }

            // Pass ou manque du numéro gagnant
            printf("Le numéro gagnant est dans : ");
            if (numeroChoisi == 0) {
                printf("nul\n");
            }
            else if (numeroChoisi >= 1 && numeroChoisi <= 18) {
                printf("pass\n");
            }
            else if (numeroChoisi >= 19 && numeroChoisi <= 36) {
                printf("manque\n");
            }

            // 1ers 12, 2nds 12 ou 3èmes 12
            printf("Plage du numéro gagnant : ");
            if (numeroChoisi >= 1 && numeroChoisi <= 12) {
                printf("1 ers 12\n");
            }
            else if (numeroChoisi >= 13 && numeroChoisi <= 24) {
                printf("2 nds 12\n");
            }
            else if (numeroChoisi >= 25 && numeroChoisi <= 36) {
                printf("3 èmes 12\n");
            }
        }
    }
    printf("\n\n");
    return 0;
}