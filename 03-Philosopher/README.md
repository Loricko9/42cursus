# Philosopher

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<p align="center"><img src="https://i.imgur.com/lcSX7KA.jpeg" alt="drawing" width="300"/></p>

$$\color{darkgreen}{{\Huge \mathbf {125/100 ✅}}}$$

## The goal

Code a program that uses thread to solve a philosophic problem...
We have a number X of philosopher around a table with an infinite bool of spagheti in the center. We have to keep all philo alive.

Here are the rules to follow : 
- Successively a philo need to eat, sleep and think 
- There is one fork per philo and of course a philo must take his neighbor's fork to eat
- If a philo don't eat after a while, he dies
- There must be one thread per philo

## Execution

This project contain a `Makefile` located in `philo/` folder.
It compile each file in `src/` directory and it produce a executable.
You can simply execute philosopher :
````sh
./philo nb_philo t_death t_eat t_sleep [nb_win]
````
- `nb_philo` is number of philo create for the experience (so the number of thread)
- `t_death` is the time in ms it takes a philo to die after he eat
- `t_eat` is the time in ms it takes a philo to eat and keep 2 fork
- `t_sleep` is the time in ms it takes a philo to sleep afer he eat
- `[nb_win]` is facultative parameter, he define the number of times a philo must eat for stop the experience (if no parameter is found, the experience is infinite)

## Bonus

You need to execute another `Makefile` located in `philo_bonus` folder.

For this part of the project, rules are change:
- All fork are on the middle of the table
- There must be one process per philo (so do one `fork()` for each philo)
- We must use a semaphore to count the number of fork available

Like the normal part you can execute philo_bonus as follow :
````sh
./philo_bonus nb_philo t_death t_eat t_sleep [nb_win]
````