#!/bin/bash
#SBATCH --job-name=serialtest
#SBATCH --partition=Mem500
#SBATCH --output=profilefib.out
#SBATCH --error=profilefib.out

echo "Starting ProfileFib"
echo"1000"
time ./main 1000 10 5
echo"10000"
time ./main 10000 10 5
echo"100000"
time ./main 100000 10 5
echo"1000000"
time ./main 1000000 10  5
#time ./main 1000000 5
#time ./main 40000000000 5
echo "Finished ProfileFib"
