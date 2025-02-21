import pandas as pd
import glob
import sys

csv_files = glob.glob(f"*size={sys.argv[1]}*.csv")

df = [pd.read_csv(f) for f in csv_files]


stop = max([len(x['tpl']) for x in df])

print("tpl,tpu")

for i in range(stop):
    n = 0
    tpl = 0
    tpu = 0
    for f in df:
        if len(f['tpl']) > i:
            n = n + 1
            tpl = tpl + f['tpl'][i]
            tpu = tpu + f['tpu'][i]

    if n < 5:
        quit()

    tpl = tpl / n
    tpu = tpu / n
    print(f"{tpl},{tpu}")
