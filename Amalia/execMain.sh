make main

min=10000
max=200000
step=5000

for seed in $(seq 1989 2008)
do
    echo "Executing seed $seed"
    for n in $(seq $min $step $max)
    do
        ./main $n $seed >> "insertion_${seed}.txt"
    done
done

make clean
