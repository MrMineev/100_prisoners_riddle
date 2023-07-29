from Prisoner import Prisoner
from System import System

import matplotlib.pyplot as plt

plt.ion()  # Turn on interactive mode

index = []
data = []
data2 = []

N_LIMIT = 1000
for N in range(1, N_LIMIT, 10):
    s = 0
    for i in range(N // 2 + 1, N + 1):
        s += 1 / i
    data2.append((1 - s) * 100)

    Q = 100
    live, die = 0, 0

    for _ in range(Q):
        prisoners = []
        for j in range(N):
            prisoners.append(Prisoner(j + 1, N))

        prison = System(list(prisoners))
        prison.shuffle()
        res = prison.run()

        if res == True:
            live += 1
        else:
            die += 1

    print(f"[LIVE]: {live / Q * 100}%")
    print(f"[DIE]: {die / Q * 100}%")

    index.append(N)
    data.append(live / Q * 100)

    # Update the plot after each iteration
    plt.clf()
    plt.plot(index, data, label='Percentage of Survivors')
    plt.plot(index, data2, label='Estimation', marker='o', linestyle='dashed')
    plt.xlabel('N')
    plt.ylabel('Percentage of Survivors')
    plt.title('Percentage of Survivors vs. N')
    plt.legend()
    plt.draw()
    plt.pause(0.001)

plt.ioff()  # Turn off interactive mode
plt.show()

