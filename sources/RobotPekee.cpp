//******************************************************** 
// Auteur MP Pinaud
// date : 07/10/2010
// fichier: Robot.cpp
// Enoncé : Code des méthodes de la classe CRobotPekee
//********************************************************
#include <iostream>
using namespace std;
#include <Windows.h>
#include "../include/RobotPekee.h"

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
CRobotPekee::CRobotPekee(string un_nom, string une_adrIP)

{	
	this->nom = un_nom;
	this->adresseIP = une_adrIP;

	char * adrIP = (char *)this->adresseIP.c_str();
	char * n = (char *)this->nom.c_str();

	if (this-> Connect(adrIP,n))
		this->connexion = true;
	else
		this->connexion = false;

	// this->connexion = this-> Connect(adrIP,n);
}

//********************************************************
// méthode: ~CRobot
// rôle: Destructeur de la classe CRobot. Il effectue la 
//			deconnexion au robot réel ou au robot simulé
//********************************************************
CRobotPekee::~CRobotPekee(void)
{
	bool res;
	if (this->connexion == true)
	{
		res = this->Disconnect();
		if (res== true)
			this->connexion = false;
	}
	
}



//********************************************************
// méthode: avancer
// rôle: avance le robot 
// Entrée: un robot
//********************************************************
void CRobotPekee::avancer()
{
	
	this->SetSpeed(100, 0);
	Sleep(100);

}
//********************************************************
// méthode: reculer
// rôle: reculer le robot 
	// Entrée: un robot
//********************************************************
void CRobotPekee::reculer()
{
	this->SetSpeed(-100, 0);
	Sleep(100);
}

//********************************************************
// méthode: tournerG
// rôle: fait tourner le robot vers la gauche
// Entrée: un robot
//********************************************************
void CRobotPekee::tournerG()
{
	this->SetSpeed(0, -45);
	Sleep(100);
}


//********************************************************
// méthode: tournerD
// rôle: fait tourner le robot vers la droite
// Entrée: un robot
//********************************************************
void CRobotPekee::tournerD()
{
	this->SetSpeed(0, 45);
	Sleep(100);
}

	//********************************************************
	// méthode: avancer
	// rôle: déplace le robot sur une distance
	// paramètres d'entrée:
	//	distance : distance à parcourir
	//  vt : vitesse de translation
	// Entrée: un robot
	//********************************************************
void CRobotPekee::avancer(float distance, int vT )

{
	float X, Y;		// position en mètres
	float angle ;	//  angle de rotation compris entre -2PI et 2PI
	bool res;
	// on réinitialise la position 
	res = this->SetPosition(0,0,0);
	Sleep(100);
	X = 0;
	while( abs(X) < distance)
	{
		this->SetSpeed(vT,0);
		Sleep(100);
		bool  res = this->GetPosition (X,Y,angle);
		Sleep(150);
	}
}
	//********************************************************
	// méthode: reculer
	// rôle: fait reculer le robot sur une distance
	// paramètres d'entrée:
	//	distance : distance à parcourir
	//  vt : vitesse de translation
	// Entrée: un robot
	//********************************************************
void CRobotPekee :: reculer(float distance, int vT )
{
	this->avancer(distance, -vT);
}
	//********************************************************
	// méthode: tournerG
	// rôle: fait tourner le robot à gauche d'un angle
	// paramètres d'entrée:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	// Entrée: un robot
	//********************************************************
void CRobotPekee::tournerG (float angle, int vA )
{
	this->tournerD(angle, -vA);
}


	 //********************************************************
	// méthode: tournerD
	// rôle: fait tourner le robot à droite d'un angle
	// paramètres d'entrée:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	// Entrée: un robot
	//********************************************************
void CRobotPekee::tournerD (float angle, int vA )
{
	float X, Y;		// position en mètres
	float teta ;	//  angle de rotation compris entre -2PI et 2PI
	bool res;
	// on réinitialise la position 
	res = this->SetPosition(0,0,0);
	Sleep(100);
	teta = 0;
	while( abs(teta) < angle)
	{
		this->SetSpeed(0,vA);
		Sleep(100);
		bool  res = this->GetPosition (X,Y,teta);
		Sleep(150);
	}
}

//**********************************************************************
// Fonction : clignoter_robot
// Rôle : fait clignoter le robot
// Entrées :	nb : nombre de fois où le robot clignote
// Entrée: un robot
//**********************************************************************
void CRobotPekee::clignoter(int nb)
{
	int i; 
	for (i = 0; i < nb; i++)
	{
		this->LedOn();
		Sleep(200);
		this->LedOff();
		Sleep(200);
	}
}

//********************************************************
// méthode: est_connecte
// rôle: indique si la connexion au robot reel ou simulé 
//       est effective
// retour : true si le robot est connecté, false sinon
// Entrée: un robot
//********************************************************
bool CRobotPekee::estConnecte(void)
{
	return this->connexion;
}

	//**********************************************************************
	// Fonction : sonNom
	// Rôle : renvoie le nom du robot
	// Retour : le nom du robot courant
	// Entrée: un robot
	//**********************************************************************
	string CRobotPekee::sonNom(){
		return this->nom;
	}
	

	//**********************************************************************
	// Fonction : sonAdrIP
	// Rôle : renvoie l'adresse IP du robot
	// Retour : l'adresseIP du robot courant
	// Entrée: un robot
	//**********************************************************************
	string CRobotPekee::sonAdrIP() {
		return this->adresseIP;
	}