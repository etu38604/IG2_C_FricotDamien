#include "Fichier.h"
#include "Gestion.h"
#include"Constantes.h"
#include"Lexique.h"


void main(void)
{
	printf("Depart \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	Shifts *pDebShifts = NULL;
	Membres(*membres)[1] = NULL;
	int nbMembres = 0;
	codeErreur = initialiserShifts(&pDebShifts);
	//codeErreur = chargementMembres(&membres[4],&nbMembres);
	printf("\n code de l'erreur = %d \n", codeErreur);
	printf("\ n Fin INIT \n");
	
	

}