import numpy as np
import pandas as pd 
df = pd.read_csv('HistoricalData_1785591887411.csv')
df['Close/Last'] = df['Close/Last'].str.replace('$', '').astype(float)
df = df.iloc[::-1].reset_index(drop=True)
df.to_csv('aapl_clean.csv', index=False)