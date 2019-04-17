#pragma once

#define INSCRIPTION "inscriptions.dat"
#define DATESORGSHIFT "datesOrgShifts.dat"
#include "Constantes.h"
#include "Gestion.h"

CodeErreur initialiserShifts(Shifts ** pDebShifts);
CodeErreur detecterFichierShifts(bool *premierefois);
CodeErreur chargerDatesOrgShifts(Shifts **pDebShifts);
