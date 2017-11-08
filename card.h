#pragma once
#include <iostream>
#include <string>

using namespace std;


class mCard
{
	//Données membres
	int Id;
	string Nom;
	string Prenom;
	string Adresse;
	string Code;
	string Ville;




public:
	mCard();

	int getId();
	string getNom();
	string getPrenom();
	string getAdresse();
	string getCode();
	string getVille();

	void setId(int Id);
	void setNom(string Nom);
	void setPrenom(string Prenom);
	void setAdresse(string Adresse);
	void setCode(string Code);
	void setVille(string Ville);

	void display();
	void del();
	
};
