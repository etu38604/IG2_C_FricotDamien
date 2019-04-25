#include "Fichier.h"
#include "Gestion.h"
#include"Constantes.h"
#include"Lexique.h"
#include "Interface.h"


void main(void)
{
	printf("Depart \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	Shifts *pDebShifts = NULL;
	Lexique *pLexique = NULL;
	Membres(*membres[]) = { NULL };
	int nbMembres = 0;
	char langue;
	//langue = langueLue(); 

	codeErreur = chargerLexique(1,&pLexique);
	
	//codeErreur = initialiserShifts(&pDebShifts);

	if (codeErreur != PAS_D_ERREUR)
	{
		// Afficher Message
	}
	else
	{
		//codeErreur = chargementMembres(&membres, &nbMembres);

		if (codeErreur != PAS_D_ERREUR)
		{
			// Afficher message
		}
		else
		{
			// Dialogue
		}
	}

	// Liberer Lexique

	// Liberer Shift

	
	printf("\n code de l'erreur = %d \n", codeErreur);
	printf("\ n Fin INIT \n");
	free(pDebShifts);
	free(membres);
	

}