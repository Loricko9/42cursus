# Philosopher

[![en](https://img.shields.io/badge/Language-en-red)](README.md)

<p align="center"><img src="https://i.imgur.com/lcSX7KA.jpeg" alt="drawing" width="1000"/></p>

$$\color{darkgreen}{{\Huge \mathbf {125/100 ✅}}}$$

## L'objectif

Coder un programme qui utilise des thread pour resoudre un problème philosophic...
Nous avons un nombre X de philosophe autour d'une table avec un plat infini de spagheti au centre. Le but est de garder en vie tous les philosophe.

Nous devons respecter quelques regles :
- Succesivement les philosophes doivent manger, dormir et penser.
- Il y a seulement une fourchette par philo donc, le philo doit prendre la fourchette de son voisin pour manger
- Si le philo ne mange pas, au bout d'un moment, il meurt
- Il doit y avoir un thread par philo

## Execution

Ce projet contient un `Makefile` dans le dossier `philo/`.
Il compile tous les fichiers present dans `src/` et produit un exécutable.
Vous pouvez simplement exécuter philosopher :
````sh
./philo nb_philo t_death t_eat t_sleep [nb_win]
````
- `nb_philo` est le nombre de philo créé pour l'expérience (donc le nombre de thread)
- `t_death` est le temps en ms que met un philo a mourir si il n'a pas manger
- `t_eat` est le temps en ms que met un philo à manger et à garder 2 fourchettes
- `t_sleep` est le temps en ms que met un philo a dormir après avoir mangé
- `[nb_win]` est un paramètre facultatif, il défini le nombre de fois qu'un philo doit manger pour arrêter l'experience (si aucun parametre n'est donné, l'experience est infinie)

## Bonus

Vous devez exécuter un autre `Makefile` dans le dossier `philo_bonus/`

Pour cette partie du projet, les régles changent :
- Toutes les fourchettes sont au milieu de la table
- Il doit y avoir un processus par philo (donc un `fork()` pour chaque philo)
- Il doit y avoir un semaphore pour compter le combre de fourchette disponible

Tout comme la partie normal, vous pouvez executer philo_bonus comme suit :
````sh
./philo_bonus nb_philo t_death t_eat t_sleep [nb_win]
````