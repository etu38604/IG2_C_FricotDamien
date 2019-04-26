#ifndef GESTION_H

#define GESTION_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"

CodeErreur nouveauShift(Shifts ** pShiftsNouv);
void ajouterShift(Shifts ** pDebShifts, Shifts  *pShiftsNouv, Shifts * pShiftsSauv, FiOrgShift fiOrgShift);
CodeErreur afficherShiftsIncomplets(Shifts **pDebShift);
CodeErreur nouvelleDoublette(Shifts ** pNouvDoublette);
_Bool shiftTrouve(Shifts **pDebShift, Shifts *pShift, int date, int heure);
_Bool membreTrouve(Membres membres[NB_MATRICULE_MAX], int nbMembres, int matricule, int indMembre);
_Bool membreDejaInscrit(Shifts ** pDebShifts, Membres membre);
int categorie(Membres joueur1, Membres joueur2);

#endif