# ft_printf

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<p align="center"><img src="https://i.imgur.com/aUJ8mI5.jpg" alt="drawing" width="400"/></p>

$$\color{darkgreen}{{\Huge \mathbf {100/100 ✅}}}$$

## The goal

Recode the printf function in C librairy.
ft_printf function content the following conversion :
| flag | description |
| ---- | ----- |
| %c | Print a single character |
| %s | Prits a string |
| %p | void * pointer argument, print in hexadecimal |
| %d | Prints a decimal (base 10) number |
| %i | Prints an integer in base 10 |
| %u | Prints an unsigned decimal (base 10) number |
| %x | Prints a number in hexadecimal (base 16) lowercase format
| %X | Prints a number in hexadecimal (base 16) uppercase format
| %% | Prints a percent sign | 

## Execution

This project contain a `Makefile`.
It compile each file in `src/` directory and it create a librairy in `.a`.
You can use this librairy by adding flag during the compilation, you may have something like this :
````sh
cc -I include/ -L [lib_folder] [your_file] -lft
````

$\color{red}{\large {\mathbf {⚠\ You\ need\ to\ add\ ft_printf.h\ in\ your\ include\ directory}}}$