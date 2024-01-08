# Libft

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<div style="text-align: center;"><img src="https://i.imgur.com/UQ00ah6.jpg " alt="drawing" width="2000"/></div>
<div style="color: darkgreen; font-weight: bold; text-align: center; font-size: 35px;"><p> 123/100 ✅</p></div>

## The goal

Recode all basic function in C like : 
`strlen` `memset` `strlcpy` `strchr` `atoi` `calloc` `strdup` `strlcat`
And some other function that doesn't exist in librairy in C like : 
`ft_split` `ft_substr` `ft_strjoin` `ft_itoa` `ft_putchar_fd` `ft_strmapi` `ft_striteri`
Bonuses of this project are to code function to manipulate chained lists like : 
`ft_lstadd_back` `ft_lstadd_front` `ft_lstclear` `ft_lstlast` `ft_lstnew` `ft_lstsize`

## Execution

This project contain a `Makefile` which creates the librairy in `.a`. 
You can use this librairy by adding flag during the compilation, you may have something like this :
````sh
cc -I include/ -L [lib_folder] [your_file] -lft
````
<div style="color: red; font-weight: bold; font-size: 20px;">⚠ You need to add `libft.h` in your include directory </div>

## Bonus

This project contain bonus, you can compile its with the command
````sh
make bonus
````
All aditional function are automaticly added at `libft.a`