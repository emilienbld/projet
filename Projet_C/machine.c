#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "machine.h"

// Fonction pour g�n�rer un symbole al�atoire
char generateSymbol() {
    const char symbols[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    return symbols[rand() % 6];
}

int main() {
    srand(time(0)); // Initialisation de la graine pour la g�n�ration al�atoire

    char rouleaux[3]; // Trois rouleaux
    int mise = 10; // Mise par tour
    int solde = 0; // Solde de d�part
    int ajout = 0; // Ajout au solde
    int retrait = 0; // Retret du solde 

    printf("Bienvenue � la machine � sous ! Mise par tour : %d\n", mise);

    while (1) {

        printf("Solde actuel : %d cr�dits\n", solde);
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
                    // Remplir les rouleaux avec des symboles al�atoires
                    for (int i = 0; i < 3; ++i) {
                        rouleaux[i] = generateSymbol();
                    }

                    // Afficher les symboles
                    printf("Rouleaux : %c %c %c\n", rouleaux[0], rouleaux[1], rouleaux[2]);

                    // V�rifier les gains (exemple simplifi�)
                    if (rouleaux[0] == rouleaux[1] && rouleaux[1] == rouleaux[2]) {
                        printf("F�licitations, vous avez gagn� ! +%d cr�dits.\n", mise * 10);
                    }
                    else {
                        printf("Dommage, vous avez perdu.\n");
                    }

                    // Demander � l'utilisateur s'il souhaite continuer � jouer
                    char choice;
                    printf("Voulez-vous jouer � nouveau ? (O/N) : ");
                    scanf_s(" %c", &choice);
                    if (choice != 'O' && choice != 'o') {
                        break; // Sortir de la boucle si l'utilisateur ne souhaite pas jouer � nouveau
                    }

                }
                break;
                case 2:
                    printf("Montant de l'ajout : ");
                    scanf_s("%d", &ajout);

                    if (ajout > 0) {
                        solde += ajout;
                        printf("Solde mis � jour : %d cr�dits\n", solde);

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
                        printf("Solde mis � jour : %d cr�dits\n", solde);
                    }
                    else {
                        printf("Montant invalide.Veuillez ajouter une somme positive.");
                    }



            
        }
            


        
    }

    printf("Merci d'avoir jou� !\n");

    return 0;
}
