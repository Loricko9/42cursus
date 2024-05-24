# Minishell

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

<p align="center"><img src="https://i.imgur.com/zEbeMMp.jpeg" alt="drawing" width="2000"/></p>
<p align="center" style="color: darkgreen; font-weight: bold; font-size: 35px;">101/100 ✅</p>
<p align="center" style="font-size: 20px;"><em>Codé avec Arpages</em></p>

## L'objectif

Reproduire simplement `bash` avec des pipe, des redirections, des doubles et simples quotes.

Nous devons aussi recoder quelque commande build-in :
- `cd` avec un chemin absolue et relatif
- `echo` avec l'option -n
- `exit`
- `pwd`
- `export`
- `unset`
- `env`

## Execution

Ce projet contient un `Makefile`.
Il compile chaque fichier present dans `src/` et produit un executable.
Vous pouvez simplement executer minishell avec :
````sh
./minishell
````
Comme dans un bash, un prompt apparaitra et vous pourrez exécuter vos programme avec un chemin relatif ou absolu.