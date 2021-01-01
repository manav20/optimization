#!/usr/bin/env python3

from matplotlib import cm
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np


#filename = 'newton_data.txt'
filename = 'steep_desc_data.txt'
filelocation = '../data/' + filename


# 3D plot for cost function
fig1 = plt.figure(1)
ax = fig1.gca(projection='3d')
s = 0.30
x = np.arange(-2, 2+s, s)
y = np.arange(-2, 3+s, s)
x, y = np.meshgrid(x, y)
z = (1.-x)**2 + 100.*(y-x*x)**2
surf = ax.plot_surface(x, y, z, rstride=1, cstride=1, cmap=cm.jet, linewidth=0, antialiased=False)
fig1.colorbar(surf, shrink=0.5, aspect=5)
plt.title('Surface Plot of Cost Function')


# 2D points from data file
fig2 = plt.figure(2)
with open(filelocation) as f:
    lines = f.readlines()
    x1 = [line.split()[0] for line in lines]
    x2 = [line.split()[1] for line in lines]
    x3 = [line.split()[2] for line in lines]
plt.plot(x1, x2);
plt.title('Optmization on 2D plot')

# Contour plot of cost fucntion
fig3 = plt.figure(3)
plt.contour(x, y, z, 200)
plt.title('Contour plot')

# Contour plot with 2D points from data file
fig4 = plt.figure(4)
s = 0.05
x = np.arange(0.5, 1.5+s, s)
y = np.arange(0.5, 1.5+s, s)
x, y = np.meshgrid(x, y)
z = (1.-x)**2 + 100.*(y-x*x)**2
plt.contour(x, y, z, 400)
plt.plot(x1, x2, 'm')
plt.plot(1, 1, 'ro')
plt.title('2D contour plot')

# Contour plot with 2D points from data file zoomed in
fig5 = plt.figure(5)
s = 0.005
x = np.arange(0.9, 1.4+s, s)
y = np.arange(0.9, 1.4+s, s)
x, y = np.meshgrid(x, y)
z = (1.-x)**2 + 100.*(y-x*x)**2
plt.contour(x, y, z, 200)
plt.plot(x1, x2, 'm')
plt.plot(1, 1, 'ro')
plt.title('2D contour plot zoomed in')

# 3D plot of cost function with data from file
fig6 = plt.figure(6)
ax = fig6.gca(projection='3d')
data = np.genfromtxt(filelocation);
x1 = data[:, 0];
x2 = data[:, 1];
x3 = data[:, 2];
ax.scatter(x1, x2, x3, color = "k", marker = ".")
s = 0.2
x = np.arange(-2, 2+s, s)
y = np.arange(-2, 3+s, s)
x, y = np.meshgrid(x, y)
z = (1.-x)**2 + 100.*(y-x*x)**2
ax.scatter (x, y, z, color = "r", marker = ".")



plt.show()



