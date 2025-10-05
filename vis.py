import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import lineStyles

file = open('output.res','r')
lines = file.readlines()

data = []
for line in lines:
    row = line.split()
    row_data = [float(x) for x in row]
    data.append(row_data)

time = np.array([row[0] for row in data])
es_res = np.array([row[1] for row in data])
rk4_res = np.array([row[2] for row in data])
aes_res = np.array([row[3] for row in data])
acc_res = np.array([row[4] for row in data])


plt.figure()
#plt.plot(time,es_res,linestyle = 'dashed', color ='g', label = 'Euler')
plt.plot(time,rk4_res,linestyle = 'solid', color ='b', label = 'RK4')
plt.plot(time,aes_res,linestyle = 'dashed', color ='orange', label = 'Adv Euler')
plt.plot(time,acc_res,linestyle = 'dotted', color ='r', label = 'Acc')
plt.xlabel('t')
plt.ylabel('θ')
plt.legend()
plt.show()