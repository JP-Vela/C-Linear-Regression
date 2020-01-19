import matplotlib.pyplot as plt
from statistics import mean
import numpy as np

randomPointsX = np.array([1,2,3,4,5,6,7,8], dtype=np.float64)
randomPointsY = np.array([1,2,5,7,6,8,10,9], dtype=np.float64)
finalSlope = 0
finalB = 0

plt.plot(randomPointsX, randomPointsY, 'ro')

def bestFit(x,y):
    finalSlope = ( ((mean(x) * mean(y)) - mean(x*y))
                / ((mean(x)**2) - mean(x**2)))

    finalB = mean(y)-(finalSlope*mean(x))
    return finalSlope

bestFit(randomPointsX, randomPointsY)
finalSlope=bestFit(randomPointsX, randomPointsY)
#print(bestFit(randomPointsX, randomPointsY))

print(finalSlope)


plt.plot(randomPointsX, randomPointsX*finalSlope+finalB)

plt.ylabel('some numbers')
plt.show()