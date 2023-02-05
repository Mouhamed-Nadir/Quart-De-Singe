/**
 * @file Partie.h
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 1 31/11/2022
 * Composant de la partie
 */

#ifndef _PARTIE_
#define _PARTIE_

#include "Joueur.h"
#include "Word.h"




struct Partie {
    uint nbjoueurs; //nombre de joueurs participant � la partie de quart de Singe
    Joueur* joueurs; //tableau de joueurs participants � la partie de quart de Singe (voir structure de donn�es Joueur dans Joueur.h)
    Word wordInGame; //mot � compl�ter pendant la partie de quart de singe
};

/**
 * @brief CreateGame cr�e une partie de quart de singe
 * Allocation en m�moire dynamique de la partie
 * de capacit� (NombreJoueurs)
 * @see EndGame, pour sa d�sallocation en fin d'utilisation
 * @param[out] game : la partie de quart de singe
 * @param [in] NombreJoueurs : le nombre de joueurs
 * @pre NombreJoueurs>1
 */
void Create_Game(Partie& game, const int NombreJoueurs);

/**
 * @brief Ajouter des joueurs dans une Partie
 * @param[out] game : la partie de quart de singe
 * @param[in] NombreJoueurs : le nombre de joueurs dans la partie
 * @param[in] argv : une chaine de caract�re contenant la liste des joueurs et leur nature respective
 * @pre NombreJoueurs > 1
 */
void Add_Players(Partie& game, const int NombreJoueurs, const char* argv);

/**
 * @brief D�salloue une partie de quart de singe
 * @see CreateGame, la partie � d�j� �t� allou�
 * @param[out] game : la partie de quart de singe
 */
void End_Game(Partie& game);

#endif // !_PARTIE_
