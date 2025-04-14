/*! \file Jeu.h
    \version 0.1
*/


#ifndef __JEU_H__
#define __JEU_H__

#include <vector>

#include "Coordonnee.h"
#include "Plateau.h"
#include "InterfaceConsole.h"

#include <iostream>
#include <algorithm>

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    /*! \class Jeu
        \brief Represente une partie generale de Carcassonne
    */
    class Jeu {

    protected:

        Plateau plateau; /*!< Le plateau de jeu */

        Joueurs* joueurs; /*!< Les joueurs presents dans la partie */

        Joueur* joueurCourant; /*!< Le joueur dont c'est le tour */

        Coordonnees emplacementJouables; /*!< Liste des emplacements jouables a l'instant t */

        Coordonnees emplacementsMeeples; /*!< Liste des emplacements ou l'on peut poser un meeple a l'instant t */
 
        vector<extensions> ext; /*!< Liste des extensions */

    public:

        /*! \brief Constructeur de Jeu
            \param[in] extensionListe Liste des extensions
            \param[in] joueur Le nombre de joueurs dans la partie
                <defaut: 2>
        */
        Jeu(std::vector<extensions> extensionListe, size_t joueur = 2) : plateau(extensionListe), ext(extensionListe) {
            size_t tmp = joueur;
            joueurs = Joueurs::getInstance();
            joueurCourant = joueurs->getJoueur(0);

            // Ajoute des joueurs
            try {
                while(tmp > 2) {
                    joueurs->ajouterJoueur();
                    tmp--;
                }
            } catch(JoueurException& e) {}
        }

        /*! \brief Destructeur de Jeu */
        virtual ~Jeu();

        /*!
            \brief Recupere une reference vers le plateau
            \return Reference sur le plateau
        */
        const Plateau& getPlateau() const { return plateau; }

        /*!
            \brief Recupere une reference vers la pioche
            \return Reference sur la pioche
        */
        const Pioche& getPioche() const { return plateau.getPioche(); }

        /*!
            \brief Recupere une reference vers le gestionnaire de joueurs
            \return Reference sur le gestionnaire de joueurs
        */
        const Joueurs* getJoueurs() const { return joueurs; }

        /*!
            \brief Recupere une reference vers le joueur courant
            \return Reference sur le joueur courant
        */
        const Joueur* getJoueurCourant() const { return joueurCourant; }

        /*!
            \brief Recupere une reference vers les emplacements ou l'on peut poser des tuiles
            \return Reference sur les emplacements ou l'on peut poser des tuiles
        */
        const Coordonnees& getEmplacementsJouables() const { return emplacementJouables; }

        /*!
            \brief Recupere une reference vers les emplacements ou l'on peut poser un Meeple
            \return Reference sur les emplacements ou l'on peut poser un Meeple
        */
        const Coordonnees& getEmplacementsOuPeutPoserMeeple() const { return emplacementsMeeples; }

        /*!
            \brief Recupere les meeples pour un joueur
            \param[in] j Joueur dont on souhaite avoir les meeples
            \return Nombre de meeples pour le joueur
        */
        const vector<int> getMeeplesJoueur(const Joueur& j) {
            vector<int> res;
            if(find(ext.begin(), ext.end(), extensions::Abbe) != ext.end()) {
                res.push_back(j.getNbAbbe());
            }
            if(find(ext.begin(), ext.end(), extensions::Auberge) != ext.end()) {
                res.push_back(j.getNbGrandMeeple());
            }
            if(find(ext.begin(), ext.end(), extensions::Base) != ext.end()) {
                res.push_back(j.getNbBasicMeeples());
            }


            return res;
        }

        /*!
            \brief Place une certaine Tuile sur le plateau
            \param[in] emplIdx Indice de l'emplacement (des coordonnees) ou la Tuile doit etre placee
        */
        void placerTuile(int emplIdx) {
            plateau.poserTuile(emplacementJouables[emplIdx]);
        }

        /*! Passe a la Tuile suivante */
        void nextTuile() {
            plateau.nextTuile();
        }

        /*! \brief Passe au joueur suivant */
        void nextJoueur() {
            joueurCourant = joueurs->getJoueur((joueurCourant->getNumero() + 1) % joueurs->getNbJoueurs());
        }

        /*! \brief Recupere les emplacements ou la tuile courante peut etre posee */
        void recupEmplacementsJouables() {
            emplacementJouables = plateau.getEmplacementsOuPeutPoser();
        }

        /*! \brief Recupere l'indice du joueur gagnant */
        int getJoueurGagnant() const {
            size_t idxJoueurScoreMax = 0;
            int scoreMax = 0;
            // Parcours tous les joueurs
            for(size_t idxJoueur = 0; idxJoueur < joueurs->getNbJoueurs(); idxJoueur++) {
                // Si le score du joueur courant est meilleur, c'est ce dernier qui est le meilleur joueur
                if(joueurs->getJoueur(idxJoueur)->getScore() > scoreMax) {
                    scoreMax = joueurs->getJoueur(idxJoueur)->getScore();
                    idxJoueurScoreMax = idxJoueur;
                }
            }

            return idxJoueurScoreMax;
        }

        /*! 
            \brief Place un meeple dans un environnement
            \param[in] idMeeple Identifiant du meeple
            \param[in] env Pointeur sur l'environnement
            \return Meeple pose

        */
        const Meeple* placeMeeple(std::string& idMeeple, Environnement* env) {
            if(!plateau.getTuile()->peutPoserMeepleDessus(env)) {
                throw TuileException("Erreur, ne peut pas poser de Meeple dessus !");
            }
            Meeple* m = nullptr;
            if(idMeeple == "Meeple") {
                m = joueurCourant->prendreMeeple();
            } else if(idMeeple == "Gd Meeple") {
                m = joueurCourant->prendreGrandMeeple();
            } else if(idMeeple == "Abbe") {
                m = joueurCourant->prendreAbbe();
            }

            plateau.poserMeeple(m, env);
            return m;
        }

        /*! 
            \brief Restitue un meeple au joueur courant
            \param[in] m Pointeur sur le meeple a recuperer

        */
        void restituerMeeple(Meeple* m) {
            BasicMeeple* b = dynamic_cast<BasicMeeple*>(m);
            if(b != nullptr) {
                joueurCourant->rendreMeeple(b);
            }

            GdMeeple* g = dynamic_cast<GdMeeple*>(m);
            if(g != nullptr) {
                joueurCourant->rendreGrandMeeple(g);
            }

            Abbe* a = dynamic_cast<Abbe*>(m);
            if(a != nullptr) {
                joueurCourant->rendreAbbe(a);
            }
        }

    };


    /*! \class JeuConsole
        \brief Represente une partie de Carcassonne en Console
    */
    class JeuConsole final : public Jeu {
    private:
        InterfaceConsole& interface; /*!< Interface utilisateur */
    public:

        /*! \brief Constructeur de Jeu
            \param[in] in L'interface utilisateur utilisee
            \param[in] joueur Le nombre de joueurs dans la partie
                <defaut: 2>
        */
        JeuConsole(std::vector<extensions> ext, InterfaceConsole& in, size_t joueur = 2) : Jeu(ext, joueur), interface(in) {}

        /*! \brief Gere le deroulement d'une partie */
        void partie();
    };



    /*! \class JeuConsole
        \brief Represente une partie de Carcassonne en Graphique
    */
    class JeuGraphique final : public Jeu {
    public:

        /*! \brief Constructeur de Jeu
            \param[in] ext Liste des extensions
            \param[in] joueur Le nombre de joueurs dans la partie
                <defaut: 2>
        */
        JeuGraphique(std::vector<extensions> ext, size_t joueur = 2) : Jeu(ext, joueur) {}

        /*! \brief Fait une rotation a droite de la tuile courante */
        void rotationTuileDroite() { plateau.tournerTuileDroite(); }

        /*! \brief Fait une rotation a gauche de la tuile courante */
        void rotationTuileGauche() { plateau.tournerTuileGauche(); }

        /*! \brief Change de tuile */
        void changerTuile() { plateau.remettreTuile(); }

        /*! 
            \brief Place la tuile courante a certaines coordonnees
            \param[in] c Coordonee ou poser la tuile
            \return Pointeur sur la Tuile placee
        */
        const Tuile* placerTuile(Coordonnee c);

        /*! 
            \brief Indique si le jeu est fini
            \return <tt>true</tt> si le jeu est fini, <tt>false</tt> sinon
        */
        bool estFini() const { return !plateau.peutJouerDesTuiles(); }
    };
}

#endif
