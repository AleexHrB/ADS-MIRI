make clean
make main
rm ./resultsInsertion/*.csv

min=10000
max=200000
step=5000

for seed in $(seq 1989 2008)
do
    echo "Executing seed $seed"
    echo "n,In" >> "./resultsInsertion/insertion_${seed}.csv" 
    for n in $(seq $min $step $max)
    do
        ./main $n $seed >> "./resultsInsertion/insertion_${seed}.csv"     
    done
done

make clean
cd ./resultsInsertion/
python3 averageCSV.py > "averageInsertion.txt"
mv averageInsertion.txt averageInsertion.csv
cd ..
echo "Finish!"
