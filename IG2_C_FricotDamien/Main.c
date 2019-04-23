#include "Fichier.h"
#include "Gestion.h"
#include"Constantes.h"
#include"Lexique.h"


void main(void)
{
	printf("Depart \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	Shifts *pDebShifts = NULL;
	Membres *pDebMembres = NULL;
	codeErreur = initialiserShifts(&pDebShifts);
	//codeErreur = chargerMembres(&pDebMembres);
	printf("\n code de l'erreur = %d \n", codeErreur);
	printf("\ n Fin INIT \n");
	
	

}