import os
import pandas as pd

def average_csv_files():
    csv_files = [file for file in os.listdir() if file.endswith('.csv')]

    # Read all CSV files into dataframes
    dfs = [pd.read_csv(file) for file in csv_files]

    print("n,In")
    for i in range(len(dfs[0]['In'])):
        s = 0
        n = 0
        val = dfs[0]['n'][i]
        for f in dfs:
            s = s + f['In'][i]
            n = n + 1

        s = s / n
        print(f'{val},{s}')

# Run the function
average_csv_files()
