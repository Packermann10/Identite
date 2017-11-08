#include "card.h"


mCard::mCard()
{
	setId(0);
}

int mCard::getId()
{
	return Id;
}

string mCard::getNom()
{
	return Nom;
}

string mCard::getPrenom()
{
	return Prenom;
}

string mCard::getAdresse()
{
	return Adresse;
}

string mCard::getCode()
{
	return Code;
}

string mCard::getVille()
{
	return Ville;
}

void mCard::setId(int Id)
{
	this->Id = Id;

}

void mCard::setNom(string Nom)
{
	this->Nom = Nom;
}

void mCard::setPrenom(string Prenom)
{
	this->Prenom = Prenom;
}

void mCard::setAdresse(string Adresse)
{
	this->Adresse = Adresse;
}

void mCard::setCode(string Code)
{
	this->Code = Code;
}

void mCard::setVille(string ville)
{
	this->Ville = ville;
}

void mCard::display() // Affiche toute les données de la classe
{
	cout << "Id : " << getId() << endl;
	cout << "Nom : " << getNom() << endl;
	cout << "Prenom : " << getPrenom() << endl;
	cout << "Adresse : " << getAdresse() << endl;
	cout << "Code postal : " << getCode() << endl;
	cout << "Ville : " << getVille() << endl;
}

void mCard::del()  // Supprime toute les données de la classe
{
	setId(0);
	setNom("");
	setPrenom("");
	setAdresse("");
	setCode("");
	setVille("");

}
