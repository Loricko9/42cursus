# ft_printf

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

<p align="center"><img src="https://i.imgur.com/aUJ8mI5.jpg" alt="drawing" width="400"/></p>

$$\color{darkgreen}{{\Huge \mathbf {100/100 ✅}}}$$

## The goal

Recoder la fonction printf presente dans la librairie en C.
ft_printf fonctionne avec ces conversions :
| flag | description |
| ---- | ----- |
| %c | Affiche un seul charactère |
| %s | Affiche une chaine de charactère |
| %p | Affiche en hexadecimal, un void * pointeur |
| %d | Affiche un nombre decimal (base 10) |
| %i | Affiche un entier (base 10) |
| %u | Affiche un nombre decimal unsigned (base 10) |
| %x | Affiche un nombre en hexadécimal (base 16) en minuscule |
| %X | Affiche un nombre en hexadécimal (base 16) en majuscule |
| %% | Affiche le signe pourcent | 

## Execution

Ce projet contient un `Makefile`
Il compile chaque fichier présent dans le répertoire `src/` et il crée la librairie en `.a`.
Vous pouvez utiliser cette librairie en ajoutant des flags durant la compilation, vous devez donc avoir quelque chose comme ça :
````sh
cc -I include/ -L [lib_folder] [your_file] -lft
````
$\color{red}{\large {\mathbf {⚠\ Vous\ devez\ ajouter\ le\ fichier\ ft_printf.h\ dans\ votre\ répertoire\ include}}}$