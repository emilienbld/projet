#define _CRT_SECURE_NO_WARNINGS

void Start() {
	printf("Jeu de Roulette de Casino.\n");
};

int Menu() {
	enum MenuButtons {
		Nouvelle_partie = 1,
		Quitter
	};
};

int End() {
	End(0);
};

int numeroAleatoire(int max) {
	return rand() % max;
}

//Couleur du numéro gagnant
//void afficherCouleur(numeros) {
//	if (numeros == 0) {
//		printf("vert\n");
//	}
//	else if (numeros % 2 == 0) {
//		printf("noir\n");
//	}
//	else {
//		printf("rouge\n");
//	}
//}

void afficherParite(int numero) {
	if (numero == 0) {
		printf("neutre\n");
	}
	else if (numero % 2 == 0) {
		printf("pair\n");
	}
	else {
		printf("impair\n");
	}
}

void afficherPassManque(int numero) {
	if (numero == 0) {
		printf("nul\n");
	}
	else if (numero >= 1 && numero <= 18) {
		printf("pass\n");
	}
	else if (numero >= 19 && numero <= 36) {
		printf("manque\n");
	}
}

void afficherPlage(int numero) {
	if (numero >= 1 && numero <= 12) {
		printf("1 ers 12\n");
	}
	else if (numero >= 13 && numero <= 24) {
		printf("2 nds 12\n");
	}
	else if (numero >= 25 && numero <= 36) {
		printf("3 èmes 12\n");
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
		printf("t1\n");
	}
	else if (estDansTiersDeux) {
		printf("t2\n");
	}
	else if (estDansTiersTrois) {
		printf("t3\n");
	}
}