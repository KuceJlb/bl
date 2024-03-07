import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
f=pd.read_excel('data1.xlsx')
x1=np.array(f['1x'])
x2=np.array(f['2x'])
c1=np.array(f['1c'])
c2=np.array(f['2c'])
n=np.array(f['n'])
x=[x1,c1,x2,c2]


for i in range(4):
    plt.plot(n,x[i], 'k',ms =3)
    plt.xlabel('N')
    plt.ylabel('t, мс')
    plt.grid(True)
    if i % 2 == 1:
        plt.show()



