#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Fichier.h"




CodeErreur initialiserShifts(Shifts ** pDebShifts)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	bool premierefois = true;
	codeErreur = detecterFichierShifts(&premierefois);
	if (codeErreur = PAS_D_ERREUR)
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
}

CodeErreur detecterFichierShifts(bool *premierefois)
{
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
}

CodeErreur chargerDatesOrgShifts(Shifts **pDebShifts)
{
	FILE *pDebOrgShifts;
	fopen_s(&pDebOrgShifts, DATESORGSHIFT, "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	(*pDebShifts) = NULL;
	Shifts *pShiftsSauv = NULL;
	Shifts *pShiftsNouv = NULL;
	FiOrgShift fiOrgShift;

	// Shift lu	
	fread_s(&fiOrgShift, sizeof(int), sizeof(int), 1, pDebOrgShifts); // ou alors fiOrgShift.date

	int nbDoublette = 0;
	
	while ((!feof(pDebOrgShifts)) && (codeErreur = PAS_D_ERREUR))
	{
		codeErreur = nouveauShift(&pShiftsNouv);
		if (codeErreur = PAS_D_ERREUR)
		{
			nbDoublette++;
			// ajouter shift
			ajouterShift(&pDebShifts, &pShiftsNouv, &pShiftsSauv,fiOrgShift,nbDoublette);
			
			// shift Lu
			fread_s(&fiOrgShift, sizeof(int), sizeof(int), 1, pDebOrgShifts);
		}
	}
	
	fclose(pDebOrgShifts);
}



