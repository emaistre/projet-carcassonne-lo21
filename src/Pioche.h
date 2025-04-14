/*! \file Pioche.h
    \version 0.1
*/

#ifndef __PIOCHE_H__
#define __PIOCHE_H__

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "Extensions.h"
#include "Tuile.h"

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    /*! \class Pioche
        \brief Represente la pioche
    */
	class Pioche {

	private:

		static const std::string TUILES_NOM_FICHIER; /*!< Nom du fichier contenant la definition des tuiles */

		vector<Tuile*> pioche; /*!< La liste des Tuiles en pioche */

        vector<Tuile*> piocheRiviere; /*!< La liste des Tuiles en pioche de l'extension riviere */

		vector<Tuile*> piochees; /*!< La liste des Tuiles deja piochees */

        std::vector<extensions> ext; /*!< La liste des extensions */

	public:

        /*!
            \brief Constructeur de la classe

            Recupere toutes les Tuiles en memoire
            \param[in] extensionListe Liste des extensions
        */
        Pioche(std::vector<extensions> extensionListe) : ext(extensionListe) {
		    srand(time(NULL)); // Seed aleatoire
            recupereToutesLesTuiles(extensionListe);
		}


		Pioche(const Pioche& p)=delete;

		Pioche& operator=(const Pioche& p)=delete;

        /*! \brief Destructeur de la classe */
		~Pioche() {
			for(Tuile* t : pioche) {
				delete t;
			}
			for(Tuile* t : piochees) {
				delete t;
			}
		}

        /*!
            \brief Donne le nombre de Tuiles dans la pioche
            \return Le nombre de Tuiles dans la pioche
        */
		size_t getTaillePioche() const {
            return pioche.size();
		}

        /*!
            \brief Pioche une Tuile
            \return Pointeur sur la Tuile piochee, ou nullptr s'il n'y a plus de Tuile a piocher
        */
        Tuile* piocher();

        /*!
            \brief Repioche une Tuile
            \return Pointeur sur la Tuile piochee, ou nullptr s'il n'y a plus de Tuile a piocher
        */
		Tuile* repiocher() {
		    // Si la pioche n'a plus de Tuile, on renvoie la derniere Tuile piochee
		    if(getTaillePioche() == 0) {
                return piochees.back();
		    }

            Tuile* dernierePiochee = piochees.back();
            piochees.pop_back();

            Tuile* nouvellePiochee = piocher();

            if(piocheRiviere.size() >= 1) {
                piocheRiviere.push_back(dernierePiochee);
            } else {
                pioche.push_back(dernierePiochee);
            }

            return nouvellePiochee;
		}

	private:

        /*!
            \brief Recupere toutes les tuiles en memoire qui sont dans le fichier TUILES_NOM_FICHIER
            \param[in] extensionListe Liste des extensions
        */
        void recupereToutesLesTuiles(std::vector<extensions> extensionListe);

        /*!
            \brief Pioche une Tuile dans une Pile
            \param[in] p Liste des Tuiles
            \return La Tuile piochee
        */
        Tuile* piocherDansPile(vector<Tuile*>& p);

        /*!
            \brief Pioche une Tuile de demarrage du jeu de base
            \return La Tuile piochee
        */
        Tuile* getTuileDeb() {
            size_t idxT = 0;
            while(idxT < getTaillePioche()) {
                if(pioche[idxT]->getID().getSpecificite() == specificiteTuile::Demarrage) {
                    return pioche[idxT];
                }
                idxT++;
            }
            return nullptr;
        }

        /*!
            \brief Pioche une Tuile de demarrage de l'extension Riviere
            \return La Tuile piochee
        */
        Tuile* getTuileDebRiviere() {
            size_t idxT = 0;
            while(idxT < piocheRiviere.size()) {
                if(piocheRiviere[idxT]->getID().getSpecificite() == specificiteTuile::Demarrage) {
                    return piocheRiviere[idxT];
                }
                idxT++;
            }
            return nullptr;
        }

	};

}


#endif
