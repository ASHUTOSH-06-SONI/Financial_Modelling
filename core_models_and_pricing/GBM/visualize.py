import pandas as pd
import matplotlib.pyplot as plt
paths = pd.read_csv('gbm_output.csv')
for col in paths.columns:
    plt.plot(paths[col],alpha =0.1)
plt.show()