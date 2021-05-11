//******************************************************** 
// Auteur MP Pinaud
// date : 29/09/2010
// fichier: Robot.h
// Interface de la classe CRobotPekee 
// Enoncé : Robot Pekee pilotable à distance
//********************************************************
#pragma once
#include <string>
using namespace std;
#include "libRobotPekee.h"



class CRobotPekee : protected WRobotPekee
{

public:
	//********************************************************
	// méthode: CRobotPekee
	// rôle: Constructeur de la classe CRobot. Il effectue la 
	//			connexion au robot réel ou au robot simulé
	// paramètres d'entrée:
	//  adrIP : adresse  pour se connecter au robot réel 
	//			ou simulé (dans ce cas vaut localhost)
	//  n    : nom du robot
	// Sortie: un robot
	//********************************************************
	CRobotPekee(string un_nom , string une_adrIP );

	//********************************************************
	// méthode: ~CRobotPekee
	// rôle: Destructeur de la classe CRobotPekee. Il effectue la 
	//			deconnexion au robot réel ou au robot simulé
	//********************************************************
	~CRobotPekee(void);
	
	

	//********************************************************
	// méthode: est_connecte
	// rôle: indique si la connexion au robot reel ou simulé 
	//       est effective
	// retour : true si le robot est connecté, false sinon
	// Entrée: un robot
	//********************************************************
	bool estConnecte(void);

	

	//********************************************************
	// méthode: avancer
	// rôle: avance le robot 
	// Entrée: un robot
	//********************************************************
	void avancer();

	//********************************************************
	// méthode: reculer
	// rôle: reculer le robot 
	// Entrée: un robot
	//********************************************************
	void reculer();

	//********************************************************
	// méthode: tournerG
	// rôle: fait tourner le robot vers la gauche
	// Entrée: un robot
	//********************************************************
	void tournerG();

	//********************************************************
	// méthode: tournerD
	// rôle: fait tourner le robot vers la droite
	// Entrée: un robot
	//********************************************************
	void tournerD();

	//********************************************************
	// méthode: avancer
	// rôle: déplace le robot sur une distance
	// paramètres d'entrée:
	//	distance : distance à parcourir
	//  vt : vitesse de translation
	// Entrée: un robot
	//********************************************************
	 void avancer(float distance, int vT =100);


	//********************************************************
	// méthode: reculer
	// rôle: fait reculer le robot sur une distance
	// paramètres d'entrée:
	//	distance : distance à parcourir
	//  vt : vitesse de translation
	 // Entrée: un robot
	//********************************************************
	 void reculer(float distance, int vT =100);

	//********************************************************
	// méthode: tournerG
	// rôle: fait tourner le robot à gauche d'un angle
	// paramètres d'entrée:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	 // Entrée: un robot
	//********************************************************
	 void tournerG (float angle, int vA =45);

	 //********************************************************
	// méthode: tournerD
	// rôle: fait tourner le robot à droite d'un angle
	// paramètres d'entrée:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	// Entrée: un robot
	//********************************************************
	 void tournerD (float angle, int vA =45);

	//**********************************************************************
	// Fonction : clignoter
	// Rôle : fait clignoter le robot
	// paramètres d'entrée::	nb : nombre de fois où le robot clignote
	// Entrée: un robot
	//**********************************************************************
	void clignoter(int nb);


	
	//**********************************************************************
	// Fonction : sonNom
	// Rôle : renvoie le nom du robot
	// Retour : le nom du robot courant
	// Entrée: un robot
	//**********************************************************************
	string sonNom();
	

	//**********************************************************************
	// Fonction : sonAdrIP
	// Rôle : renvoie l'adresse IP du robot
	// Retour : l'adresseIP du robot courant
	// Entrée: un robot
	//**********************************************************************
	string sonAdrIP();

private :

	bool connexion;		// indique si la connexion au robot s'est faite

	string nom ;		// nom du robot
	string adresseIP;	// adresse de connexion au robot

};
