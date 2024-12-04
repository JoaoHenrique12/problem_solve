import random

sum = 0
for i in range((int(1e6))):
    value = random.randint(0,100)
    print(value)
    if value == 23:
        sum += 1

print(sum)
