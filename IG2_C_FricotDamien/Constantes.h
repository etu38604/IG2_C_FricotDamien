#ifndef CONSTANTES_H
#define CONSTANTES_H
	#define FIDATESORGSHIFTS "DatesOrgShifts.dat"
	#define FIMEMBRESFSBB "MembresFSBB.dat"
	#define FIINSCRIPTIONS "Inscriptions.dat"
	
	#define TTXT		150
	
			// à compléter

	#define PAUSE getchar()
	#define CLEAR system("cls")

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
#endif

