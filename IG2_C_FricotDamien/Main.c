#include "Fichier.h"
#include "Gestion.h"
#include"Constantes.h"
#include"Lexique.h"


void main(void)
{
	printf("Depart \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	Shifts *pDebShifts = NULL;
	codeErreur = initialiserShifts(&pDebShifts);
	printf("\n code de l'erreur = %d \n", codeErreur);
	Shifts *pSauvShifts;
	pSauvShifts = pDebShifts;
	while (pSauvShifts != NULL)
	{
		printf("\n test \n");
		printf("date = %d   heure = %d  nb doublette = %d \n", pSauvShifts->date, pSauvShifts->heure, pSauvShifts->nbDoublette);
		pSauvShifts = pSauvShifts->pSuiv;
	}
	printf("\ n Fin INIT \n");
	
	

}