#!/bin/bash
#SBATCH -J mistery_prog
#SBATCH -o %J.out
#SBATCH -e %J.err
#SBATCH -n 24
#SBATCH -p small
#SBATCH -t 5
#SBATCH --reservation=Summerschool

aprun -n 24 ./prog


