/**
 * @file Word.h
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 2/12/2022
 * Composant Word
 */

#ifndef _WORD_
#define _WORD_

typedef unsigned int uint;// raccourci de "unsigned int"

enum { zerochar = 1 };//taille initiale de la cha�ne de caract�re contenue dans Word

struct Word {
    char* word; //mot compl�t� tout au long d'une manche de quart de singe
    int lenword; // longueur de ce mot
};

/**@brief alloue un nouveau mot pour la manche dans la partie en cours
*@see detruire_mot_manche, fonction dans laquelle le mot est d�sallou�
*@param[in,out] NouveauMotManche : le mot pour la manche dans la partie en cours, allou�
*/
void Nouveau_Mot(Word& NouveauMotManche);

/**@brief ajoute une lettre au Word de la partie
*@param[in] motDePartie : la suite de lettres actuel contenu dans Word
*@param[in] lettre : lettre � ajouter � la suite de lettres
*@param[out]: suite de lettres avec la lettre ajout�e
*/
void Add_Letter(Word& motDePartie, const char lettre);

/**brief compare deux mots, celui contenue dans la structure de donn�es Word et celui saisi par un joueur lors d'une interrogation
* @param[in] motDeLaManche : repr�sentation du mot � comparer
* @param[in] motSaisi : mot saisi par le joueur
* @return si les mots sont identiques ou non
*/
bool Compare_Mot(const Word& motDeLaManche, const char motSaisi[]);

/**@brief d�salloue le mot allou� pour la manche
*@see Nouveau_Mot, fonction dans laquelle le mot est allou�
*@param[in,out] MotDeLaManche : le mot a desallou�
*/
void Detruire_Mot_Manche(Word& MotDeLaManche);

#endif //! _WORD_
