/*! \file EnvironnementVide.h
    \version 0.1
*/

#ifndef ENVIRONNEMENTVIDE_H
#define ENVIRONNEMENTVIDE_H

#define UNUSED(x) (void)x

#include "Environnement.h"
#include "Symbols.h"

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    class EnvironnementVide : public Environnement {

    public:

        /*! \brief Constructeur de la classe
            \param[in] premiereTuile Tuile contenant un coin
        */
        EnvironnementVide(Tuile* premiereTuile) : Environnement(premiereTuile) {}

        /*! \brief Destructeur de la classe */
        ~EnvironnementVide()=default;

        /*! \brief Renvoie le caractere representant un type env vide
            \return Le caractere representant env vide
        */
        const char& toChar() const {
            return C_COIN;
        }

        /*!
           \brief Connecte l'environnement courant a un autre
           \param[in] env L'environnement que l'on connecte
           \warning env peut etre desalloue a la fin de l'appel a la methode
           \return L'element courant apres connection
           \note Aucune connection n'est faite
       */
        virtual Environnement* connect(Environnement* env) {
            UNUSED(env);
            return this;
        }

        /*!
            \brief Indique si peut poser un meeple dessus
            \return <tt>true</tt> si on peut poser un meeple dessus, <tt>false</tt> sinon
        */
        bool peutPoserMeeple() const override {
            return false;
        }

    };

}

#endif // ENVIRONNEMENTVIDE_H
