#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "card.h"
#define TAILLE 100

int menu();
int FindEmpty(mCard Card[]);
int Id = 0;
int choice = 0;
string tempo;

void AddCard(mCard Card[]);
void DisplayCard(mCard Card[]);
void DeleteCard(mCard Card[]);
void ModifCard(mCard Card[]);

/*
Menu principal :
But : ergonomie de l'interface
Entrée : commande que la personne souhaite effectuer
Sortie : la personne peut effectuer ce qu'elle veut faire
*/
int menu(){


system("cls");	//Affichage du menu
	std::cout << "Que voulez-vous faire ?\n";
	std::cout << "Tapez 1 pour ajouter une carte !\n";
	std::cout << "Tapez 2 pour supprimer une carte !\n";
	std::cout << "Tapez 3 pour modifier une carte !\n";
	std::cout << "Tapez 4 pour afficher une carte !\n";
	std::cout << "Tapez 0 pour quitter !\n\n";

	std::cin >> choice;	
	return choice;	//Retourne le choix du menu
}

/*
Fonction ajouter :
But : ajouter une nouvelle carte
Entrée : donées de la carte
Sortie : carte inscrite et identifiant généré
*/
void AddCard(mCard Card[]){

	mCard info;	//sert a enregistrer l'information pour l'assigner plus tard à une case vide


	int empty = FindEmpty(Card);	//trouve une place dans le tableau

system("cls");
	std::cout << "Ajouter une carte\n";

	cin.ignore();
	std::cout << "Nom : \n";
	std::getline (std::cin, tempo);
	info.setNom(tempo);

	std::cout << "Prenom : \n";
	std::getline (std::cin, tempo);
	info.setPrenom(tempo);

	std::cout << "Adresse : \n";
	std::getline (std::cin, tempo);
	info.setAdresse(tempo);

	std::cout << "Code Postal : \n";
	std::getline (std::cin, tempo);
	info.setCode(tempo);

	std::cout << "Ville : \n";
	std::getline (std::cin, tempo);
	info.setVille(tempo);
		
		Card[empty].setId(empty);

		Card[empty].setNom(info.getNom());

		Card[empty].setPrenom(info.getPrenom());

		Card[empty].setAdresse(info.getAdresse());

		Card[empty].setCode(info.getCode());

		Card[empty].setVille(info.getVille());
	}


int FindEmpty(mCard Card[]) {

	int i = 1;

	while (Card[i].getId() != 0) {

		i++;
	}

	return i;
}

/*
Fonction afficher :
But : afficher les données d'une carte
Entrée : l'identifiant de la carte à afficher
Sortie : affichage des données de la carte dont l'ID correspond
*/
void DisplayCard(mCard Card[]) {


	system("cls");
	std::cout << "Affiche Carte\n";

	std::cout << "ID de la carte à afficher : ";
	std::cin >> Id;

	if (Card[Id].getId() == 0) {	
		std::cout << "ID invalide\n";

	} else {
		Card[Id].display();	//Affichage des données
	}

	system("pause");
}

/*
Fonction supprimer :
But : supprimer la carte dont l'identifiant correspond
Entrée : l'identifiant de la carte à supprimer
Sortie : suppression de la carte
*/
void DeleteCard(mCard Card[]) {

	system("cls");
	std::cout << "Supprimer une carte\n";

	std::cout << "ID de la carte à supprimer : ";
	std::cin >> Id;

	if (Card[Id].getId() == 0) {	
		std::cout << "ID invalide\n";

	}
	else {
		Card[Id].del();	//Suppression des données de la classe

		std::cout << "Carte supprimee\n ";
	}
	system("pause");
}

/*
Fonction modifier :
But : modifier les données d'une carte
Entrée : l'identifiant de la carte à modifier
Sortie : la carte avec les modifications effectuées
*/
void ModifCard(mCard Card[]) {

	system("cls");
	std::cout << "Modifier une carte\n";

	std::cout << "ID de la carte à modifier : ";
	std::cin >> Id;

	if (Card[Id].getId() == 0) {
		std::cout << "ID invalide\n";
	} else {
		
		Card[Id].display();

		std::cout << "\n\nQuelle information souhaitez vous modifier ?\n";
		std::cout << "Tapez 1 pour nom\n";
		std::cout << "Tapez 2 pour le prénom\n";
		std::cout << "Tapez 3 pour l'adresse\n";
		std::cout << "Tapez 4 pour le code postal\n";
		std::cout << "Tapez 5 pour la ville\n";

		std::cin >> choice;

		std::cout << "\n\nEntrez votre modification ! :\n";

		cin.ignore();
		std::getline(std::cin, tempo);

		switch (choice) {

		case 1:
			Card[Id].setNom(tempo);
			break;

		case 2:
			Card[Id].setPrenom(tempo);
			break;

		case 3:
			Card[Id].setAdresse(tempo);
			break;

		case 4:
			Card[Id].setCode(tempo);
			break;

		case 5:
			Card[Id].setVille(tempo);
			break;
		}
	}

	system("pause");
}

int main()
{
	mCard tableau[TAILLE]; // Création du tableau de Carte
	bool action = true; 

	while (action) { // tant que action = true l'application tourne

		switch (menu()) {	//Menu 

		case 1:	//Ajout d'une carte
			AddCard(tableau);
			break;

		case 2:	//Suppression d'une carte
			DeleteCard(tableau);
			break;

		case 3:	//Modification d'une carte
			ModifCard(tableau);
			break;

		case 4:	//Affichage d'une carte
			DisplayCard(tableau);
			break;

		case 0:	//Fin de l'utilisation de l'appli

			action = false;
			break;

		default:
			break;
		}
	}
	return 0;
}