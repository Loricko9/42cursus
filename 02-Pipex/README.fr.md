# Pipex

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

<p align="center"><img src="https://i.imgur.com/NJRhA7H.jpg" alt="drawing" width="400"/></p>

$$\color{darkgreen}{{\Huge \mathbf {125/100 ✅}}}$$

## The goal

Reproduire la commande terminal :
````sh
$> < infile cmd1 | cmd2 > outfile
````

## Execution

Ce projet contient un `Makefile`.
Il compile tous les fichier présent dans `src/` et produit un exécutable.
Le programme doit être lancer comme suit :
````sh
./pipex infile cmd1 cmd2 outfile
````
`infile` `outfile` sont les chemin de chaque fichier (`outfile` ne doit pas obligatoirement exister mais si il existe, vous devez avoir la permission d'écrire dedans)
`cmd1` `cmd2` sont les commandes en une seul chaine de charactére par commande (ex : "tr ' ' '.'")

## Bonus

Vous n'avez pas besoin de compiler avec `make bonus`
Ce projet peut prendre plus de 2 commande, vous pouvez en rajouter autant que vous souhaitez
````sh
./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile
````
Ce projet peut reproduire cette commande :
````sh
$> cmd << LIMITER | cmd1 >> file
````
Vous avez juste a ajouter `here_doc` en 1er argument
````sh
./pipex here_doc LIMITER cmd cmd1 file
````
`LIMITER` est le charactère d'arrêt de lecture