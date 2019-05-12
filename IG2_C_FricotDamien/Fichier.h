#ifndef FICHIER_H
#define FICHIER_H

#define INSCRIPTION "inscriptions.dat"
#define DATESORGSHIFT "DatesOrgShifts.dat"
#define MEMBRE "MembresFSBB.dat"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Gestion.h"

CodeErreur initialiserShifts(Shifts ** pDebShifts);
CodeErreur detecterFichierShifts(bool *premierefois);
CodeErreur chargerDatesOrgShifts(Shifts **pDebShifts);
CodeErreur chargementMembres(Membres membres[NB_MATRICULE_MAX], int nbMembre);


#endif // !FICHIER_H