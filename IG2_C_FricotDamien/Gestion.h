#pragma once

#include "Constantes.h"

CodeErreur nouveauShift(Shifts ** pShiftsNouv);
void ajouterShift(Shifts ** pDebShifts, Shifts  *pShiftsNouv, Shifts * pShiftsSauv, FiOrgShift fiOrgShift, int nbDoublette);