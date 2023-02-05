/**
 * @file Dico.h
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 24/12/2022
 * Composant du dictionnaire
 */

#ifndef _DICO_
#define _DICO_
#include <cstring> 
#pragma warning(disable: 4996)

typedef unsigned int uint;

struct Dictionnaire {
    char** contenu; //un tableau de mots appel� dictionnaire contenant l'ensemble des mots d'un dictionnaire
    uint capacite; // capacit� du dictionnaire (souvent diff�rente du nombre de mots r�el)
    double pasExtension; //pas d'extension de la capacit� du dictionnaire
    uint nombreMots; // nombre r�el de mots dans le dictionnaire
};


/**@brief initialise un tableau de chaine de caract�res qui contiendra tous les mots du dictionnaire
*@see Detruire_Dico pour la desallocation du Dictionnaire
*@param[in,out] dico : le Dictionnaire contenant tous les mots d'un fichier
*@param[in] capa : la capacit� initiale du Dictionnaire
*@param[in] p : le pas d'extension choisi lorsqu'il faudra augmenter la taille du Dictionnaire
* @pre capa > 0 , p > 0
*/
void Initialiser_Dico(Dictionnaire& dico, const uint capa, const double p);

/**@brief inclus (en lisant) tous les mots d'un fichier texte repr�sentant le dictionnaire dans le Dictionnaire dynamique 
*@param[in,out] dico : le Dictionnaire qui va contenir tous les mots du dictionnaire
*/
void Ecrire_Mots_Dico(Dictionnaire& conteneurTdeDico);

/**@brief recherche dichotomique d'une cha�ne de caract�res dans un tableau de chaine de caract�res
*@param[in] dico : le tableau de chaines de caract�res dans lequel on cherche le mot
*@param[in] nombreMots : nombre de cha�nes de caract�res dans le tableau
*@param[in] word : mot pour lequel on cherche la pr�sence ou non dans le tableau de cha�nes de caract�res
*@return la pr�sence ou non du mot dans le tableau de cha�nes de caract�res sous la forme d'un bool�en
*/
bool Recherche_Mot_Dico_Dichoto(char** dico, const uint nombreMots, const char* word);

/**@brief recherche dichotomique, par le robot, dans un tableau de chaine de caract�res, d'un mot commen�ant par les m�mes lettres que le chaine de caract�re compl�t�e durant la partie pour le soumettre en r�ponse
*@param[in] dico : le tableau de chaines de caract�res dans lequel on cherche le mot
*@param[in] dicoNombreMots : nombre de cha�nes de caract�res dans le tableau de cha�ne de carac�tre
*@param[in] motDeLaManche : mot compl�t�e durant la partie, pour lequel on cherche un mot identique
*@param[in] lenword : longueur du mot compl�t� durant la manche
*@return le mot trouv�, ayant les premi�res lettres identiques � celui compl�t�e durant la partie
*/
char* Recherche_Robot_Mot_Dichoto(char** dico, const uint dicoNombreMots, const char* motDeLaManche, const uint lenword);

/**@brief recherche dichotomique, par le robot, dans un tableau de chaine de caract�res, d'un mot commen�ant par les m�mes lettres que le chaine de caract�re compl�t�e durant la partie pour jouer la lettre suivante
*@param[in] dico : le tableau de chaines de caract�res dans lequel on cherche le mot
*@param[in] dicoNombreMots : nombre de cha�nes de caract�res dans le tableau de cha�ne de carac�tre
*@param[in] motDeLaManche : mot compl�t� durant la partie, pour lequel on cherche la lettre suivante
* @param[in] lenword : longueur du mot compl�t� durant la manche
*@return une lettre, pour un mot ayant les premi�res lettres identiques � celui compl�t�e durant la partie, ou d'un ? si aucune lettre n'est coh�rente
*/
char Recherche_D�but_Mot_Dichoto(char** dico, const uint dicoNombreMots, const char* motDeLaManche, const uint lenword);

/**@brief desalloue le dictionnaire � la fin de la partie
*@see Initialiser_Dico pour l'allocation du Dictionnaire
*@param[in,out] dico : le Dictionnaire utilis� pour stock� tous les mots du dictionnaire
*/
void Detruire_Dico(Dictionnaire& dico);


#endif // !_DICO_
