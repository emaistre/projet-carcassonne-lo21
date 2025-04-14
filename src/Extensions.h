/*! \file Extensions.h
    \version 0.1
    \brief Defini les extensions du jeu
*/

#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <string>
#include <set>
#include <vector>

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    using namespace std;

    /*! \enum extensions
        \brief Les differentes extensions du jeu
    */
    enum class extensions {
        Base, /*!< Jeu de base */
        Paysans, /*!< Extension Paysans */
        Abbe, /*!< Extension Abbe */
        Riviere, /*!< Extension Riviere  */
        Auberge /*!< Extension Auberge */
    };

    /*!
        \brief Extrait les differents meeples a partir de l'extension
        \param[in] ext Extensions dont on veut recuperer les definition des meeples
        \return Les definition des meeples
    */
    std::vector<std::string> getMeeples(std::vector<extensions> ext);

    /*!
        \brief Converti l'extension en chaine de caracteres
        \param[in] e Extensions que l'on veut convertir en chaine de caracteres
        \return Chaine qui represente une extension
    */
    std::string toString(extensions e);

}


#endif // EXTENSIONS_H
