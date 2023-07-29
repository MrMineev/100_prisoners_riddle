import random

class System:
    def __init__(self, prisoners):
        self.prisoners = list(prisoners)
        self.boxes = [i for i in range(1, len(prisoners) + 1)]

    def shuffle(self):
        random.shuffle(self.boxes)

    def run(self):
        index = 1
        for prisoner in self.prisoners:
            found = False
            for i in range(50):
                box = prisoner.guess()
                value = self.boxes[box - 1]
                prisoner.report(value)

                if value == index:
                    found = True
                    break
            if found == False:
                return False
            index += 1
        return True
