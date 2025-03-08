rm resultsDelete/*.csv
make clean
make delete
min=1000
max=2000
step=50

for seed in $(seq 1989 2008)
do
    echo "Running seed $seed"
    echo "n,ipl" >> "./resultsDelete/delete_${seed}.csv"
    for n in $(seq $min $step $max)
    do
        ./delete $n $seed >> "./resultsDelete/delete_${seed}.csv"
    done
done

cd ./resultsDelete/
python3 averageCSV.py > "averageDelete.txt"
cd ..

make clean
make ipl

for seed in $(seq 1989 2008)
do
    echo "Running seed $seed"
    echo "n,ipl" >> "./resultsDelete/ipl_${seed}.csv"
    for n in $(seq $min $step $max)
    do
        ./ipl $n $seed >> "./resultsDelete/ipl_${seed}.csv"
    done
done

cd ./resultsDelete/
python3 averageCSV.py > "averageIPL.txt"
mv averageIPL.txt averageIPL.csv
mv averageDelete.txt averageDelete.csv
cd ..
make clean
echo "Finish!"
