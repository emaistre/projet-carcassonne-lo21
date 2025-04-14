/*! \file Personnages.h
    \version 0.1
*/

#ifndef __PERSONNAGES_H__
#define __PERSONNAGES_H__

#include <string>
#include "Joueur.h"

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    class Environnement;

    /*! \class Meeple
        \brief Represente un Meeple
    */
    class Meeple {
    private:
        bool enJeu; /*!< Le meeple est-il pose sur une Tuile */
        Joueur * joueur; /*!< Le proprietaire du Meeple */

    public:

        /*!
            \brief Constructeur de la classe
            \param[in] j Pointeur sur le Joueur proprietaire
        */
        Meeple(Joueur * j): enJeu(false), joueur(j){}

        /*! \brief Destructeur de la classe */
        virtual ~Meeple()=default;

        /*!
            \brief Donne le proprietaire du meeple
            \return Pointeur sur le Joueur proprietaire
        */
        Joueur* getProprietaire() const {
            return joueur;
        }

        /*!
            \brief Donne l'etat du meeple
            \return L'etat du meeple
        */
        bool getEtat() const {
            return enJeu;
        }

        /*!
            \brief Met le meeple sur le plateau
        */
        void misEnJeu() {
            enJeu = true;
        }

        /*!
            \brief Retire le meeple du le plateau
        */
        void recuperer() {
            enJeu = false;
        }

        /*!
            \brief Converti le Personnage en chaine de caracteres
            \return chaine de caracteres correspondante au personnage
        */
        virtual std::string toString() const {
            return "Meeple";
        }

        /*!
            \brief Indique si l'on peut retirer un meeple de la tuile
            \param[in] e Environnement sur lequel le meeple est pose
            \return <tt>true</tt> si on peut le retirer, <tt>false</tt> sinon
        */
        virtual bool peutEtreRetire(const Environnement& e) {
            return false;
        }
    };


    /*! \class BasicMeeple
        \brief Represente un Meeple Basique
    */
    class BasicMeeple : public Meeple{
    public:
        /*!
            \brief Constructeur de la classe
            \param[in] j Pointeur sur le Joueur proprietaire
        */
        BasicMeeple(Joueur* j): Meeple(j){}

        /*!
            \brief Converti le Meeple en chaine de caracteres
            \return chaine de caracteres correspondante au Meeple
        */
        std::string toString() const override {
            return "Meeple";
        }

        /*!
            \brief Indique si l'on peut retirer un meeple de la tuile
            \param[in] e Environnement sur lequel le meeple est pose
            \return <tt>true</tt> si on peut le retirer, <tt>false</tt> sinon
        */
        bool peutEtreRetire(const Environnement& e) override {
            return true;
        }
    };

    /*! \class GdMeeple
        \brief Represente un Grand Meeple
    */
    class GdMeeple : public Meeple{
    public:
        /*!
            \brief Constructeur de la classe
            \param[in] j Pointeur sur le Joueur proprietaire
        */
        GdMeeple(Joueur* j): Meeple(j){}

        /*!
            \brief Converti le Grand Meeple en chaine de caracteres
            \return chaine de caracteres correspondante au Grand Meeple
        */
        std::string toString() const override {
            return "Gd Meeple";
        }

        /*!
            \brief Indique si l'on peut retirer un meeple de la tuile
            \param[in] e Environnement sur lequel le meeple est pose
            \return <tt>true</tt> si on peut le retirer, <tt>false</tt> sinon
        */
        bool peutEtreRetire(const Environnement& e) override {
            return true;
        }
    };

    /*! \class Abbe
        \brief Represente un Abbe
    */
    class Abbe : public Meeple{
    public:
        /*!
            \brief Constructeur de la classe
            \param[in] j Pointeur sur le Joueur proprietaire
        */
        Abbe(Joueur* j): Meeple(j) {}

        /*!
            \brief Converti l'Abbe en chaine de caracteres
            \return chaine de caracteres correspondante a l'Abbe
        */
        std::string toString() const override {
            return "Abbe";
        }

        /*!
            \brief Indique si l'on peut retirer un meeple de la tuile
            \param[in] e Environnement sur lequel le meeple est pose
            \return <tt>true</tt> si on peut le retirer, <tt>false</tt> sinon
        */
        bool peutEtreRetire(const Environnement& e) override {
            return true;
        }
    };
}

#endif
