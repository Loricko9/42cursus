# Minishell

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<p align="center"><img src="https://i.imgur.com/zEbeMMp.jpeg" alt="drawing" width="400"/></p>

$$\color{darkgreen}{{\Huge \mathbf {101/100 ✅}}}$$
$$\color{dark}{\huge {Coded\ with\ Arpages}}$$

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