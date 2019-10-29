# Explained in class but implemented to class by me

import numpy as np
import matplotlib.pyplot as plt
# import time # time.time_ns (py.3.7++ ) for seed, but problems with str(current) becomes "73e+"

class MiddleSquared:
    '''
    Bad RNG
    '''
    def __init__(self, seed = 2**30):

        self._state = seed


    def __call__(self, n = 1):
        random = np.zeros(n+1)
        for i in range(0, n+1):
            self._state = self._next_number(self._state)
            random[i] = self._state

        self._random = random
        return random

    def _next_number(self, current):
        current **= 2
        return int(str(current)[-6:-2])

    def print(self):
        print(self._random)
             
if __name__ == "__main__":
    rng = MiddleSquared()
    rng(10)
    rng.print()

        

