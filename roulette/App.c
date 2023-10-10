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
            int pari;
            printf("Entrez votre pari : ");
            scanf_s("%d, &pari");

            if (mise <= 0) {
                printf("Mise invalide. La mise doit être supérieure à zéro.\n");
                continue;
            }

            int numeroGagnant = numeroAleatoire(37); // Génère un numéro aléatoire entre 0 et 36

            printf("La roulette tourne...\n");
            int numeroChoisi = numeros[numeroGagnant];
            printf("Le numéro gagnant est : %d\n", numeroChoisi);


            // Couleur des numéros
            //int numeroGagnant = 0; // Vous pouvez changer le numéro ici pour tester
            //afficherCouleur(numeros[numeroGagnant]);


            //printf("La couleur du numéro gagnant est : ");
            //afficherCouleur(numeroChoisi);

            printf("La parité du numéro gagnant est : ");
            afficherParite(numeroChoisi);

            printf("Le numéro gagnant est dans : ");
            afficherPassManque(numeroChoisi);

            printf("Plage du numéro gagnant : ");
            afficherPlage(numeroChoisi);

            printf("Tiers du numéro gagnant : ");
            afficherTiers(numeroChoisi);
        }
    }
    printf("\n\n");
    return 0;
}