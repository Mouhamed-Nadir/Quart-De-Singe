/**
 * @file JeuEnCours.h
 * @brief SAE 1.02
 * @author BSIKRI Mouhamed Nadir / MAATOUGUI Nassim
 * @version 2 28/12/2022
 * Fonctions essentiels au bon d�roulement du jeu du quart de singe
 */

#ifndef _JeuEnCours_
#define _JeuEnCours_
	#include "Partie.h"
	#include "Dico.h"

enum {
	MAX = 26,
};

/**@brief annonce la fin de la manche et d�salloue le mot constitu� lors de cette manche
* @see Affiche_Check_Point pour l'affichage de la fin de la manche
* @param[in,out] game : la partie de quart de singe
* @param[in,out] motdeLaManche : mot d�sallou� � la fin de la manche
*/
void Fin_Manche(Partie& game,Word& motdeLaManche);

/**@brief annonce l'abandon d'un joueur, lui ajoute un quart de singe et arr�te la manche
* @param[in,out] game : la partie de quart de singe qui se d�roule
* @param[in,out] motDeLaManche : le mot de la manche qui va �tre d�sallou�
* @param[in,out] joueur : le joueur ayant abandonn� et recevant un quart de singe suite � son abandon
*/
void Abandon_Joueur(Partie& game, Word& motDeLaManche, Joueur& joueur);

/**@brief determine le joueur qui doit jouer sous forme d'indice selon si c'est la fin d'une manche ou non
* @see Joueur_Suivant pour comprendre qui est le joueur suivant si ce n'est pas la fin d'une manche
* @param[in] finManche : booleen determinant si c'est la fin d'une manche ou non
* @param[in] joueur : joueur courant
* @param[in] nombreJoueurs : Nombre de joueur jouant au jeu du quart de singe pour cette partie
* @return le joueur suivant
*/
uint Determine_Joueur_Suivant(const bool finManche, const uint joueur, const uint nombreJoueurs);

/**@brief Annonce que le joueur interrog� n'a pas saisi un mot commen�ant par les m�mes lettres que la chaine de caract�res compl�t�e pendant la manche de quart de singe et lui ajoute un quart de singe
* @param[in] motEnCoursDeSaisie : mot saisie par le joueur interrog�, ne commen�ant pas par les bonnes lettres
* @param[in] joueurInterroge : le joueur interrog� 
*/
void Mauvais_Debut_Mot(const char motEnCoursDeSaisie[], Joueur& joueurInterroge);

/**@brief met tous les caract�res de la cha�ne de caract�res en majuscule
* @param[in,out] motEnCoursDeSaisie : cha�ne de caract�res � mettre en majuscule
*/
void Majuscule(char* motEnCoursDeSaisie);

/**brief Confrontation entre le joueur interrog� et le joueur concurrent. Le joueur interrog� saisi un mot, s'il n'existe pas ou s'il ne commence pas par les bonnes lettres, il perd la manche et prend un quart de singe, sinon c'est le joueur concurrent qui perd.
* @param[in] game : la partie de quart de singe
* @param[in,out] joueurInterroge: Joueur invit� � saisir un mot
* @param[in,out] joueurConcurrent: Joueur ayant invit� le joueur pr�cedent � saisir un mot
* @param[in,out] motDeLaManche: mot de la manche d�truit � l'issu de cet confrontation
* @param[in] dico: Dictionnaire dans lequel le mot saisi figure ou non
* @param[in,out] plDebManche: joueur qui va entam� la manche � l'issu de cet confrontation entre les deux joueurs.
*/
void Saisie_Mot_Humain(Partie& game, Joueur& joueurInterroge, Joueur& joueurConcurrent, Word& motDeLaManche, Dictionnaire& dico, uint& plDebManche);

/**@brief renvoie une lettre al�atoire dans l'alphabet
* @return une lettre au hasard dans l'alphabet
*/
char Lettre_Random_Robot();


/**@brief affiche l'identifiant d'un joueur et le mot actuel afin d'annoncer son tour.
*@param[in] joueur : joueur courant
*@param[in] motDelaPartie : la suite de lettres actuel
*/
void Affiche_Tour(const Joueur& joueur, Word& motDelaPartie);

/**@brief annonce l'abandon d'une manche par un joueur
*@param[in] joueur : joueur ayant abandonn� la manche
*/
void Affiche_Abandon(const Joueur& joueur);

/**@brief annonce que le mot existe ainsi que le joueur prend un quart de singe
*@param[in] MotDeLaManche : mot existant � afficher
*@param[in] joueur : le joueur ayant entr� un mot existant et perdu la manche
*/
void Affiche_Mot_Existe(const Word& MotDeLaManche, const Joueur& joueur);

/**@brief affiche pour chaque joueur le nombre de quart de singe � la fin de chaque manche
*@param[in] game : la partie se d�roulant
*/
void Affiche_Check_Point(const Partie& game);


/**@brief affiche une demande au joueur interrog� afin qu'il saisisse un mot
*@param[in] joueurInterroge: Le joueur interroge
*/
void Affiche_Saisir_Mot(const Joueur& joueurInterroge);

/**@brief affiche que le mot saise par le joueur interrog� ne commence pas par les bonnes lettres
*@param[in] motEnCoursDeSaisie : le mot saisie par le joueur interrog�
*@param[in] joueurInterroge : le joueur interroge
*/
void Affiche_Mauvais_Debut_Mot(const char motEnCoursDeSaisie[], Joueur& joueurInterroge);

/**@brief affiche que le mot saisi existe et que, par consequent, le joueur ayant interrog� le joueur precedent perd la manche
*@param[in] motSaisie : le mot saisi lors de l'interrogation
*@param[in] joueurConcurrent : le joueur ayant interroge le joueur precedent, perdant de la manche
*/
void Affiche_Joueur_Concurrent_Manche_Perdu(const char motSaisie[], Joueur& joueurConcurrent);

/**@brief affiche que le mot saisi n'existe pas et que, par consequent, le joueur interrog� perd la manche
*@param[in] motSaisie : le mot saisi lors de l'interrogation
*@param[in] joueurConcurrent : le joueur ayant interrog�, perdant de la manche
*/
void Affiche_Joueur_Interroge_Manche_Perdu(const char motSaisie[], Joueur& joueurInterroge);

/**@brief annonce que la r�ponse du robot existe et qu'il prend un quart de singe
*@param[in] reponse : mot existant � afficher
*@param[in] joueur : le robot ayant entr� un mot existant et perdu la manche
*/

void Affiche_Mot_Existe(char* reponse, const Joueur& joueur);

/**@brief affiche une lettre
*@param[in] lettre : lettre � afficher
*/
void Afficher_Lettre(const char lettre);

#endif // !_JeuEnCours_
