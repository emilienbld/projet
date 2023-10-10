//
//  Launch.h
//  Banque
//
//  Created by Fabio Tavares Marques  on 10/10/2023.
//

#ifndef Compte_h
#define Compte_h

#include <stdio.h>



// Structure d'un compte
struct Compte {
    int numero;
    char nom[50]; // Tableau de caractères pour stocker le nom
    int solde;
};

// Prototypes de fonctions associées aux personnes


void initialiserCompte(struct Compte *compte, int numero, const char *nom, int solde);
void afficherCompte(const struct Compte *compte);



#endif /* Launch_h */
