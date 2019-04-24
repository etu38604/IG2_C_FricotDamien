#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Fichier.h"




CodeErreur initialiserShifts(Shifts ** pDebShifts)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	printf("\n initialiser shifts");
	bool premierefois = true;
	codeErreur = detecterFichierShifts(&premierefois);
	printf("\n code erreur = %d \n", codeErreur);
	if (codeErreur == PAS_D_ERREUR)
	{
		if (premierefois)
		{
			printf("premiere fois");
			codeErreur = chargerDatesOrgShifts(&pDebShifts);

			// charger date Orgs Shifts
		}
		else
		{
			printf("not premiere fois");
			// charger inscription
		}
	}
	return codeErreur;
}

CodeErreur detecterFichierShifts(bool *premierefois)
{
	printf("\n détecter fichier shifts \n");
	CodeErreur codeErreur = PAS_D_ERREUR;
	FILE *fInscriptions;
	fopen_s(&fInscriptions, INSCRIPTION, "rb");

	if (fInscriptions == NULL)
	{
		premierefois = true;
		FILE *fDatesOrgShifts;
		fopen_s(&fDatesOrgShifts, DATESORGSHIFT, "rb");
		if (fDatesOrgShifts == NULL)
		{
			codeErreur = PROBS_OUVERTURE;
		}
		else
		{
			fclose(fDatesOrgShifts);
		}
	}
	else
	{
		premierefois = false;
		fclose(fInscriptions);
	}
	return codeErreur;
}

CodeErreur chargerDatesOrgShifts(Shifts **pDebShifts)
{
	printf("\n charger dates org shifts \n");
	FILE *pDebOrgShifts;
	fopen_s(&pDebOrgShifts, DATESORGSHIFT, "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	(*pDebShifts) = NULL;
	Shifts *pShiftsSauv = NULL;
	Shifts *pShiftsNouv = NULL;
	FiOrgShift fiOrgShift;


	// Problème lors de la lecture du fichier
	fread_s(&fiOrgShift, sizeof(FiOrgShift), sizeof(FiOrgShift), 1, pDebOrgShifts); 
	printf("ficher : date -> %d  heure -> %d  \n \n", fiOrgShift.date, fiOrgShift.heure);
	
	
	while ((!feof(pDebOrgShifts)) && (codeErreur == PAS_D_ERREUR))
	{
		codeErreur = nouveauShift(&pShiftsNouv);
		if (codeErreur == PAS_D_ERREUR)
		{
			
			// ajouter shift
			ajouterShift(pDebShifts, pShiftsNouv, pShiftsSauv,fiOrgShift);
			printf("date = %d   heure = %d  nb doublette = %d \n \n ", pShiftsNouv->date, pShiftsNouv->heure, pShiftsNouv->nbDoublette);
			
			// shift Lu
			fread_s(&fiOrgShift, sizeof(FiOrgShift), sizeof(FiOrgShift), 1, pDebOrgShifts); 
			printf("ficher : date -> %d  heure -> %d  \n \n", fiOrgShift.date, fiOrgShift.heure);

		}
	}
	
	fclose(pDebOrgShifts);
	return codeErreur;
}

CodeErreur chargementMembres(Membres *(*membres)[1],int nbMembre)
{
	printf("\n charger membres \n");
	
	FILE *pDebFiMembres;
	fopen_s(&pDebFiMembres, MEMBRE, "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	FiMembres fiMembres;
	nbMembre = 0;


	fread_s(&fiMembres, sizeof(FiMembres), sizeof(FiMembres), 1, pDebFiMembres);
	printf("ficher : matricule -> %d  nom -> %d prenom -> %d moyenne -> %d  \n \n", fiMembres.matricule, fiMembres.nom, fiMembres.prenom, fiMembres.moyPrec);
	
	while ((!feof(pDebFiMembres)) && (codeErreur == PAS_D_ERREUR))
	{
		codeErreur = NouveauMembre(&membres);

		if (codeErreur == PAS_D_ERREUR)
		{
			
			membres[nbMembre][0]->matricule = fiMembres.matricule;
			strcpy_s(membres[nbMembre][0]->nom, NB_CHAR_NOM_MAX, fiMembres.nom);
			strcpy_s(membres[nbMembre][0]->prenom, NB_CHAR_PRENOM_MAX, fiMembres.prenom);
			membres[nbMembre][0]->moyPrec = fiMembres.moyPrec;

			// shift Lu
			fread_s(&fiMembres, sizeof(FiMembres), sizeof(FiMembres), 1, pDebFiMembres);
			//printf("ficher : matricule -> %d  nom -> %d prenom -> %d moyenne -> %d  \n \n", fiMembres.matricule, fiMembres.nom, fiMembres.prenom, fiMembres.moyPrec);
			
		}
		nbMembre++;
	}

	printf(" matricule -> %d  nom -> %d prenom -> %d moyenne -> %d  \n \n", membres[1][0]->matricule, membres[1][0]->nom, membres[1][0]->prenom, membres[1][0]->moyPrec);

	fclose(pDebFiMembres);
	return codeErreur;
}



