/*! \file InterfaceActions.h
    \version 0.1
*/

#ifndef INTERFACEACTIONS_H
#define INTERFACEACTIONS_H

#include <vector>
#include <array>
#include <QWidget>

#include "Extensions.h"
#include "InterfacePersonnages.h"

class QLabel;
class QHBoxLayout;
class QVBoxLayout;

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {


    /*! \class InterfaceActions
        \brief Interface gerant les actions
    */
    class InterfaceActions : public QWidget {
        Q_OBJECT
    public:
    private:
        QVBoxLayout* layoutPrincipal;
        QHBoxLayout* layoutMeeples;
        std::vector<InterfaceMeeple*> meeples;
    public:

        /*! \brief Constructeur de la classe
            \param[in] ext Liste d'extensions
            \param[in] parent Widget parent
        */
        InterfaceActions(std::vector<extensions> ext, QWidget* parent = nullptr);

        /*! \brief Destructeur de la classe
        */
        virtual ~InterfaceActions() {
            for(auto m : meeples) {
                delete m;
            }
        }

        /*! \brief Affiche le nombre restant de meeples
            \param[in] nbMeeplesParCat Nombre de meeples par categorie
        */
        void afficherNombreRestantMeeples(std::vector<int> nbMeeplesParCat);

        /*! \brief RendActif la pose de meeple
        */
        void rendreActifPoseMeeple() {
            for(auto m : meeples) {
                m->activeSelectionMeeple();
            }
        }

        /*! \brief Desactive la pose de meeple
        */
        void desactivePoseMeeple() {
            for(auto m : meeples) {
                m->desactiveSelectionMeeple();
            }
        }

    signals:
        /*! 
            \brief Signal : indique que l'on veut poser un meeple
            \param[in,out] i Pointeur sur l'interface de meeples qui a declenchee le signal
        */
        void sig_veutPoserMeeple(Carcassonne::InterfaceMeeple* i);

    private slots:
        /*! 
            \brief Handler : gère le click sur le bouton de pose de meeple
            \param[in,out] i Pointeur sur l'interface de meeples qui a declenchee le signal
        */
        void handleClickActionBtn(Carcassonne::InterfaceMeeple* i) {
            emit sig_veutPoserMeeple(i);
        }
    };

}

#endif // INTERFACEACTIONS_H
