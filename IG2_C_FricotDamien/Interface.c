
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"


int langueLue()
{
	int langue = 0;
	bool selection = false;

	while (!selection)
	{
		printf_s(" 1 : French \n");
		printf_s(" 2 : English \n");
		scanf_s("%u", langue);

		if ((langue == 1) || (langue == 2))
		{
			selection = true;
		}
		else
		{
			printf_s("selection not correct \n Please select the right number \n");

		}
	}

	return langue;
}
/*


CodeErreur ajouterInscription(Shifts ** pDebShifts)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	// Afficher Shifts incomplets

	if (codeErreur != SHIFTS_COMPLETS)
	{
		// Nouvelle doublette

		if (codeErreur != ALLOCATION_MEMOIRE)
		{
			// Shift Obtenu
			// Membre obtenu (Matricule 1 , moy 1)
			// Membre déjà inscrit

			if (not (MEMBRE_DEJA_INSCRIT))
			{
				// Membre Obtenu (matricule 2, moy 2)
				// Membre déjà inscrit

				if (not (MEMBRE_DEJA_INSCRIT))
				{
					// categorie (calcul de la categorie)
					// ajouter doublette shift
					// maj nbDoublette
				}
				else
				{
					codeErreur = MEMBRE_DEJA_INSCRIT;
				}
			}
			else
			{
				codeErreur = MEMBRE_DEJA_INSCRIT;
			}
		}
	}
}


*/