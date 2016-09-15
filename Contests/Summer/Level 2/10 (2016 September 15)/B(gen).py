from random import randint

for i in range(10):
    for j in range(10):
        if randint(0, 4) in [0, 1]:
            print('*', end='')
        else:
            print('o', end='')
    print()
