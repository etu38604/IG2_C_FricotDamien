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
	
	fclose(pDebOrgShifts);
	return codeErreur;
}

CodeErreur chargementMembres(Membres (*membres[]),int nbMembre)
{
	printf("\n charger membres \n");
	
	FILE *pDebFiMembres;
	fopen_s(&pDebFiMembres, MEMBRE, "rb");
	CodeErreur codeErreur = PAS_D_ERREUR;
	nbMembre = 0;
	Membres *pMembre = NULL;
	Membres fiMembres;

	fread_s(&fiMembres, sizeof(Membres), sizeof(Membres), 1, pDebFiMembres);
	printf("ficher : matricule -> %u  nom -> %s prenom -> %s moyenne -> %u  \n \n", fiMembres.matricule, fiMembres.nom, fiMembres.prenom, fiMembres.moyPrec);
	
	while ((!feof(pDebFiMembres)) && (codeErreur == PAS_D_ERREUR))
	{
		codeErreur = nouveauMembre(&pMembre);
		printf("nouveau membre code erreur = %d", codeErreur);

		if (codeErreur == PAS_D_ERREUR)
		{
			pMembre->matricule = fiMembres.matricule;
			strcpy_s(pMembre->nom, NB_CHAR_NOM_MAX, fiMembres.nom);
			strcpy_s(pMembre->prenom, NB_CHAR_PRENOM_MAX, fiMembres.prenom);
			pMembre->moyPrec = fiMembres.moyPrec;
			membres[nbMembre] = pMembre;
			
			// shift Lu
			fread_s(&fiMembres, sizeof(Membres), sizeof(Membres), 1, pDebFiMembres);
			//printf("ficher : matricule -> %d  nom -> %d prenom -> %d moyenne -> %d  \n \n", fiMembres.matricule, fiMembres.nom, fiMembres.prenom, fiMembres.moyPrec);
			
		}
		nbMembre++;
	}
	printf("code erreur de la sortie de boucle chrgerMembre %d", codeErreur);
	printf(" matricule -> %d  nom -> %s prenom -> %s moyenne -> %d  \n \n", membres[10]->matricule, membres[10]->nom, membres[10]->prenom, membres[10]->moyPrec);

	fclose(pDebFiMembres);
	return codeErreur;
}



