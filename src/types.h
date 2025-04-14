/*! \file types.h
    \version 0.1
    \brief Defini divers types pour le jeu
*/

#ifndef TYPES_H
#define TYPES_H

#include <string>

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    static const std::string COMMANDE_ROTATION_DROITE = "d"; /*<! Commande la rotation de la tuile à droite */
    static const std::string COMMANDE_ROTATION_GAUCHE = "g"; /*<! Commande la rotation de la tuile à gauche */
    static const std::string COMMANDE_REPIOCHER = "r"; /*<! Commande le repiochage */

    /*! \enum InterfaceError
        \brief Differents types d'erreur pour l'interface
    */
    enum class InterfaceError {
        indiceIncorrect /*<! Une erreur lie a l'indice */
    };

}

#endif // TYPES_H
