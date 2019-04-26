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

_Bool membreTrouve(Membres membres[NB_MATRICULE_MAX],int nbMembres, int matricule, int indMembre)
{
	while ( indMembre < NB_MATRICULE_MAX && membres[indMembre].matricule != matricule)
	{
		indMembre++;
	}

	if (indMembre > NB_MATRICULE_MAX)
	{
		return false;
	}
	else return true;
}

_Bool membreDejaInscrit(Shifts ** pDebShifts, Membres membre)
{
	Shifts *pShiftLu = NULL;
	pShiftLu = pDebShifts;

	while (pShiftLu != NULL && pShiftLu->pInscriptions->matricule1 != membre.matricule)
	{
		pShiftLu = pShiftLu->pSuiv;
	}

	if (pShiftLu == NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int categorie(Membres joueur1, Membres joueur2)
{
	int moy = (joueur1.moyPrec + joueur2.moyPrec) / 2;
	int categ = 0;
	

	if (moy < 159)
	{
		categ = 6;  // A remettre en constante et optimiser
	}
	
	if (160 < moy < 169)
	{
		categ = 5;
	}

	if (170 < moy < 179)
	{
		categ = 4;
	}

	if (180 < moy < 189)
	{
		categ = 3;
	}

	if (190 < moy < 199)
	{
		categ = 2;
	}

	if (moy > 200)
	{
		categ = 1;
	}
	
	return categ;
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
