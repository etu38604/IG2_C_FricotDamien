#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"




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
