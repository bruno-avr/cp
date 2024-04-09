import math

a, b = map(int, input().split())
if (b >= math.log(a, 2)):
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")