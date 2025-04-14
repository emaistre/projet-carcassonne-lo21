/*! \file InterfaceVariables.h
    \version 0.1
    \brief Variables de l'interface
*/

#ifndef __INTERFACEVARIABLES_H__
#define __INTERFACEVARIABLES_H__

#include <string>

namespace Carcassonne {

    const unsigned int FENETRE_PRINCIPALE_LONGUEUR_MAX = 1920; /*<! Longueur maximale de la fenetre */
    const unsigned int FENETRE_PRINCIPALE_HAUTEUR_MAX = 1080; /*<! Hauteur maximale de la fenetre */

    const unsigned int FENETRE_PRINCIPALE_LONGUEUR_MIN = 1000; /*<! Longueur minimale de la fenetre */
    const unsigned int FENETRE_PRINCIPALE_HAUTEUR_MIN = 900; /*<! Hauteur minimale de la fenetre */

    static const std::string TITRE_FENETRE = "Carcassonne"; /*<! Titre de la fenetre*/

    const unsigned int NB_MAX_J = 4; /*<! Nombre maximum de joueurs */

}

#endif // __INTERFACEVARIABLES_H__
