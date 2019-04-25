#ifndef CONSTANTES_H
#define CONSTANTES_H
	#define FIDATESORGSHIFTS "DatesOrgShifts.dat"
	#define FIMEMBRESFSBB "MembresFSBB.dat"
	#define FIINSCRIPTIONS "Inscriptions.dat"
	
	#define TTXT		150

	#define PAUSE getchar()
	#define CLEAR system("cls")
	#define NB_MATRICULE_MAX 999999
	#define NB_CHAR_MESSAGE_MAX 250
	#define NB_CHAR_NOM_MAX 80
	#define NB_CHAR_PRENOM_MAX 30

	typedef enum codeErreur CodeErreur;
	enum codeErreur {
		PAS_D_ERREUR,
		//Erreurs logiques...
		MAUVAIS_CHOIX,
		MEMBRE_INCONNU,
		MEMBRE_DEJA_INSCRIT,
		PLUS_DE_PLACE_SHIFTS,
		PAS_DE_SHIFTS,
		SHIFT_INCONNU,
		PAS_UNE_DOUBLETTE,
		PAS_DE_DOUBLETTE,
		FICHIER_VIDE,
		OP_ANNULE,
		DOUBLETTE_NON_CONFORME,
		SHIFTS_COMPLETS,
		//Erreurs système...
		ERREUR_SYSTEME = 100,
		ALLOCATION_MEMOIRE,
		PROBS_OUVERTURE
	};


	typedef enum choixMenu ChoixMenu;
	enum choixMenu {
		CHOIX_MIN,
		AJOUTER_INSCRIPTION = 1,
		SUPPRIMER_INSCRIPTION,
		AFFICHER_INSCRIPTIONS,
		QUITTER
	};

	typedef struct inscriptions Inscriptions;
	struct inscription
	{
		int matricule1;
		int matricule2;
		int categorie;
		Inscriptions *pSuiv;
	};

	typedef struct lexique Lexique;
	struct lexique
	{
		int code;
		char message[NB_CHAR_MESSAGE_MAX];
		Lexique *pSuiv;
	};

	typedef struct fiLexique FiLexique;
	struct fiLexique
	{
		int code;
		char message[NB_CHAR_MESSAGE_MAX];
	};

	typedef struct shifts Shifts;
	struct shifts
	{
		int date;
		int heure;
		int nbDoublette;
		Inscriptions *pInscriptions;
		Shifts *pSuiv;

	};


	typedef struct fiOrgShift FiOrgShift;
	struct fiOrgShift
	{
		int date;
		int heure;
	};

	typedef struct membres Membres;
	struct membres
	{
		int matricule;
		char nom[NB_CHAR_NOM_MAX];
		char prenom[NB_CHAR_PRENOM_MAX];
		int moyPrec;
		
	};

	typedef struct fiMembres FiMembres;
	struct fiMembres
	{
		int matricule;
		char nom[NB_CHAR_NOM_MAX];
		char prenom[NB_CHAR_PRENOM_MAX];
		int moyPrec;
	};

#endif

