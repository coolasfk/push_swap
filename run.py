import os
import random
for x in range(1):
    n = 100
    A = [0 for y in range(n)]
    for y in range(n):
        A[y] = y+1
    random.shuffle(A)
    command = "leaks -atExit -- ./push_swap " + " ".join([str(y) for y in A])
    os.system(command)