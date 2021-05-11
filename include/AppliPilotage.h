//******************************************************** 
// Auteur MP Pinaud
// date : 23/05/2011
// fichier: AppliPilotage.h
// Déclaration des fonctions et des variables utiles pour l'application
// de pilotage
//********************************************************
#include <vector>
using namespace std;

#include "RobotPekee.h"



vector <CRobotPekee*> tabRobots; // les robots à piloter


	//********************************************************
	// Fonctions: InitRobots
	// rôle: Initialise les robots à piloter à partir du fichier RobotsConfig.txt
	//
	//********************************************************
void initRobots();


	//********************************************************
	// Fonctions: choisirRobot
	// rôle: fait choisir à l'utilisateur le robot à piloter
	// Retour : un pointeur sur le robot choisi
	//********************************************************
CRobotPekee * choisirRobot();

	//********************************************************
	// Fonctions: piloterRobot
	// rôle: fait choisir à l'utilisateur les commandes de pilotage 
	//et les fait exécuter par le robot
	// Paramètre d'entrée : un pointeur sur le robot à piloter
	//********************************************************
 void piloterRobot(CRobotPekee * robot);