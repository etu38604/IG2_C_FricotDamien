#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Lexique.h"





CodeErreur nouveauLexique(Lexique ** pLexiqueNouv)
{
	(*pLexiqueNouv) = (Lexique*)malloc(sizeof(Lexique));
	if ((*pLexiqueNouv) != NULL)
	{
		return PAS_D_ERREUR;
	}
	else {
		return ALLOCATION_MEMOIRE;
	}
}

void ajouterLexique(Lexique ** pLexique, Lexique  *pLexiqueNouv, Lexique * pLexiqueSauv, FiLexique fiLexique)
{

	pLexiqueNouv->code = fiLexique.code;
	strcpy_s(pLexiqueNouv->message, NB_CHAR_MESSAGE_MAX, fiLexique.message);
	pLexiqueNouv->pSuiv = NULL;

	if (pLexiqueSauv != NULL) {

		pLexiqueSauv->pSuiv = pLexiqueNouv;

	}
	else {
		pLexique = pLexiqueNouv;

	}

	pLexiqueSauv = pLexiqueNouv;
	printf("LC Lexique  code = %u \n message = %s", pLexiqueSauv->code, pLexiqueSauv->message);
}

CodeErreur nouveauShift(Shifts ** pShiftsNouv)
{
	(*pShiftsNouv) = (Shifts*)malloc(sizeof(Shifts));
	if ((*pShiftsNouv) != NULL)
	{
		return PAS_D_ERREUR;
	}
	else {
		return ALLOCATION_MEMOIRE;
	}
}

CodeErreur chargerLexique(Langue choixLangue,Lexique **pLexique)
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

	Lexique *pLexiqueSauv = NULL;
	Lexique *pLexiqueNouv = NULL;
	FiLexique fiLexique;


	// Problème lors de la lecture du fichier
	//fread_s(&fiLexique, sizeof(FiLexique), sizeof(FiLexique), 1, pDebLexique);
	fscanf_s(pDebLexique, "%u %s", &(fiLexique.code), &(fiLexique.message));
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

			// shift Lu
			//fread_s(&fiLexique, sizeof(FiLexique), sizeof(FiLexique), 1, pDebLexique);
			fscanf_s(pDebLexique, "%u %s", &fiLexique.code, &fiLexique.message);

			printf("2 Fichier Lexique : code = %u \n message = %s", fiLexique.code, fiLexique.message);

		}
	}

	//free(pLexiqueNouv);
	//free(pLexiqueSauv);
	fclose(pDebLexique);
	return codeErreur;


}