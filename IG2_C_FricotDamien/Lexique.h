#ifndef LEXIQUE_H
#define LEXIQUE_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <errno.h>
	#include "Constantes.h"

	#define FRANCAIS "Francais.txt"
	#define ENGLISH "English.txt"

	typedef enum langue Langue;
	enum langue { fr = 1, en } lng;

	typedef enum numMessage NumMessage;
	enum numMessage {
		MENU_PRINCIPAL = 1001,
		OBT_DATE = 2001,
		OBT_HEURE = 2002,
		OBT_MATRICULE = 2003,
		OBT_RECOMMENCER = 2004,
		OBT_CHOIX = 2005,
		TITRE_PRINCIPAL = 3000,
		TITRE_INSCRIPTION = 3001,
		TITRE_IMPRESSION = 3002,
		TITRE_AJOUT_DOUBLETTE = 3101,
		TITRE_SUPPR_DOUBLETTE = 3102,
		TITRE_LISTE_MEMBRES = 3301,
		SAUVEGARDE = 3401,
		PREMIER_ERREUR = 5000,
	};
	
	typedef struct message Message;
	struct message {
		int num;
		char texte[TTXT];
		Message *pSuiv;
	};

	CodeErreur chargerLexique(Langue choixLangue, Message ** pPLexique);
	Message * messageTrouvé(Message * pLexique, int numMessage);
	int nbChoixMenu(Message * pMenu, int debMenu);
	void libérerLexique(Message * pLexique);
	
#endif

