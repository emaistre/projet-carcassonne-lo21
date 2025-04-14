/*! \file InterfacePioche.h
    \version 0.1
*/

#ifndef __INTERFACEPIOCHE_H__
#define __INTERFACEPIOCHE_H__

#include <QWidget>
#include "Tuile.h"
#include "InterfaceTuile.h"

class QLabel;
class QProgressBar;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    /*! \class InterfacePioche
        \brief Interface d'une pioche
    */
    class InterfacePioche : public QWidget {
        Q_OBJECT
    public:
    private:
        QProgressBar* nbTuilesRestantes;
        QLabel* titrePage;
        InterfaceTuile* tuilePioche;
        QHBoxLayout *layoutEtatPioche, *layoutRotation;
        QVBoxLayout* layoutPrincipal, *layoutActions;
        QPushButton *btnRotGauche, *btnRotDroite, *btnRepiocher;
    public:

        InterfacePioche(QWidget* parent = nullptr);

        virtual ~InterfacePioche()=default;

        void afficherTuile(const Tuile* t);

        void retirerElementDePioche();

        void setNbTuilesDansPioche(int nbTuiles);

        void initNbTuiles(int nbTuiles);

        InterfaceTuile* getTuileCour() const { return tuilePioche; }

        void rotateTuile(directionRotation d) {
            switch(d) {
            case directionRotation::droite:
                tuilePioche->rotate(90);
                break;
            case directionRotation::gauche:
                tuilePioche->rotate(-90);
            }
        }

    signals:
        void sig_rotationTuile(Carcassonne::directionRotation);
        void sig_repiocher();

    private slots:
        void evtRotGaHandler() {
            emit sig_rotationTuile(directionRotation::gauche);
        }

        void evtRotDrHandler() {
            emit sig_rotationTuile(directionRotation::droite);
        }

        void evtRepiocherHandler() {
            emit sig_repiocher();
        }

    };

}

#endif // __INTERFACEPIOCHE_H__
