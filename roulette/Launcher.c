#include "Launcher.h"
#define _CRT_SECURE_NO_WARNINGS

void Start() {
	printf("Jeu de Roulette de Casino.\n");
};

void Menu() {

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
//		printf("La couleur du num�ro gagnant est : vertte\n");
//	}
//	else if (numeros % 2 == 0) {
//		printf("La couleur du num�ro gagnant est : noire\n");
//	}
//	else {
//		printf("La couleur du num�ro gagnant est : rouge\n");
//	}
//}

void afficherParite(int numero) {
	if (numero == 0) {
		printf("La parit� du num�ro gagnant est : neutre\n");
	}
	else if (numero % 2 == 0) {
		printf("La parit� du num�ro gagnant est : pair\n");
	}
	else {
		printf("La parit� du num�ro gagnant est : impair\n");
	}
}

void afficherPassManque(int numero) {
	if (numero == 0) {
		printf("Le num�ro gagnant est : nul\n");
	}
	else if (numero >= 1 && numero <= 18) {
		printf("Le num�ro gagnant est du c�t� : pass\n");
	}
	else if (numero >= 19 && numero <= 36) {
		printf("Le num�ro gagnant est du c�t� : manque\n");
	}
}

void afficherPlage(int numero) {
	if (numero >= 1 && numero <= 12) {
		printf("Plage du num�ro gagnant : 1 ers 12\n");
	}
	else if (numero >= 13 && numero <= 24) {
		printf("Plage du num�ro gagnant : 2 nds 12\n");
	}
	else if (numero >= 25 && numero <= 36) {
		printf("Plage du num�ro gagnant : 3 �mes 12\n");
	}
}

void afficherTiers(int numero) {
	int TiersUn[12] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 };
	int TiersDeux[12] = { 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 };
	int TiersTrois[12] = { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 };

	int estDansTiersUn = 0;
	int estDansTiersDeux = 0;
	int estDansTiersTrois = 0;

	for (int i = 0; i < 12; i++) {
		if (numero == TiersUn[i]) {
			estDansTiersUn = 1;
		}
		if (numero == TiersDeux[i]) {
			estDansTiersDeux = 1;
		}
		if (numero == TiersTrois[i]) {
			estDansTiersTrois = 1;
		}
	}

	if (estDansTiersUn) {
		printf("Le num�ro gagnant est dans le tiers: t1\n");
	}
	else if (estDansTiersDeux) {
		printf("Le num�ro gagnant est dans le tiers : t2\n");
	}
	else if (estDansTiersTrois) {
		printf("Le num�ro gagnant est dans le tiers : t3\n");
	}
}

//void gain(int pari, int numeroChoisi, int mise) {
//	if (pari == numeroChoisi) {
//		mise *= 36;
//		printf("F�licitations ! Votre mise a �t� multipli�e par 36.\n");
//	}
//	else {
//		printf("D�sol�, vous avez perdu votre mise.\n");
//		mise = 0;
//	}
//	return mise;
//}

void gain(int paris[], int mises[], int nbParis) {
	int totalGains = 0;
	int numeroGagnant = numeroAleatoire(37); // G�n�re un num�ro gagnant al�atoire
	printf("Le num�ro gagnant est : %d\n", numeroGagnant);

	for (int i = 0; i < nbParis; i++) {
		if (paris[i] == numeroGagnant) {
			int gain = mises[i] * 36;
			totalGains += gain;
			printf("Pari sur le num�ro %d, mise : %d, gain : %d\n", paris[i], mises[i], gain);
		}
	}

	if (totalGains > 0) {
		printf("Total des gains : %d\n", totalGains);
	}
	else {
		printf("D�sol�, vous avez perdu toutes vos mises.\n");
	}
}
