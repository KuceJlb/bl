import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math
f=pd.read_excel('forpy.xlsx')
x=np.array(f['n'])
y=np.array(f['_+1'])
plt.scatter(np.log(x), np.log(y), c='k', s=15)
plt.plot([4,12],[4*1.9-5.8, 1.9*12-5.8], c='k',label='+1, k = 1.9')
y=np.array(f['_+100'])
plt.scatter(np.log(x), np.log(y), c='g', s=15)
plt.plot([4,12],[4*1.7-8.2, 1.7*12-8.2], c='g',label='+100, k = 1.7')
y=np.array(f['_x2'])
plt.scatter(np.log(x), np.log(y), c='r', s=15)
plt.plot([4,12],[4*0.83-2.8, 0.83*12-2.8], c='r',label='x2, k = 0.83')




plt.xlabel('ln(N)')
plt.ylabel('ln(t/мкс)')
plt.grid(True)
plt.legend()
plt.show()

y=np.array(f['ph'])
plt.scatter(np.log(x), np.log(y), c='r', s=15)
plt.plot([4,12],[4*0.84+3, 0.84*12+3], c='r',label='push, k = 0.84')
y=np.array(f['pl'])
plt.scatter(np.log(x), np.log(y), c='g', s=15)
plt.plot([4,12],[4*0.91+1.8, 0.91*12+1.8], c='g',label='poll, k = 0.91')


plt.xlabel('ln(N)')
plt.ylabel('ln(t/нс)')
plt.grid(True)
plt.legend()
plt.show()
