
# Union-Find Data Structure: An Empirical Analysis

## Project Contents  
The project consists of a report in PDF format, along with a C++ implementation of the data structure (see the files `UnionFind.cc/.hh`). Additionally, it includes `main.cc` for executing different experiments, a `generator.cc` file for generating different instances, and a `Makefile` for compiling both files. The `instances/` directory contains all files used for experiments, while `resultMetrics/` and `resultTimes/` store the collected metrics for generating plots.  

## Generating an Executable  

### Generator  
To generate an instance, run:  

```
make generator && ./generator.exe size seed
```
providing a `size` and a `seed` for generating random numbers.  

### Main  
If you are interested in obtaining metric results, execute:  

```
make main && ./main.exe size UnionStrategy PathStrategy
```
providing a `size`, a `UnionStrategy` (a number between 0-2), and a `PathStrategy` (a number between 0-4). The program will then request two natural numbers until a single block is formed in the data structure.  

Otherwise, to obtain time results, execute:  
```
make main_time && ./main.exe size UnionStrategy PathStrategy
```
to get time results.


## Scripts  
To replicate experiments, run `execAll.sh`. This script will clean all data, recompile, regenerate instances, and collect both metrics and timing results.  
