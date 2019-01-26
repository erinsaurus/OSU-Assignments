# Erin Alltop
# CS344 - Winter 2018
# Description: This program creates 3 files in the same directory as this script.
# Each file contains 10 random lowercase characters.
# It prints out the contents of each file, two random integer (1-42 inclusive)
# and then the product of the two random numbers.

import os
import random
import string
cwd = os.getcwd()
print cwd


def randomString(N):
	return ''.join(random.choice(string.ascii_lowercase) for i in range(N))


file1 = open('file1.txt', 'w')
string1 = (randomString(10))
file1.write(string1 + '\n')
print string1
file1.close()

file2 = open('file2.txt', 'w')
string2 = (randomString(10))
file2.write(string2 + '\n')
print string2
file2.close()

file3 = open('file3.txt', 'w')
string3 = (randomString(10))
file3.write(string3 + '\n')
print string3
file3.close()


a = random.randint(1, 42)
b = random.randint(1, 42)
c = a * b

print a
print b
print c


