import random

a = 78643
print a

for i in xrange(0, a):
    print i

for i in xrange(0, a):
    randomFloat = random.random() * (10 ** random.randint(1,10))
    print ("%.6f" %randomFloat)

for i in xrange(0,a):
    print i
    randomFloat = random.random() * (10 ** random.randint(1,10))
    print ("%.6f" %randomFloat)

