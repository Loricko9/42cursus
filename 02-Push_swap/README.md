# Push_swap

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<p align="center"><img src="https://i.imgur.com/cDx1mo4.jpg" alt="drawing" width="400"/></p>

$$\color{darkgreen}{{\Huge \mathbf {125/100 ✅}}}$$

## The goal

Sort a stack of number.
To help us, we can use a second stack and this list of movement :
| Move | Descrpition |
| ---- | ----------- |
| sa | Swap 2 first number of the stack a |
| sb | Swap 2 first number of the stack b |
| ss | Do sa and sb at the same time |
| pa | Take the first element in stack b and put it at the top of the stack a |
| pb | Take the first element in stack a and put it at the top of the stack b |
| ra | Shift up every element in the stack a (first element become the last) |
| rb | Shift up every element in the stack b (first element become the last) |
| rr | Do ra and rb at the same time |
| rra | Shift down every element int the stack a (last element become the first) |
| rrb | Shift down every element in the stack b (last element become the first) |
| rrr | Do rra and rrb at the same time |
<div style="color: red; font-weight: bold;">This project sort 100 numbers in less than 600 movements and 500 numbers in less than 5000 movements. </div>

$\color{red}{\large {\mathbf {This\ project\ sort\ 100\ numbres\ in\ less\ than\ 600\ movements\ and\ 500\ numbers\ in\ less\ than\ 5000\ movements.}}}$

## Execution

This project contain a `Makefile`.
It compile each file in `src/` directory and it produce a executable
The executable must be executed as follow :
````sh
./push_swap your_number
````
You can't put duplicate number or another charactere than a figure. Just put space or tab between each number.
You can put your number in a same argument or put one number in each argument. 

## Bonus

I code my own checker to verify if number are sorted
You can compile this checker with `make bonus`
The checker take in argument numbers just like push_swap program.
You can execute its with push_swap program as follow :
````sh
$> ARG="your number"; ./push_swap $ARG | ./checker $ARG
````
Or you can also enter manualy all command
<div style="text-align: center;"><img src="https://i.imgur.com/nio9olJ.jpg" alt="drawing" width="500"/></div>

$\color{red}{\large {\mathbf {⚠\ Don't\ forget\ to\ press\ Crtl\ +\ d\ when\ you\ finish\ to\ enter\ your\ command}}}$