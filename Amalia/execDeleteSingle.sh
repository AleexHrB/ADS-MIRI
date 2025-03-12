rm resultsDeleteSingle/*.csv
make clean
make deleteSingle

v=(1000 1500 2000)
for n in ${v[@]}
do
    for seed in $(seq 1989 2008)
    do
        echo "Running seed $seed"
        echo "n,ipl" >> "./resultsDeleteSingle/delete_${seed}_${n}.csv"
        ./deleteSingle $n $seed >> "./resultsDeleteSingle/delete_${seed}_${n}.csv"
    done
    cd ./resultsDeleteSingle/
    python3 averageCSV.py > "averageDeleteSingle$n.txt"
    mv averageDeleteSingle$n.txt averageDeleteSingle$n.csv
    mv *.csv ..
    cd ..
done
mv *.csv ./resultsDeleteSingle/
make clean
