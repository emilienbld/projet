#define _CRT_SECURE_NO_WARNINGS
#include "Launcher.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Start() {
	printf("Jeu de Roulette de Casino.\n");
};

void Menu() {
	enum Jouer {
		Jouer = 1,
		Quiter
	};

	printf("\nQue voulez vous faire ? Jouer tapez [1] Quiter tapez [2] \n");
	int action;
	scanf_s("%d", &action);

	enum MenuButtons MonMenuBoutons = action;

	switch (MonMenuBoutons) {
	case Jouer:
		while (1) {
			Roulette();
			int choix;
			printf("Voulez-vous refaire une partie ? Jouer [1] Quiter [2] : ");
			scanf_s("%d", &choix);
			system("cls");
			if (choix == 2) {
				break;
			}
		}
		break;
	case Quiter:
		End();
	default:
		break;
	};
};

void End() {
	exit(0);
};

int numeroAleatoire(int max) {
	return rand() % max;
}

//Couleur du num�ro gagnant
//void afficherCouleur(numeros) {
//	if (numeros == 0) {
//		printf("La couleur du num�ro gagnant est : vert\n");
//	}
//	else if (numeros % 2 == 0) {
//		printf("La couleur du num�ro gagnant est : noir\n");
//	}
//	else {
//		printf("La couleur du num�ro gagnant est : rouge\n");
//	}
//}

void afficherCouleur(int numeroGagnant) {
	if (numeroGagnant == 0) {
		printf("La couleur du num�ro gagnant est : vert\n");
	}
	else if (numeroGagnant % 2 == 0) {
		printf("La couleur du num�ro gagnant est : rouge\n");
	}
	else {
		printf("La couleur du num�ro gagnant est : noir\n");
	}
}




void afficherParite(int numero) {
	if (numero == 0) {
		printf("La parite du numero gagnant est : neutre\n");
	}
	else if (numero % 2 == 0) {
		printf("La parite du numero gagnant est : pair\n");
	}
	else {
		printf("La parite du numero gagnant est : impair\n");
	}
}

void afficherPassManque(int numero) {
	if (numero == 0) {
		printf("Le numero gagnant est : nul\n");
	}
	else if (numero >= 1 && numero <= 18) {
		printf("Le numero gagnant est du c�te : pass\n");
	}
	else if (numero >= 19 && numero <= 36) {
		printf("Le numero gagnant est du c�te : manque\n");
	}
}

void afficherPlage(int numero) {
	if (numero >= 1 && numero <= 12) {
		printf("Plage du numero gagnant : 1 ers 12\n");
	}
	else if (numero >= 13 && numero <= 24) {
		printf("Plage du numero gagnant : 2 nds 12\n");
	}
	else if (numero >= 25 && numero <= 36) {
		printf("Plage du numero gagnant : 3 emes 12\n");
	}
}

//void afficherTiers(int numero) {
//	int TiersUn[12] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 };
//	int TiersDeux[12] = { 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 };
//	int TiersTrois[12] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };
//
//	int estDansTiersUn = 0;
//	int estDansTiersDeux = 0;
//	int estDansTiersTrois = 0;
//
//	for (int i = 0; i < 12; i++) {
//		if (numero == TiersUn[i]) {
//			estDansTiersUn = 1;
//		}
//		if (numero == TiersDeux[i]) {
//			estDansTiersDeux = 1;
//		}
//		if (numero == TiersTrois[i]) {
//			estDansTiersTrois = 1;
//		}
//	}
//
//	if (estDansTiersUn) {
//		printf("Le numero gagnant est dans le tiers: t1\n");
//	}
//	else if (estDansTiersDeux) {
//		printf("Le numero gagnant est dans le tiers : t2\n");
//	}
//	else if (estDansTiersTrois) {
//		printf("Le numero gagnant est dans le tiers : t3\n");
//	}
//}

//void gain(int paris[], int mises[], int nbParis, int numeroChoisi) {
//	int totalGains = 0;
//	for (int i = 0; i < nbParis; i++) {
//		if (paris[i] == numeroChoisi) {
//			int gain = mises[i] * 36;
//			totalGains += gain;
//			printf("Pari sur le numero %d, mise : %d, gain : %d\n", paris[i], mises[i], gain);
//		}
//	}
//
//	if (totalGains > 0) {
//		printf("Total des gains : %d\n", totalGains);
//	}
//	else {
//		printf("Desole, vous avez perdu toutes vos mises.\n");
//	}
//}

void Roulette() {
	srand(time(0));

	int numeros[37] = {
		0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26
	};

	int nbParis;
	printf("\nCombien de paris souhaitez-vous faire ? ");
	scanf("%d", &nbParis);

	int paris[100];
	int mises[100];

	for (int i = 0; i < nbParis; i++) {
		printf("Pari %d : Pour un nombre de 0 a 36 [0-36], pair [37] impair [38], pass [39] manque[40], 1 ers 12 [41], 2 nds 12 [42], 3 emes 12 [43], rouge [44], noir [45] : ", i + 1);
		scanf("%d", &paris[i]);

		if (paris[i] < 0 || (paris[i] > 36 && paris[i] < 37) || (paris[i] > 45)) {
			printf("Pari invalide. Choisissez un numero entre 0 et 36, ou [37] pour pair, [38] pour impair, [39] pour pass, [40] pour manque, [41] pour 1 ers 12, [42] pour 2 nds 12, [43] pour 3 emes 12, rouge [44], noir [45].\n");
			i--; // R�p�ter la saisie du pari pour cette it�ration.
			continue;
		}

		printf("Entrez la mise correspondante : ");
		scanf("%d", &mises[i]);
	}

	int numeroGagnant = numeroAleatoire(37); // G�n�re un num�ro al�atoire entre 0 et 36

	printf("Rien ne va plus...\n");
	int numeroChoisi = numeros[numeroGagnant];
	printf("Le numero gagnant est : %d\n", numeroChoisi);

	afficherParite(numeroChoisi);
		afficherPassManque(numeroChoisi);
		afficherPlage(numeroChoisi);
		//afficherTiers(numeroChoisi);
		afficherCouleur(numeroChoisi);
		//gain(paris, mises, nbParis, numeroChoisi);


	for (int i = 0; i < nbParis; i++) {
		if (paris[i] >= 0 && paris[i] <= 36) {
			if (paris[i] == numeroChoisi) {
				printf("Pari sur le numero %d, mise : %d, gain : %d\n", paris[i], mises[i], mises[i] * 36);
			}
		}
		else if (paris[i] == 37) { // Pari sur la parit� (pair)
			if (numeroChoisi % 2 == 0) {
				printf("Pari sur la parite (pair), mise : %d, gain : %d\n", mises[i], mises[i] * 2);
			}
		}
		else if (paris[i] == 38) { // Pari sur la parit� (impair)
			if (numeroChoisi % 2 != 0) {
				printf("Pari sur la parite (impair), mise : %d, gain : %d\n", mises[i], mises[i] * 2);
			}
		}
		else if (paris[i] == 39) { // Pari sur le c�t� (pass)
			if (numeroChoisi >= 1 && numeroChoisi <= 18) {
				printf("Pari sur le cote (pass), mise : %d, gain : %d\n", mises[i], mises[i] * 2);
			}
		}
		else if (paris[i] == 40) { // Pari sur le c�t� (manque)
			if (numeroChoisi >= 19 && numeroChoisi <= 36) {
				printf("Pari sur le cote (manque), mise : %d, gain : %d\n", mises[i], mises[i] * 2);
			}
		}
		else if (paris[i] == 41) { // Pari sur la plage (1 ers 12)
			if (numeroChoisi >= 1 && numeroChoisi <= 12) {
				printf("Pari sur la plage (1 ers 12), mise : %d, gain : %d\n", mises[i], mises[i] * 3);
			}
		}
		else if (paris[i] == 42) { // Pari sur la plage (2 nds 12)
			if (numeroChoisi >= 13 && numeroChoisi <= 24) {
				printf("Pari sur la plage (2 nds 12), mise : %d, gain : %d\n", mises[i], mises[i] * 3);
			}
		}
		else if (paris[i] == 43) { // Pari sur la plage (3 emes 12)
			if (numeroChoisi >= 25 && numeroChoisi <= 36) {
				printf("Pari sur la plage (3 emes 12), mise : %d, gain : %d\n", mises[i], mises[i] * 3);
			}
		}
		else if (paris[i] == 44) { // Pari sur la couleur rouge
			if (numeroChoisi >= 1 && numeroChoisi <= 10 || numeroChoisi >= 19 && numeroChoisi <= 28) {
				printf("Pari sur la couleur rouge, mise : %d, gain : %d\n", mises[i], mises[i] * 2);
			}
		}
		else if (paris[i] == 45) { // Pari sur la couleur noire
			if (numeroChoisi >= 11 && numeroChoisi <= 18 || numeroChoisi >= 29 && numeroChoisi <= 36) {
				printf("Pari sur la couleur noire, mise : %d, gain : %d\n", mises[i], mises[i] * 2);
			}
		}
	}

}