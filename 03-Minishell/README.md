# Minishell

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<p align="center"><img src="https://i.imgur.com/zEbeMMp.jpeg" alt="drawing" width="2000"/></p>
<p align="center" style="color: darkgreen; font-weight: bold; font-size: 35px;">101/100 ✅</p>
<p align="center" style="font-size: 20px;"><em>Coded with Arpages</em></p>

## The goal

Reproduce a simple `bash` with pipe, redirection, double & simple quote.

We also need to recode some build-in commande :
- `cd` with relative and absolute path
- `echo` with -n option
- `exit`
- `pwd`
- `export`
- `unset`
- `env`

## Execution

This project contain a `Makefile`.
It compile each file in `src/` directory and it produce a executable.
You can simply execute minishell :
````sh
./minishell
````
Like in bash, a prompt will be displayed and you can enter & execute your program with relative or absolute path.