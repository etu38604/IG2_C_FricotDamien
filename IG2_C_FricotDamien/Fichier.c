#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"


CodeErreur initialiserShifts(Shifts ** pDebShifts)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	bool premierefois = true;
	codeErreur = detecterFichierShifts(&premierefois);
	if (codeErreur = PAS_D_ERREUR)
	{
		if (premierefois)
		{
			codeErreur = chargerDatesOrgShifts();
			// charger date Orgs Shifts
		}
		else
		{
			// charger inscription
		}
	}
}

CodeErreur detecterFichierShifts(bool *premierefois)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	FILE *fInscriptions;
	fopen_s(&fInscriptions, "inscriptions.dat", "rb");

	if (fInscriptions == NULL)
	{
		premierefois = true;
		FILE *fDatesOrgShifts;
		fopen_s(&fDatesOrgShifts, "datesOrgShifts.dat", "rb");
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
	fopen_s(&pDebOrgShifts, "datesOrgShifts.dat", "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	FILE *pDebShifts = NULL;
	FILE *pShiftsSauv = NULL;
	FiOrgShift fiOrgShifts = shiftsLu();
}

FiOrgShift shiftsLu()
{

}

