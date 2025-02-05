# Mon Cursus 42

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

## Bienvenue dans le GitHub de mon Cursus 42
Je suis un étudiant 42 français de 42 Perpignan de la promotion 2023.

<div style="text-align: center;"><img src="https://i.imgur.com/ZkXPVN0.jpg =250x20" alt="drawing" width="200"/><h2> lle-saul</h2></div>

## Préambule

### Compilation

Chaque projet contient a `Makefile` qui compile avec `clang`, donc vous avez besoin de le télécharger au préalable, sinon vous pouvez directement compiler avec la commande :
````sh
make
````
Le `Makefile` crée un dossier `obj\` qui contient chaque fichier compiler venant du dossier `src/`.
Vous pouvez supprimer le dossier `obj/` sans effacer l'éxécutable avec la commande :
````sh
make clean
````
Ou vous pouvez supprimer le dossier `obj/` et l'éxécutable avec :
````sh
make fclean
````
Ou recompiler tous les fichiers avec :
````sh
make re
````
Si c'est spécifier, vous pouvez compiler les bonus avec :
````sh
make bonus
````
### Norme
Chaque projet écrit en C sont écrit en accordance avec la Norme de 42.
[Le PDF de la Norme](https://fr.yohan.world/wp-content/uploads/sites/2/2020/05/norme_42_2.0.1.pdf)

--------

## Les Projets

| Projet | Description | Note |
| ------- | -------- | ------- |
| [Libft](00-libft/) | Recoder toutes les fonction basic en C | <div style="color: darkgreen; font-weight: bold;"> 123/100 </div> |
| [Get_next_line](01-Get_next_line/) | Coder une fonction pour lire chaque ligne d'un fichier | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |
| [Printf](01-printf/) | Recoder la fonction printf | <div style="color: darkgreen; font-weight: bold;"> 100/100 </div> |
| [So_long](02-So_long/) | Créer un jeux en 2D avec la MinilibX | <div style="color: darkgreen; font-weight: bold;"> 120/100 </div> |
| [Push_swap](02-Push_swap/) | Coder un algorithme pour trier une pile de nombre | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |
| [Pipex](02-Pipex/) | Recoder les pipe en C | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |
| [Philosopher](03-Philosopher/) | Controler les vie de philosophes | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |
| [Minishell](03-Minishell/) | Recoder un terminal avec des fonctions basique | <div style="color: darkgreen; font-weight: bold;"> 101/100 </div> |
| [CPP Module 00-04](04-CPP_Module_00-04/) | Decouvrir la programmation orientée objet en C++ | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |
| [Cube3d](04-Cube3d/) | Code un jeux 3d en C s'inspirant de DOOM | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |
| [CPP Module 05-09](05-CPP_Module_05-09/) | Approfondir nos connaissance en C++ avec différentes notions | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |
| [Ft_irc](05-ft_irc/) | Coder en C++ un serveur IRC | <div style="color: darkgreen; font-weight: bold;"> 100/100 </div> |
| [Inception](05-Inception/) | Créer plusieur image Docker et héberger un Wordpress | <div style="color: darkgreen; font-weight: bold;"> 100/100 </div> |
| [Ft_Transcendence](https://github.com/Loricko9/Transcendence) | Créer avec Django, un site web de tournois de Pong  | <div style="color: darkgreen; font-weight: bold;"> 125/100 </div> |