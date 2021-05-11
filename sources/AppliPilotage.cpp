//***********************************************************************
// Date : 23/05/2011		Auteur : MP Pinaud
// Nom du fichier : AppliPilotage.cpp
// Rôle : Programme de pilotage de robots Pekee.
// L'utilisateur a le choix entre plusieurs robots à piloter. 
// Historique : 
// 23/04/2021 par MP Pinaud
// Les noms et  adressse IP des robots sont configurés dans le fichier
//RobotsConfig.txt
//**********************************************************************


#include <iostream>
#include <fstream>


#include "../include/AppliPilotage.h"



//**********************************************************************
// Fonction : main
// Rôle : se connecter au robot et le commander
//**********************************************************************



int main(void)
{
	
	bool erreur = false;
	bool fin = false;


	// Lecture du fichier de configuration et initialisation des robots
	initRobots();
	
	int nbRobots = tabRobots.size();

	if( nbRobots == 0){
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "Erreur : Aucun robot a piloter" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		
		cout << "pour sortir : appuyer sur une touche caractere\n";
		char c;
		cin >> c;
	}

	else {

		while (fin == false)
		{
			CRobotPekee * robot = choisirRobot();
			
			if (robot == NULL)
				fin = true;
			else {
				piloterRobot( robot);
				
			}
		
		}

	}

	return 0 ;
}


	//********************************************************
	// Fonctions: InitRobots
	// rôle: Initialise les robots à piloter à partir du fichier RobotsConfig.txt
	//********************************************************
void initRobots()
{

	ifstream fileconfig("RobotsConfig.txt", ios::in);

	if (fileconfig)  // fichier existe
	{
		
		while (fileconfig.eof() == false)
		{
			string nom;
			string adrIP;
			fileconfig >> nom;
			fileconfig >> adrIP;

			CRobotPekee* robot = new CRobotPekee(nom, adrIP);
			if (robot->estConnecte())
			{
					cout << "connexion OK avec le robot " << robot->sonNom() << "  " << robot->sonAdrIP() << endl ;
					tabRobots.push_back(robot);
			}
			else {
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "probleme de connexion avec le robot " << robot->sonNom() << "  " << robot->sonAdrIP() << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			}
			
		}
	}
	else {
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "Erreur : le fichier RobotsConfig.txt est introuvable" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			
	}
}

	//********************************************************
	// Fonctions: choisirRobot
	// rôle: fait choisir à l'utilisateur le robot à piloter
	// Retour : un pointeur surle robot choisi
	//********************************************************
CRobotPekee * choisirRobot(){

	cout << "**************************************************************************" << endl;
	cout << "Quel robot voulez-vous piloter ?" << endl;
	
	int nbRobots =tabRobots.size(); 
	for (int i = 0; i < nbRobots; i++) 
		cout << i + 1 << " : le robot " << tabRobots[i]->sonNom() << " adresse " << tabRobots[i]->sonAdrIP() << endl;
			
			
	cout  <<"0 : pour sortir" << endl;
	cout << "**************************************************************************" << endl << endl;
			
	int choix;
	cin >> choix;

	CRobotPekee* robot =NULL;
	if (choix >0 && choix < nbRobots + 1)
		robot = tabRobots[choix -1];
			
	return robot;

}

	//********************************************************
	// Fonctions: piloterRobot
	// rôle: fait choisir à l'utilisateur les commandes de pilotage 
	//et les fait exécuter par le robot
	// Paramètre d'entrée : un pointeur sur le robot à piloter
	//********************************************************
 void piloterRobot(CRobotPekee * robot){

	 int rep;
	
	 do {
		cout << "Piloter le robot" << robot->sonNom() << "  " << robot->sonAdrIP()<< endl;
		cout << "**************************************************************************" << endl;
		cout << "1 - Avancer" << endl;
		cout << "2 - Reculer" << endl;
		cout << "3 - Tourner a gauche  " << endl;
		cout << "4 - Tourner a droite" << endl;
		//cout << "5 - Avancer sur une distance" << endl;
		cout << "0 - Fin pilotage du robot" << endl;
		cout << "**************************************************************************" << endl << endl;

					
		cin >> rep;

		switch (rep) {
			case 1:
					//  AVANCER
					robot->avancer();
					break;
			case 2:
					//  RECULER
					robot->reculer();
					break;

			case 3:	//  TOURNER A GAUCHE
					robot->tournerG();
					break;

			case 4:	//  TOURNER A DROITE
					robot->tournerD();
					break;

			case 5:	//  AVANCER sur une distance
					float distance;
					cout << "Quelle distance de deplacement ?";
					cin >> distance;
					robot->avancer(distance,100);
					break;

			case 0:
					break;
								
			default: cout << "Erreur de saisie" << endl;
					break;
			}
		} while (rep != 0);
				
 }