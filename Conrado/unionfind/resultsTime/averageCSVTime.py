import pandas as pd
import glob
import sys

csv_files = glob.glob(f"*size={sys.argv[1]}*.csv")

df = [pd.read_csv(f) for f in csv_files]


stop = max([len(x['time']) for x in df])

print("time")

for i in range(stop):
    n = 0
    time = 0
    for f in df:
        if len(f['time']) > i:
            n = n + 1
            time = time + f['time'][i]

    if n < 5:
        quit()

    time = time / n
    print(f"{time}")
