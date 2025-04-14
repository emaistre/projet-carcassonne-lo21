/*! \file InterfaceCouleurJoueur.h
    \version 0.1
*/

#ifndef __INTERFACECOULEURJOUEUR_H__
#define __INTERFACECOULEURJOUEUR_H__

#include <QPushButton>

/*! \namespace Carcassonne

    espace de nom regroupant tout ce qui est utilise pour le jeu
*/
namespace Carcassonne {

    /*! \class InterfaceCouleurJoueur
        \brief Couleur d'une interface
    */
    class InterfaceCouleurJoueur : public QPushButton {
        Q_OBJECT
    private:
        static const int TAILLE_POINT = 15;
    private:
        QColor couleurPoint;
    public:
        explicit InterfaceCouleurJoueur(const QColor& couleur, QWidget* parent = nullptr);

        virtual ~InterfaceCouleurJoueur()=default;
    protected:
        void paintEvent(QPaintEvent *event) override;
    };

}

#endif // __INTERFACECOULEURJOUEUR_H__
