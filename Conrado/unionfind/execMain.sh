echo "Executing Quick Union with No Compression"
make clean
make main

QU=0
UW=1
UR=2

NC=0
FC=1
PS=2
PH=3

for f in $(ls ./instances)
do
    size=$(echo $f | grep -oP '(?<=size=)[0-9]+')
    file="./instances/${f}"
    (echo "$size $UR $NC" ; cat $file) | ./main.exe
done

echo "Finish!"
make clean
