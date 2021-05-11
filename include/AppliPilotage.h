//******************************************************** 
// Auteur MP Pinaud
// date : 23/05/2011
// fichier: AppliPilotage.h
// D�claration des fonctions et des variables utiles pour l'application
// de pilotage
//********************************************************
#include <vector>
using namespace std;

#include "RobotPekee.h"



vector <CRobotPekee*> tabRobots; // les robots � piloter


	//********************************************************
	// Fonctions: InitRobots
	// r�le: Initialise les robots � piloter � partir du fichier RobotsConfig.txt
	//
	//********************************************************
void initRobots();


	//********************************************************
	// Fonctions: choisirRobot
	// r�le: fait choisir � l'utilisateur le robot � piloter
	// Retour : un pointeur sur le robot choisi
	//********************************************************
CRobotPekee * choisirRobot();

	//********************************************************
	// Fonctions: piloterRobot
	// r�le: fait choisir � l'utilisateur les commandes de pilotage 
	//et les fait ex�cuter par le robot
	// Param�tre d'entr�e : un pointeur sur le robot � piloter
	//********************************************************
 void piloterRobot(CRobotPekee * robot);