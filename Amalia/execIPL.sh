make clean
make ipl
min=10000
max=200000
step=5000

for seed in $(seq 1989 2008)
do
    echo "Running seed $seed"
    for n in $(seq $min $step $max)
    do
        ./ipl $n $seed
    done
done

make clean
