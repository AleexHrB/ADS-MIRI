make clean
make main

rm results/*.csv

QU=0
UW=1
UR=2

NC=0
FC=1
PS=2
PH=3

size=(1000 5000 10000)

for size in ${size[@]}
do
    for US in $(seq 0 2)
    do
        for PS in $(seq 0 3)
        do
            for f in $(ls ./instances/size=${size}_*)
            do
                seed=$(echo $f | grep -oP '(?<=seed=)[0-9]+')
                ./main.exe $size $US $PS < $f > "./results/${f##*/}_US=${US}_PS=${PS}_Metrics.csv"
            done
            cd ./results/
            python3 averageCSV.py $size > "n=${size}_US=${US}_PS=${PS}_Metrics.csv"
            rm size=${size}*
            cd ..
            echo "size=${size} with US=${US} and PS=${PS} done!"
        done
    done
done





echo "Finish!"

make clean
