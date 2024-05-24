# Libft

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

<p align="center"><img src="https://i.imgur.com/UQ00ah6.jpg" alt="drawing" width="2000"/></p>

$$\color{darkgreen}{{\huge \mathbf {123/100 ✅}}}$$

## L'objectif

Recoder toutes les fonctions basique en C comme par exemple :
`strlen` `memset` `strlcpy` `strchr` `atoi` `calloc` `strdup` `strlcat`
Et d'autre fonctions qui n'existe pas dans les librairies en C comme par exemple :
`ft_split` `ft_substr` `ft_strjoin` `ft_itoa` `ft_putchar_fd` `ft_strmapi` `ft_striteri`
Les bonus de ce projet consiste a coder des fonctions pour manipuler les listes chainées comme par exemple :
`ft_lstadd_back` `ft_lstadd_front` `ft_lstclear` `ft_lstlast` `ft_lstnew` `ft_lstsize`

## Execution

Ce projet contient un `Makefile` qui crée la librairie en `.a`.
Vous pouvez utiliser cette librairie en ajoutant des flags durant la compilation, vous devez donc avoir quelque chose comme ça :
````sh
cc -I include/ -L [lib_folder] [your_file] -lft
````

$$\color{red}{\large {\mathbf {⚠\ Vous\ devez\ ajouter\ le\ fichier\ libft.h\ dans\ votre\ répertoire\ include}}}$$

## Bonus

Ce projet contient des bonus, vous pouvez les compiler avec la commande :
````sh
make bonus
````
Toutes les fonctions supplémentaires sont automatiquement ajouter au fichier `libft.a`
