# So_long

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

<div style="text-align: center;"><img src="https://i.imgur.com/oxsa34o.jpg " alt="drawing" width="2000"/></div>

$$\color{darkgreen}{{\Huge \mathbf {120/100 ✅}}}$$

## Le but

Créer un jeu en 2D en C avec l'aide de la MiniLibX, une librairie simplifié, codé par 42 et derivée de X11.
Le programme doit prendre en arguments une map avec seulement ces caractéres :

| CHAR |	OBJET   |
| --------- | ---------- |
| 1         |   Plot   |
| C	        | Jerican |
| E	        |   Sortie  |
| P         |   Voiture  |      
| 0         |   Route     |

Vous pouvez déplacer la voiture à l'aide de fléche directionnel. Vous devez récolter tous les collectibles avant d'atteindre la sortie et gagner le jeux.
Pour les bonus, un compteur de déplacement doit être placé sur la fenetre.

## Exigence

The projet a besoin d'une librairie additionnelle pour compiler la MiniLibX.

Vous pouvez l'installer grâce à ces commandes :

````sh
sudo apt update
sudo apt install libx11-dev
````

Apres l'installation, la compilation de la MiniLibX ce fera automatiquement en exécutant la commande `make`.

## Exécution

Vous devez fournir en argument du programme, un chemin vers une map en format `.ber`.
La map doit au moins remplir ces exigences :
- Seulement un E (représentant la Sortie)
- Seulement un P (représentant le Joueur)
- Un ou plusieurs C (représentant les collectibles)
- Un chemin valide entre le P et le E
- La map doit être entouré de mur (caractère 1)

Plusieurs maps de test sont disponible de le fichier `maps/`
A la fin, lors de l'execution, vous devriez avoir quelque chose comme ça :
````sh
./so_long maps/map1.ber
````