from Prisoner import Prisoner
from System import System

N = 100
Q = 1000

live, die = 0, 0

for i in range(Q):
    prisoners = []
    for i in range(N):
        prisoners.append(
            Prisoner(
                i + 1,
                N
            )
        )

    prison = System(list(prisoners))
    prison.shuffle()
    res = prison.run()

    if res == True:
        live += 1
    else:
        die += 1

print(f"[LIVE]: {live / Q * 100}%")
print(f"[DIE]: {die / Q * 100}%")
