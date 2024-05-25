# Pipex

[![fr](https://img.shields.io/badge/Langue-fr-blue)](README.fr.md)

<p align="center"><img src="https://i.imgur.com/NJRhA7H.jpg" alt="drawing" width="400"/></p>

$$\color{darkgreen}{{\Huge \mathbf {125/100 ✅}}}$$

## The goal

Reproduce the shell command :
````sh
$> < infile cmd1 | cmd2 > outfile
````

## Execution

This project contain a `Makefile`.
It compile each file in `src/` directory and it produce a executable
The executable must be executed as follow :
````sh
./pipex infile cmd1 cmd2 outfile
````
`infile` `outfile` are the path of each file (`outfile` doesn't have to exist but if it exist, you need to have write permission)
`cmd1` `cmd2` are the command for example in one string for each cmd (ex : "tr ' ' '.'")

## Bonus

You don't have to compile with `make bonus`
This project can take more than 2 cmd, you can add as many cmd as you like
````sh
./pipex infile cmd1 cmd2 cmd3 ... cmdn outfile
````
This project can reproduce this command :
````sh
$> cmd << LIMITER | cmd1 >> file
````
You just have to add `here_doc` in first argument
````sh
./pipex here_doc LIMITER cmd cmd1 file
````
`LIMITER` is the pleyback stop character