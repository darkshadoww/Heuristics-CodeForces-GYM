import random
import string
n=50000
print n
for i in range(n):
    print ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(5))
