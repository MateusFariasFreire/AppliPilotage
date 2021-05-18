//******************************************************** 
// Auteur MP Pinaud
// date : 07/10/2010
// fichier: Robot.cpp
// Enonc� : Code des m�thodes de la classe CRobotPekee
//********************************************************
#include <iostream>
using namespace std;
#include <Windows.h>
#include "../include/RobotPekee.h"

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
// m�thode: ~CRobot
// r�le: Destructeur de la classe CRobot. Il effectue la 
//			deconnexion au robot r�el ou au robot simul�
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
// m�thode: avancer
// r�le: avance le robot 
// Entr�e: un robot
//********************************************************
void CRobotPekee::avancer()
{
	
	this->SetSpeed(100, 0);
	Sleep(100);

}
//********************************************************
// m�thode: reculer
// r�le: reculer le robot 
	// Entr�e: un robot
//********************************************************
void CRobotPekee::reculer()
{
	this->SetSpeed(-100, 0);
	Sleep(100);
}

//********************************************************
// m�thode: tournerG
// r�le: fait tourner le robot vers la gauche
// Entr�e: un robot
//********************************************************
void CRobotPekee::tournerG()
{
	this->SetSpeed(0, -45);
	Sleep(100);
}


//********************************************************
// m�thode: tournerD
// r�le: fait tourner le robot vers la droite
// Entr�e: un robot
//********************************************************
void CRobotPekee::tournerD()
{
	this->SetSpeed(0, 45);
	Sleep(100);
}

	//********************************************************
	// m�thode: avancer
	// r�le: d�place le robot sur une distance
	// param�tres d'entr�e:
	//	distance : distance � parcourir
	//  vt : vitesse de translation
	// Entr�e: un robot
	//********************************************************
void CRobotPekee::avancer(float distance, int vT )

{
	float X, Y;		// position en m�tres
	float angle ;	//  angle de rotation compris entre -2PI et 2PI
	bool res;
	// on r�initialise la position 
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
	// m�thode: reculer
	// r�le: fait reculer le robot sur une distance
	// param�tres d'entr�e:
	//	distance : distance � parcourir
	//  vt : vitesse de translation
	// Entr�e: un robot
	//********************************************************
void CRobotPekee :: reculer(float distance, int vT )
{
	this->avancer(distance, -vT);
}
	//********************************************************
	// m�thode: tournerG
	// r�le: fait tourner le robot � gauche d'un angle
	// param�tres d'entr�e:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	// Entr�e: un robot
	//********************************************************
void CRobotPekee::tournerG (float angle, int vA )
{
	this->tournerD(angle, -vA);
}


	 //********************************************************
	// m�thode: tournerD
	// r�le: fait tourner le robot � droite d'un angle
	// param�tres d'entr�e:
	//	angle : angle de rotation
	//  vA : vitesse de rotation
	// Entr�e: un robot
	//********************************************************
void CRobotPekee::tournerD (float angle, int vA )
{
	float X, Y;		// position en m�tres
	float teta ;	//  angle de rotation compris entre -2PI et 2PI
	bool res;
	// on r�initialise la position 
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
// R�le : fait clignoter le robot
// Entr�es :	nb : nombre de fois o� le robot clignote
// Entr�e: un robot
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
// m�thode: est_connecte
// r�le: indique si la connexion au robot reel ou simul� 
//       est effective
// retour : true si le robot est connect�, false sinon
// Entr�e: un robot
//********************************************************
bool CRobotPekee::estConnecte(void)
{
	return this->connexion;
}

	//**********************************************************************
	// Fonction : sonNom
	// R�le : renvoie le nom du robot
	// Retour : le nom du robot courant
	// Entr�e: un robot
	//**********************************************************************
	string CRobotPekee::sonNom(){
		return this->nom;
	}
	

	//**********************************************************************
	// Fonction : sonAdrIP
	// R�le : renvoie l'adresse IP du robot
	// Retour : l'adresseIP du robot courant
	// Entr�e: un robot
	//**********************************************************************
	string CRobotPekee::sonAdrIP() {
		return this->adresseIP;
	}