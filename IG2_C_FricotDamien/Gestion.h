#ifndef GESTION_H

#define GESTION_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"

CodeErreur nouveauShift(Shifts ** pShiftsNouv);
void ajouterShift(Shifts ** pDebShifts, Shifts  *pShiftsNouv, Shifts * pShiftsSauv, FiOrgShift fiOrgShift);
CodeErreur nouveauMembre(Membres ** pMembreNouv);
void ajouterMembre(Membres ** pDebMembres, Membres  *pMembresNouv, Membres * pMembresSauv, FiMembres fiMembres);

#endif