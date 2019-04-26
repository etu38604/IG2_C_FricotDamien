
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

Shifts shiftObtenu(Message *pLexique,Shifts *pDebShift)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	int date = 0;
	int heure = 0;
	bool shiftExiste = false;
	Shifts *pShift = NULL;

	do
	{
		afficherMessage(pLexique, OBT_DATE);
		scanf_s("%d", date);

		afficherMessage(pLexique, OBT_HEURE);
		scanf_s("%d", heure);

		shiftExiste = shiftTrouve(pDebShift, &pShift, date, heure);
		if (!shiftExiste)
		{
			codeErreur = SHIFT_INCONNU;
			afficherMessage(pLexique, PREMIER_ERREUR + codeErreur);
		}
	} while (!shiftExiste);
	return *pShift;
}

Membres membreObtenu(Message **pLexique,Shifts **pDebShifts,Membres membres[NB_MATRICULE_MAX],int nbMembres)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	Membres membre;
	int matricule = 0;
	int indMembre = 0;
	bool membreExiste = false;
	do
	{
		// lister Membres
		afficherMessage(pLexique, OBT_MATRICULE);
		scanf_s("%d", matricule);

		membreExiste = membreTrouve(&membres[NB_MATRICULE_MAX], nbMembres, matricule, &indMembre);
		if (!membreExiste)
		{
			codeErreur = MEMBRE_INCONNU;
			afficherMessage(pLexique, PREMIER_ERREUR + codeErreur);
		}
	} while (!membreExiste);
	membre.moyPrec = membres[indMembre].moyPrec;
	membre.matricule = matricule;
	return membre;
}

CodeErreur ajouterInscription(Message ** pLexique,Shifts ** pDebShifts,Membres membres[NB_MATRICULE_MAX],int nbMembres)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	Doublette *pNouvDoublette = NULL;
	bool dejaInscrit = false;
	codeErreur = afficherShiftsIncomplets(pDebShifts);
	
	if (codeErreur != SHIFTS_COMPLETS)
	{
		codeErreur = nouvelleDoublette(&pNouvDoublette);

		if (codeErreur != ALLOCATION_MEMOIRE)
		{
			Shifts pShift = shiftObtenu(pLexique, pDebShifts);
			Membres joueur1 = membreObtenu(pLexique, pDebShifts, &membres[NB_MATRICULE_MAX], nbMembres);
			
			bool dejaInscrit = membreDejaInscrit(pDebShifts, joueur1);

			if (!dejaInscrit)
			{
				Membres joueur2 = membreObtenu(pLexique, pDebShifts, &membres[NB_MATRICULE_MAX], nbMembres);
				dejaInscrit = membreDejaInscrit(pDebShifts, joueur2);

				if (!dejaInscrit)
				{
					// Ajouter doublette shift
					pNouvDoublette->categ = categorie(joueur1, joueur2);
					pNouvDoublette->matricule1 = joueur1.matricule;
					pNouvDoublette->matricule2 = joueur2.matricule;
					pNouvDoublette->moy1 = joueur1.moyPrec;
					pNouvDoublette->moy2 = joueur2.moyPrec;
					
					// maj nbDoublette
					pShift.nbDoublette++;
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


