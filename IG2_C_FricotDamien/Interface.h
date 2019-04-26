#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int langueLue();
void afficherMessage(Message *pLexique, int numMessage);
int afficherMenu(Message *pLexique, int numMenu);
ChoixMenu choixObtenu(Message *pLexique, int numMessage);
void dialogues(Message *pLexique, Shifts pDebShifts, Membres membres, int nbMembres);
CodeErreur ajouterInscription(Message ** pLexique, Shifts ** pDebShifts, Membres membres[NB_MATRICULE_MAX], int nbMembres);
Membres membreObtenu(Message **pLexique, Shifts **pDebShifts, Membres membres[NB_MATRICULE_MAX], int nbMembres);
