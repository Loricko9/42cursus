# Push_swap

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

<div style="text-align: center;"><img src="https://i.imgur.com/cDx1mo4.jpg" alt="drawing" width="400"/></div>

$$\color{darkgreen}{{\Huge \mathbf {125/100 ✅}}}$$

## L'objectif

Trier une pile de nombres
Pour nous aider, nous avons une deuxième pile et une liste de mouvements :
| Move | Descrpition |
| ---- | ----------- |
| sa | Swap les 2 prmeier nombre de la pile a |
| sb | Swap les 2 prmeier nombre de la pile b |
| ss | Faire sa et sb en même temps |
| pa | Prendre le premier élément de la pile b et le mettre en haut de la pile a |
| pb | Prendre le premier élément de la pile a et le mettre en haut de la pile b |
| ra | Décale d’une position vers le haut tous les élements de la pile a (le premier élément devient le dernier) |
| rb | Décale d’une position vers le haut tous les élements de la pile b (le premier élément devient le dernier) |
| rr | Faire ra et rb en même temps |
| rra | Décale d’une position vers le bas tous les élements de la pile b (le premier élément devient le dernier) |
| rrb | Décale d’une position vers le bas tous les élements de la pile b (le premier élément devient le dernier) |
| rrr | Faire rra et rrb en même temps |

$\color{red}{\large {\mathbf {Ce\ projet\ trie\ 100\ nombres\ en\ moins\ de\ 600\ coups\ et\ 500\ nombres\ en\ moins\ de\ 5000\ coups.}}}$

## Execution

Ce projet contient un `Makefile`.
Il compile tous les fichier présent dans `src/` et produit un exécutable.
Le programme doit être lancer comme suit :
````sh
./push_swap your_number
````
Vous ne pouvez pas entrer 2 fois le même nombre ou un autre charactère différent d'un chiffre. Seulement les espaces et les tabulations entre chaque nombres sont toléré.
Vous pouvez mettre vos nombre dans un seul et même argument ou un nombre dans chaque argument.

## Bonus

J'ai codé mon propre checker pour vérifier si les nombres étaient trié correctement.
Vous pouvez compiler le checker avec `make bonus`
Le checker prend en argument les nombres tous comme le programme push_swap.
Vous pouvez l'éxécuter avec le push_swap comme suit :
````sh
$> ARG="your number"; ./push_swap $ARG | ./checker $ARG
````
Ou entrer manuellement toutes les commandes :
<div style="text-align: center;"><img src="https://i.imgur.com/nio9olJ.jpg" alt="drawing" width="500"/></div>

$\color{red}{\large {\mathbf {⚠\ N'oubliez\ pas\ de\ faire\ Ctrl\ +\ d\ quand\ vous\ avez\ finit\ d'entrer\ les\ commandes}}}$