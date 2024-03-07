import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
f=pd.read_excel('data2.xlsx')
x1=np.array(f['1x'])
x2=np.array(f['2x'])
n=np.array(f['n'])
x=[x1,x2]


for i in x:
    plt.plot(n,i, 'k',ms =3)
    plt.xlabel('N')
    plt.ylabel('t, мс')
    plt.grid(True)
    plt.show()



