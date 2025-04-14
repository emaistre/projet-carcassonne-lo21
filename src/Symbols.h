/*! \file Symbols.h
    \version 0.1
    \brief Definis dans le fichier csv representant une les differents elements de decors presents sur une tuile
*/

#ifndef __SYMBOLS_H__
#define __SYMBOLS_H__

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    /*!
        \enum idTypesVilles
        \brief Differents identifiants pour representer differents types de villes
    */
    enum class idTypesVilles {
        CLASSIQUE = 0,  /*<! Ville Classique */
        AVEC_BOUCLIER = 1,  /*<! Ville avec Bouclier */
        AVEC_CATHEDRALE = 2 /*<! Ville avec Cathedrale */
    };

    //Cas Particuliers
    const char C_COIN = '@'; /*!< Caractere representant un environnement vide */
    const char C_BOUCLIER = 'B'; /*!< Caractere representant un bouclier */

    //Surfaces
    const char C_PRES = '#'; /*!< Caractere representant un pre */
    const char C_VILLE = 'V'; /*!< Caractere representant une ville */

    //Batiments
    const char C_ABBAYE = 'A'; /*!< Caractere representant une abbaye */
    const char C_JARDIN = 'J'; /*!< Caractere representant un jardin */
    const char C_AUBERGE = 'L'; /*!< Caractere representant une auberge */
    const char C_CATHEDRALE = 'T'; /*!< Caractere representant une cathedrale */

    //Chemins
    const char C_ROUTE = 'C'; /*!< Caractere representant une route */
    const char C_RIVIERE = 'R'; /*!< Caractere representant une riviere */
}


#endif
