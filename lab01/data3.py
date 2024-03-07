import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
f=pd.read_excel('data3rm.xlsx')
x1=np.array(f['x1'])
x2=np.array(f['x2'])
x3=np.array(f['x3'])
x0=np.array(f['x0'])
n=np.array(f['n'])
x=[x1,x2,x3,x0]
c=['r','g','b','k']
l=['1','2','3','0']

for i in range (4):
    plt.plot(n, x[i], c[i],ms =3, label = l[i])
    plt.xlabel('N')
    plt.ylabel('t, мс')
    plt.grid(True)

plt.legend()
f=pd.read_excel('data3nrm.xlsx')
x1=np.array(f['x1'])
x2=np.array(f['x2'])
x3=np.array(f['x3'])
x0=np.array(f['x0'])
n=np.array(f['n'])
x=[x1,x2,x3,x0]


for i in range (4):
    plt.plot(n, x[i], c[i],ms =3)
    plt.xlabel('N')
    plt.ylabel('t, мс')
    plt.grid(True)
plt.show()


