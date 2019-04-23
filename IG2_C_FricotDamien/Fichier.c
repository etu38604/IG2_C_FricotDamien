#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Fichier.h"




CodeErreur initialiserShifts(Shifts ** pDebShifts)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	printf("\n initialiser shifts");
	bool premierefois = true;
	codeErreur = detecterFichierShifts(&premierefois);
	printf("\n code erreur = %d \n", codeErreur);
	if (codeErreur == PAS_D_ERREUR)
	{
		if (premierefois)
		{
			printf("premiere fois");
			codeErreur = chargerDatesOrgShifts(&pDebShifts);

			// charger date Orgs Shifts
		}
		else
		{
			printf("not premiere fois");
			// charger inscription
		}
	}
	return codeErreur;
}

CodeErreur detecterFichierShifts(bool *premierefois)
{
	printf("\n détecter fichier shifts \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	FILE *fInscriptions;
	fopen_s(&fInscriptions, INSCRIPTION, "rb");

	if (fInscriptions == NULL)
	{
		premierefois = true;
		FILE *fDatesOrgShifts;
		fopen_s(&fDatesOrgShifts, DATESORGSHIFT, "rb");
		if (fDatesOrgShifts == NULL)
		{
			codeErreur = PROBS_OUVERTURE;
		}
		else
		{
			fclose(fDatesOrgShifts);
		}
	}
	else
	{
		premierefois = false;
		fclose(fInscriptions);
	}
	return codeErreur;
}

CodeErreur chargerDatesOrgShifts(Shifts **pDebShifts)
{
	printf("\n charger dates org shifts \n");
	FILE *pDebOrgShifts;
	fopen_s(&pDebOrgShifts, DATESORGSHIFT, "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	(*pDebShifts) = NULL;
	Shifts *pShiftsSauv = NULL;
	Shifts *pShiftsNouv = NULL;
	FiOrgShift fiOrgShift;


	// Problème lors de la lecture du fichier : donnée non cohérente
	fread_s(&fiOrgShift, sizeof(FiOrgShift), sizeof(FiOrgShift), 1, pDebOrgShifts); 
	printf("ficher : date -> %d  heure -> %d  \n \n", fiOrgShift.date, fiOrgShift.heure);
	int nbDoublette = 0;
	
	while ((!feof(pDebOrgShifts)) && (codeErreur == PAS_D_ERREUR))
	{
		codeErreur = nouveauShift(&pShiftsNouv);
		if (codeErreur == PAS_D_ERREUR)
		{
			nbDoublette++;
			// ajouter shift
			ajouterShift(pDebShifts, pShiftsNouv, pShiftsSauv,fiOrgShift,nbDoublette);
			printf("date = %d   heure = %d  nb doublette = %d \n \n ", pShiftsNouv->date, pShiftsNouv->heure, pShiftsNouv->nbDoublette);
			
			// shift Lu
			fread_s(&fiOrgShift, sizeof(FiOrgShift), sizeof(FiOrgShift), 1, pDebOrgShifts); 
			printf("ficher : date -> %d  heure -> %d  \n \n", fiOrgShift.date, fiOrgShift.heure);

		}
	}
	
	fclose(pDebOrgShifts);
	return codeErreur;
}



