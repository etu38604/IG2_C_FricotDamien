#include "Fichier.h"
#include "Gestion.h"
#include"Constantes.h"
#include"Lexique.h"
#include "Interface.h"


void main(void)
{
	printf("Depart \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	//Shifts *pDebShifts = NULL;
	//Membres(*membres[]) = { NULL };
	int nbMembres = 0;
	int langue;
	langue = langueLue();
	printf_s("%u \n", langue);
	//codeErreur = initialiserShifts(&pDebShifts);
	//codeErreur = chargementMembres(&membres,&nbMembres);
	printf("\n code de l'erreur = %d \n", codeErreur);
	printf("\ n Fin INIT \n");
	//free(pDebShifts);
	//free(membres);
	

}