rm resultsIPL/*.csv
make clean
make ipl
min=10000
max=200000
step=5000

for seed in $(seq 1989 2008)
do
    echo "Running seed $seed"
    echo "n,ipl" >> "./resultsIPL/ipl_${seed}.csv"
    for n in $(seq $min $step $max)
    do
        ./ipl $n $seed >> "./resultsIPL/ipl_${seed}.csv"
    done
done

make clean
cd ./resultsIPL/
python3 averageCSV.py > "averageIPL.txt"
mv averageIPL.txt averageIPL.csv
cd ..
echo "Finish!"
