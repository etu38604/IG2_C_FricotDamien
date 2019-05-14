#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Constantes.h"
#include "Fichier.h"





CodeErreur initialiserShifts(Shifts ** pDebShifts)
{
	CodeErreur codeErreur = PAS_D_ERREUR;
	bool premierefois = true;
	codeErreur = detecterFichierShifts(&premierefois);
	if (codeErreur == PAS_D_ERREUR)
	{
		if (premierefois)
		{
			codeErreur = chargerDatesOrgShifts(&pDebShifts);
		}
		else
		{
			// charger inscription
			
		}
	}
	return codeErreur;
}

CodeErreur detecterFichierShifts(bool *premierefois)
{
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
	FILE *pDebOrgShifts;
	fopen_s(&pDebOrgShifts, DATESORGSHIFT, "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	(*pDebShifts) = NULL;
	Shifts *pShiftsSauv = NULL;
	Shifts *pShiftsNouv = NULL;
	FiOrgShift fiOrgShift;

	fread_s(&fiOrgShift, sizeof(FiOrgShift), sizeof(FiOrgShift), 1, pDebOrgShifts); 
	
	
	while ((!feof(pDebOrgShifts)) && (codeErreur == PAS_D_ERREUR))
	{
		codeErreur = nouveauShift(&pShiftsNouv);
		if (codeErreur == PAS_D_ERREUR)
		{
			
			// ajouter shift
			ajouterShift(pDebShifts, pShiftsNouv, pShiftsSauv,fiOrgShift);
			
			// shift Lu
			fread_s(&fiOrgShift, sizeof(FiOrgShift), sizeof(FiOrgShift), 1, pDebOrgShifts); 
			

		}
	}
	
	free(pShiftsNouv);
	fclose(pDebOrgShifts);
	return codeErreur;
}

CodeErreur chargementMembres(Membres membres[NB_MATRICULE_MAX],int nbMembre) // Question à poser taille tableau
{
	
	FILE *pDebFiMembres;
	fopen_s(&pDebFiMembres, MEMBRE, "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	nbMembre = 0;
	Membres fiMembres;

	fread_s(&fiMembres, sizeof(Membres), sizeof(Membres), 1, pDebFiMembres);
	
	while ((!feof(pDebFiMembres)) && (codeErreur == PAS_D_ERREUR) && (nbMembre < NB_MATRICULE_MAX))
	{
		
			// A optimiser ou  changer pour tableau dynamique
			membres[nbMembre] = fiMembres;

			/*
			membres[nbMembre]->matricule = fiMembres.matricule;
			strcpy_s(membres[nbMembre]->nom, NB_CHAR_NOM_MAX, fiMembres.nom);
			strcpy_s(membres[nbMembre]->prenom, NB_CHAR_PRENOM_MAX, fiMembres.prenom);
			membres[nbMembre]->moyPrec = fiMembres.moyPrec;
			*/

			// shift Lu
			fread_s(&fiMembres, sizeof(Membres), sizeof(Membres), 1, pDebFiMembres);
			//printf("ficher : matricule -> %d  nom -> %d prenom -> %d moyenne -> %d  \n \n", fiMembres.matricule, fiMembres.nom, fiMembres.prenom, fiMembres.moyPrec);
			
		
		nbMembre++;
	}
	fclose(pDebFiMembres);
	return codeErreur;
}



