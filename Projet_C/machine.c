#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine.h"

// Fonction pour générer un symbole aléatoire
char generateSymbol() {
    const char symbols[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    return symbols[rand() % 6];
}

int main() {
    srand(time(0)); // Initialisation de la graine pour la génération aléatoire

    char rouleaux[3]; // Trois rouleaux
    int mise = 10; // Mise par tour
    int solde = 0; // Solde de départ
    int ajout = 0; // Ajout au solde
    int retrait = 0; // Retret du solde 

    printf("Bienvenue à la machine à sous ! Mise par tour : %d\n", mise);

    while (1) {

        printf("Solde actuel : %d crédits\n", solde);
        printf("Menu :\n");
        printf("1. Tourner les rouleaux\n");
        printf("2. Ajouter de l'argent\n");
        printf("3. Retirer de l'argent\n");
        printf("4. Quitter\n");
        printf("Faites un choix : ");

        int choix;
        scanf_s("%d", &choix);

        switch (choix) {
            case 1:
                if (solde < mise) {
                    printf("Solde insuffisant.Veuillez ajouter de l'argent.\n");
                }
                else {
                    solde -= mise;
                    // Remplir les rouleaux avec des symboles aléatoires
                    for (int i = 0; i < 3; ++i) {
                        rouleaux[i] = generateSymbol();
                    }

                    // Afficher les symboles
                    printf("Rouleaux : %c %c %c\n", rouleaux[0], rouleaux[1], rouleaux[2]);

                    // Vérifier les gains (exemple simplifié)
                    if (rouleaux[0] == rouleaux[1] && rouleaux[1] == rouleaux[2]) {
                        printf("Félicitations, vous avez gagné ! +%d crédits.\n", mise * 10);
                    }
                    else {
                        printf("Dommage, vous avez perdu.\n");
                    }

                    // Demander à l'utilisateur s'il souhaite continuer à jouer
                    char choice;
                    printf("Voulez-vous jouer à nouveau ? (O/N) : ");
                    scanf_s(" %c", &choice);
                    if (choice != 'O' && choice != 'o') {
                        break; // Sortir de la boucle si l'utilisateur ne souhaite pas jouer à nouveau
                    }

                }
                break;
                case 2:
                    printf("Montant de l'ajout : ");
                    scanf_s("%d", &ajout);

                    if (ajout > 0) {
                        solde += ajout;
                        printf("Solde mis à jour : %d crédits\n", solde);

                    }
                    else {
                        printf("Montant invalide.Veuillez ajouter une somme positive.");
                    }
                break;
                case 3 : 
                    printf("Montant du retrait : ");
                    scanf_s("%d", &retrait);
                    if (retrait > 0 || retrait <= solde) {
                        solde -= retrait;
                        printf("Solde mis à jour : %d crédits\n", solde);
                    }
                    else {
                        printf("Montant invalide.Veuillez ajouter une somme positive.");
                    }



            
        }
            


        
    }

    printf("Merci d'avoir joué !\n");

    return 0;
}
