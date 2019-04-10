
#include <stdio.h>
#include <stdlib.h>
#include "Constantes.h"




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
