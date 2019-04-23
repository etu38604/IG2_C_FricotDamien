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

CodeErreur nouveauMembre(Membres ** pMembreNouv)
{
	(*pMembreNouv) = (Membres*)malloc(sizeof(Membres));
	if ((*pMembreNouv) != NULL)
	{
		return PAS_D_ERREUR;
	}
	else {
		return ALLOCATION_MEMOIRE;
	}
}

void ajouterMembre(Membres ** pDebMembres, Membres  *pMembresNouv, Membres * pMembresSauv, FiMembres fiMembres)
{

	pMembresNouv->matricule = fiMembres.matricule;
	strcpy_s(pMembresNouv->nom, NB_CHAR_NOM_MAX, fiMembres.nom);
	strcpy_s(pMembresNouv->prenom, NB_CHAR_PRENOM_MAX, fiMembres.prenom);
	pMembresNouv->moyPrec = fiMembres.moyPrec;
	pMembresNouv->pSuiv = NULL;

	if (pMembresSauv != NULL) {

		pMembresSauv->pSuiv = pMembresNouv;

	}
	else {
		pDebMembres = pMembresNouv;

	}

	pMembresSauv = pMembresNouv;
}