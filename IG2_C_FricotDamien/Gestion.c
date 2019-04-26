#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"


CodeErreur nouveauShift(Shifts ** pShiftsNouv)
{
	(*pShiftsNouv) = (Shifts*)malloc(sizeof(Shifts));
	if ((*pShiftsNouv) != NULL)
	{
		return PAS_D_ERREUR;
	}
	else {
		return ALLOCATION_MEMOIRE;
	}
}

void ajouterShift(Shifts ** pDebShifts, Shifts  *pShiftsNouv, Shifts * pShiftsSauv,FiOrgShift fiOrgShift)
{
	
	pShiftsNouv->date = fiOrgShift.date;
	pShiftsNouv->heure = fiOrgShift.heure;
	pShiftsNouv->nbDoublette = NULL;
	pShiftsNouv->pInscriptions = NULL;
	pShiftsNouv->pSuiv = NULL;

	if (pShiftsSauv != NULL) {
		
		pShiftsSauv->pSuiv = pShiftsNouv;
		
	}
	else {
		pDebShifts = pShiftsNouv;
		
	}

	  pShiftsSauv = pShiftsNouv;
}

CodeErreur afficherShiftsIncomplets(Shifts **pDebShift)
{
	Shifts *pShiftLu = pDebShift;
	CodeErreur codeErreur = SHIFTS_COMPLETS;


	while (pShiftLu != NULL)
	{
		if (pShiftLu->nbDoublette < NB_PISTE_MAX)
		{
			printf("Shift prevu le %d a %d heure, reste %d place(s) disponible(s) \n", pShiftLu->date, pShiftLu->heure, (NB_PISTE_MAX - pShiftLu->nbDoublette));
			codeErreur = PAS_D_ERREUR;
		}

		
		pShiftLu = pShiftLu->pSuiv;
	}

	return codeErreur;
}


CodeErreur nouvelleDoublette(Shifts ** pNouvDoublette)
{
	(*pNouvDoublette) = (Doublette*)malloc(sizeof(Doublette));
	if ((*pNouvDoublette) != NULL)
	{
		return PAS_D_ERREUR;
	}
	else {
		return ALLOCATION_MEMOIRE;
	}
}

_Bool shiftTrouve(Shifts **pDebShift, Shifts *pShift, int date, int heure)
{
	pShift = pDebShift;
	while (pShift != NULL && pShift->heure != heure && pShift->date != date)
	{
		pShift = pShift->pSuiv;
	}

	if (pShift != NULL)
	{
		return true;
	}
	else return false;
}

_Bool membreTrouve(Membres membres[NB_MATRICULE_MAX],int nbMembres, int matricule)
{
	
	while (pShift != NULL && pShift->heure != heure && pShift->date != date)
	{
		pShift = pShift->pSuiv;
	}

	if (pShift != NULL)
	{
		return true;
	}
	else return false;
}

/* En test
CodeErreur nouveauMembre(Membres **pMembre)
{
	(*pMembre) = (Membres*)malloc(sizeof(Membres));
	if ((*pMembre) != NULL)
	{
		return PAS_D_ERREUR;
	}
	else {
		return ALLOCATION_MEMOIRE;
	}
	
}
*/
