import time
import matplotlib.pyplot as plt
import numpy as np
import random

# mergesort algorithm
def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        left = arr[:mid]
        right = arr[mid:]
        mergeSort(left)
        mergeSort(right)
        # merge
        i = j = k = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]: # <= for stable sort
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1
        # left
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1
        # right
        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1



x = []
y = []

n = [10000, 250000, 500000, 750000, 1000000, 1250000, 1500000, 1750000, 2000000]
# n = [10000, 250000, 500000]
for i in range(len(n)):
    try:
        with open("input.txt", "w+") as f:
            f.writelines(str(random.randint(0, j)) + "\n" for j in range(n[i]))

        with open("input.txt", "r+") as f:
            arr = [int(line) for line in f]

        start = time.time()
        mergeSort(arr)
        end = time.time()

        y.append(end - start)
        x.append(n[i])

    except:
        break

# Plot the curve
plt.plot(x, y, 'ro', color='red', alpha=0.2)
plt.xlabel('Input Size')
plt.ylabel('Execution Time (s)')
plt.title('Merge Sort')
print(x)
print(y)
plt.plot(x, y)
plt.show()

#  also plot a bar graph using this
plt.bar(x, y, color='green', width=50000)
plt.xlabel('Input Size')
plt.ylabel('Execution Time (s)')
plt.title('Merge Sort')
plt.show()