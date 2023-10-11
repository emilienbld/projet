#ifndef LAUNCHER_H
#define LAUNCHER_H

void Start();
void Menu();
void End();
int numeroAleatoire(int max);
//void afficherCouleur(int indice);
void afficherParite(int numero);
void afficherPassManque(int numero);
void afficherPlage(int numero);
void afficherTiers(int numero);
//void gain(int pari, int numeroChoisi, int mise);
void gain(int paris[], int mises[], int nbParis);



#endif LAUNCHER_H