#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Lexique.h"





CodeErreur nouveauLexique(Message ** pLexiqueNouv)
{
	(*pLexiqueNouv) = (Message*)malloc(sizeof(Message));
	if ((*pLexiqueNouv) != NULL)
	{
		return PAS_D_ERREUR;
	}
	else {
		return ALLOCATION_MEMOIRE;
	}
}

void ajouterLexique(Message ** pLexique, Message  *pLexiqueNouv, Message * pLexiqueSauv, FiLexique fiLexique)
{

	pLexiqueNouv->num = fiLexique.code;
	strcpy_s(pLexiqueNouv->texte, NB_CHAR_MESSAGE_MAX, fiLexique.message);
	pLexiqueNouv->pSuiv = NULL;

	if (pLexiqueSauv != NULL) {

		pLexiqueSauv->pSuiv = pLexiqueNouv;

	}
	else {
		pLexique = pLexiqueNouv;

	}

	pLexiqueSauv = pLexiqueNouv;
	printf("LC Lexique  code = %u \n message = %s", pLexiqueSauv->num, pLexiqueSauv->texte);
}



CodeErreur chargerLexique(Langue choixLangue,Message **pLexique)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	printf("\n charger lexique");
	FILE *pDebLexique;

	if (choixLangue = 1)
	{
		fopen_s(&pDebLexique, FRANCAIS, "r");
	}
	else
	{
		fopen_s(&pDebLexique, ENGLISH, "r");
	}


	
	(*pLexique) = NULL;

	Message *pLexiqueSauv = NULL;
	Message *pLexiqueNouv = NULL;
	FiLexique fiLexique;


	fgets(&fiLexique.code, 5, pDebLexique);
	fgets(&fiLexique.message, 1000, pDebLexique);
	printf("1 Fichier Lexique : code = %u \n message = %s", fiLexique.code, fiLexique.message);


	while ((!feof(pDebLexique)) && (codeErreur == PAS_D_ERREUR))
	{
		codeErreur = nouveauLexique(&pLexiqueNouv);
		printf("nouveau lexique");
		if (codeErreur == PAS_D_ERREUR)
		{

			// ajouter Lexique
			ajouterLexique(pLexique, pLexiqueNouv, pLexiqueSauv, fiLexique);
			printf("ajouter lexique");

			// Lexique Lu
			fgets(&fiLexique.code, 5, pDebLexique);
			fgets(&fiLexique.message, 1000, pDebLexique);

		}
	}

	
	fclose(pDebLexique);
	return codeErreur;


}