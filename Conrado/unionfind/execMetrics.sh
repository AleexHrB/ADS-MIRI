make clean
make main

rm resultsMetrics/*.csv

size=(1000 5000 10000)

for size in ${size[@]}
do
    for US in $(seq 0 2)
    do
        for PS in $(seq 0 4)
        do
            for f in $(ls ./instances/size=${size}_*)
            do
                seed=$(echo $f | grep -oP '(?<=seed=)[0-9]+')
                ./main.exe $size $US $PS < $f > "./resultsMetrics/${f##*/}_US=${US}_PS=${PS}_Metrics.csv"
            done
            cd ./resultsMetrics/
            python3 averageCSVMetrics.py $size > "n=${size}_US=${US}_PS=${PS}_Metrics.csv"
            rm size=${size}*
            cd ..
            echo "size=${size} with US=${US} and PS=${PS} done!"
        done
    done
done

make clean
echo "Finish!"
