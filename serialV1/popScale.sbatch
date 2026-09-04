#!/bin/bash
#SBATCH --job-name=serialV1_test
#SBATCH --partition=Mem500
#SBATCH --output=popScale.out
#SBATCH --error=popScale.out

echo "Starting profile for serial implementation"
#echo"test 1000"
#time ./main 1000 10 5
#echo"test 5000"
#time ./main 5000 10 5
#echo"test 10000"
#time ./main 10000 10 5
#echo"test 50000"
#time ./main 50000 10 5

echo "test 100000"
time ../main 100000 10 5
echo "test 150000"
time ../main 150000 10 5
echo "test 200000"
time ../main 200000 10 5
echo "test 250000"
time ../main 250000 10 5
echo "test 300000"
time ../main 300000 10 5

#echo"1000000"
#time ./main 1000000 10  5
#time ./main 1000000 5
#time ./main 40000000000 5
echo "Finished serialV1 test"
