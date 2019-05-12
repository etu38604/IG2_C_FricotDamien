#include "Fichier.h"
#include "Gestion.h"
#include"Constantes.h"
#include"Lexique.h"
#include "Interface.h"


void main(void)
{
	printf("Depart \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	Shifts *pDebShifts;
	Message *pLexique;
	Membres membres[NB_MATRICULE_MAX];
	int nbMembres = 0;
	
	int langue = langueLue(); 

	codeErreur = chargerLexique(langue,&pLexique);
	
	if (codeErreur != PAS_D_ERREUR)
	{
		if (codeErreur == ALLOCATION_MEMOIRE)
		{
			printf("Erreur Memoire / Memory Error");

			free(pLexique);
		}
		if (codeErreur == PROBS_OUVERTURE)
		{
			printf("Erreur ouverture fichier / File Opening Error");
		}
	}
	else
	{
		codeErreur = initialiserShifts(&pDebShifts);

		if (codeErreur != PAS_D_ERREUR)
		{
			int numMessage = PREMIER_ERREUR + codeErreur;
			afficherMessage(pLexique, numMessage);
		}
		else
		{
			codeErreur = chargementMembres(&membres, &nbMembres);

			if (codeErreur != PAS_D_ERREUR)
			{
				int numMessage = PREMIER_ERREUR + codeErreur;
				afficherMessage(pLexique, numMessage);
			}
			else
			{
				// Dialogue
				dialogues(pLexique, pDebShifts, &membres, nbMembres);
			}
		}


		if (pLexique != NULL)
		{
			free(pLexique);
		}

		if (pDebShifts != NULL)
		{
			free(pDebShifts);
		}
		printf("\n code de l'erreur = %d \n", codeErreur);
		printf("\ n Fin INIT \n");
		
	}

	
	

}