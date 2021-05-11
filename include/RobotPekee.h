//******************************************************** 
// Auteur MP Pinaud
// date : 29/09/2010
// fichier: Robot.h
// Interface de la classe CRobotPekee 
// Enonc� : Robot Pekee pilotable � distance
//********************************************************
#pragma once
#include <string>
using namespace std;
#include "libRobotPekee.h"



class CRobotPekee : protected WRobotPekee
{

public:
	//********************************************************
	// m�thode: CRobotPekee
	// r�le: Constructeur de la classe CRobot. Il effectue la 
	//			connexion au robot r�el ou au robot simul�
	// param�tres d'entr�e:
	//  adrIP : adresse  pour se connecter au robot r�el 
	//			ou simul� (dans ce cas vaut localhost)
	//  n    : nom du robot
	// Sortie: un robot
	//********************************************************
	CRobotPekee(string un_nom , string une_adrIP );

	//********************************************************
	// m�thode: ~CRobotPekee
	// r�le: Destructeur de la classe CRobotPekee. Il effectue la 
	//			deconnexion au robot r�el ou au robot simul�
	//********************************************************
	~CRobotPekee(void);
	
	

	//********************************************************
	// m�thode: est_connecte
	// r�le: indique si la connexion au robot reel ou simul� 
	//       est effective
	// retour : true si le robot est connect�, false sinon
	// Entr�e: un robot
	//********************************************************
	bool estConnecte(void);

	

	//********************************************************
	// m�thode: avancer
	// r�le: avance le robot 
	// Entr�e: un robot
	//********************************************************
	void avancer();

	//********************************************************
	// m�thode: reculer
	// r�le: reculer le robot 
	// Entr�e: un robot
	//********************************************************
	void reculer();

	//********************************************************
	// m�thode: tournerG
	// r�le: fait tourner le robot vers la gauche
	// Entr�e: un robot
	//********************************************************
	void tournerG();

	//********************************************************
	// m�thode: tournerD
	// r�le: fait tourner le robot vers la droite
	// Entr�e: un robot
	//********************************************************
	void tournerD();

	//********************************************************
	// m�thode: avancer
	// r�le: d�place le robot sur une distance
	// param�tres d'entr�e:
	//	distance : distance � parcourir
	//  vt : vitesse de translation
	// Entr�e: un robot
	//********************************************************
	 void avancer(float distance, int vT =100);


	//********************************************************
	// m�thode: reculer
	// r�le: fait reculer le robot sur une distance
	// param�tres d'entr�e:
	//	distance : distance � parcourir
	//  vt : vitesse de translation
	 // Entr�e: un robot
	//********************************************************
	 void reculer(float distance, int vT =100);

	//********************************************************
	// m�thode: tournerG
	// r�le: fait tourner le robot � gauche d'un angle
	// param�tres d'entr�e:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	 // Entr�e: un robot
	//********************************************************
	 void tournerG (float angle, int vA =45);

	 //********************************************************
	// m�thode: tournerD
	// r�le: fait tourner le robot � droite d'un angle
	// param�tres d'entr�e:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	// Entr�e: un robot
	//********************************************************
	 void tournerD (float angle, int vA =45);

	//**********************************************************************
	// Fonction : clignoter
	// R�le : fait clignoter le robot
	// param�tres d'entr�e::	nb : nombre de fois o� le robot clignote
	// Entr�e: un robot
	//**********************************************************************
	void clignoter(int nb);


	
	//**********************************************************************
	// Fonction : sonNom
	// R�le : renvoie le nom du robot
	// Retour : le nom du robot courant
	// Entr�e: un robot
	//**********************************************************************
	string sonNom();
	

	//**********************************************************************
	// Fonction : sonAdrIP
	// R�le : renvoie l'adresse IP du robot
	// Retour : l'adresseIP du robot courant
	// Entr�e: un robot
	//**********************************************************************
	string sonAdrIP();

private :

	bool connexion;		// indique si la connexion au robot s'est faite

	string nom ;		// nom du robot
	string adresseIP;	// adresse de connexion au robot

};
