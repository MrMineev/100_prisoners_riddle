import random

class Prisoner:
    def __init__(self, index, N):
        self.index = index
        self.value = index
        self.N = N

    def guess(self):
        # return random.randint(1, self.N)
        return self.value
    
    def report(self, value):
        self.value = value
