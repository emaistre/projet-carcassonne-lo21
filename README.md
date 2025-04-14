# Projet de LO21 : Carcassonne

Ce projet a consisté en l'implementation d'une version complète du jeu de plateau Carcassonne. 
Le jeu et ses 4 extensions, en C++.
L'interface graphique a été réalisée à l'aide de la bibliothèque Qt.

# Lancement du jeu

Pour lancer le jeu il suffit de compiler le projet à l'aide de qmake par exemple en se servant du fichier .pro pour générer le makefile.

# Déroulement d'une partie

Lorsqu'une partie se lance, une fenètre s'ouvre proposant à l'utilisateur de spécifier :   

- le nombre de joueurs
- les extensions à utiliser lors de la partie

Par la suite, le jeu se lance avec les options choisies. Le système pose automatiquement une Tuile au milieu du plateau.    
Les emplacements apparaisssant en blanc dans le plateau correspondent aux emplacements qui sont autorisés pour placer la tuile courante et dans l'orientation courante (visible dans la vue en bas à droite).
Pour voir si cette Tuile recèle d'autres possibilités de placement, il suffit de la faire tourner en cliquant sur les boutons droite / gauche dans l'interface de la pile. 
Le bouton "repiocher" permet à l'utilisateur de reposer sa tuile et d'en prendre une nouvelle; cela peut être utile pour ne pas se retrouver coincé.   
En cliquant sur l'emplacement vide proposé par le jeu, l'utilisateur pose la tuile de sa pioche; à partir de là plusieurs possibilités s'offrent à lui :

- Il peut poser un meeple en cliquant dans les environnements de même couleur, adjacents à ceux présentants des carrés violet
- Il peut récupérer un de ses meeples en cliquant sur l'environnement dans lequel est situé les siens
- Il peut décider de ne rien faire et utiliser le bouton "passer" en haut à droite, pour permettre au joueur suivant de jouer

Ce procédé se repète jusqu'à ce qu'il n'y ait plus de Tuile en stock.
Lorsque cela se produit, les utilisateurs peuvent modifier les scores des différents joueurs, pour compter les points.