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
        printf("\n\n0 - Quitter le jeu\n");
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
            //Combien le joueur veux miser
            //int mise;
            //printf("Entrez votre mise : ");
            //scanf_s("%d", &mise);
            //
            //if (mise <= 0) {
            //    printf("Mise invalide. La mise doit être supérieure à zéro.\n");
            //    continue;
            //}

            ////Choix du pari
            //int pari;
            //printf("Faites vos jeux : ");
            //scanf_s("%d", &pari);

            int nbParis;
            printf("Combien de paris souhaitez-vous faire ? ");
            scanf("%d", &nbParis);

            int paris[100]; // Vous pouvez ajuster la taille selon vos besoins
            int mises[100];

            for (int i = 0; i < nbParis; i++) {
                printf("Pari %d : Entrez le numéro : ");
                scanf("%d", &paris[i]);
                printf("Entrez la mise correspondante : ");
                scanf("%d", &mises[i]);
            }

            gain(paris, mises, nbParis);


            int numeroGagnant = numeroAleatoire(37); // Génère un numéro aléatoire entre 0 et 36

            printf("Rien ne vas plus...\n");
            int numeroChoisi = numeros[numeroGagnant];
            printf("Le numéro gagnant est : %d\n", numeroChoisi);

            afficherParite(numeroChoisi);
            afficherPassManque(numeroChoisi);
            afficherPlage(numeroChoisi);
            afficherTiers(numeroChoisi);
            
            //gain(pari, numeroChoisi, mise);
            //gain(paris, mises, nbParis);


        }
    }
    printf("\n\n");
    return 0;
}