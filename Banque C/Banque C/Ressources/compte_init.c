//
//  compte_init.c
//  Banque HSBC C
//
//  Created by Fabio Tavares Marques  on 11/10/2023.
//

#include "compte_init.h"
#include "compte_structure.h"

void accountInit(void){
    
    struct Compte AFE;
    struct Compte KAI;
    struct Compte JAO;


    // Initialisation manuelle des informations pour le compte
    initialiserCompte(&AFE, 2838445, "Evian EAU", 1500);
    initialiserCompte(&KAI, 3828281, "Cristaline MINERALE", 12990);
    initialiserCompte(&JAO, 9384928, "Volvic NATURELLE", 4500);


    printf("Informations du compte :\n");
    afficherCompte(&AFE);
    printf("\n");
    afficherCompte(&KAI);
    printf("\n");
    afficherCompte(&JAO);

}

