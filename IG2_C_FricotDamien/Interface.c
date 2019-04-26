
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Lexique.h"
#include "Gestion.h"


int langueLue() // A optimiser et gestion cas d'erreur
{
	char l;
	bool selection = false;

	while (!selection)
	{
		printf_s(" f : French \n");
		printf_s(" e : English \n");
		scanf_s("%c",&l, 1);

		if ((l == 'e') || (l == 'f'))
		{
			selection = true;

			if (l == 'e')
			{
				return 2;
			}

			return 1;
		}
		else
		{
			printf_s("selection not correct \n Please select the right number \n");

		}
	}

}

void afficherMessage(Message *pLexique,int numMessage)
{
	Message *ptr = NULL;
	ptr = pLexique;
	while (ptr != NULL && ptr->num != numMessage)
	{
		ptr = ptr->pSuiv;
	}

	if (ptr != NULL)
	{
		printf("%s", ptr->texte);
	}
	else
	{
		printf("Message n'existe pas"); // A modifier
	}

	free(ptr);
}

int afficherMenu(Message *pLexique, int numMenu)
{
	int numMessage = numMenu;
	Message *pMessage = NULL;

	while (pMessage != NULL && pMessage->num != numMessage) // Message trouvé
	{
		pMessage = pMessage->pSuiv;
	}

	if (pMessage != NULL)
	{
		printf("%s", pMessage->texte); // Revoir gestion cas d'erreur
	}

	int tailleMenu = nbChoixMenu(pMessage,&numMenu);
	pMessage = pMessage->pSuiv;
	int nbChoix = 1;

	while (pMessage != NULL && pMessage->num <= numMenu + tailleMenu)
	{
		printf("%d . %s", nbChoix, pMessage->texte);
		nbChoix++;
		pMessage = pMessage->pSuiv;
	}

	int maxChoix = nbChoix - 1;
}

ChoixMenu choixObtenu(Message *pLexique, int numMessage)
{
	bool choixValide = false;
	NumMessage numMenu;
	do
	{
	numMenu = MENU_PRINCIPAL;
	int maxChoix = afficherMenu(pLexique, numMenu);
	numMessage = OBT_CHOIX;
	afficherMessage(pLexique, numMessage);
	int choix = 0 ;
	scanf_s('%d', choix);
	choixValide = choix >= 1 && choix <= maxChoix;
	if (! choixValide)
		{
		CodeErreur codeErreur = MAUVAIS_CHOIX;
		numMessage = PREMIER_ERREUR + numMessage;
		afficherMessage(pLexique, numMessage);
		}

	} while (!choixValide);
}

void dialogues(Message *pLexique,Shifts pDebShifts,Membres membres, int nbMembres)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	NumMessage numMessage = MENU_PRINCIPAL;
	ChoixMenu choix = choixObtenu(pLexique, numMessage);

	while (choix != QUITTER)
	{
		
		switch (choix)
		{
			case  AJOUTER_INSCRIPTION:

				// Ajouter inscription
				
				break;

		}
			
	}
	
}

CodeErreur ajouterInscription(Shifts ** pDebShifts)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	codeErreur = afficherShiftsIncomplets(pDebShifts);
	
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
					return codeErreur = MEMBRE_DEJA_INSCRIT;
				}
			}
			else
			{
				return codeErreur = MEMBRE_DEJA_INSCRIT;
			}
		}
	}
	return codeErreur;
}


