echo "Generating instances..."
make clean
make generator

rm ./instances/*

size=(1000 5000 10000 50000 100000)

for n in ${size[@]}
do
    for seed in $(seq 1964 1983)
    do
        echo "Creating instance with size $n and seed $seed"
        output_file="./instances/size=${n}_seed=${seed}.txt"
        ./generator.exe $n $seed > $output_file
    done
done

make clean
