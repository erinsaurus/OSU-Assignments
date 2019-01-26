def print_coins(values, coins): #print out the coins and their quantity used; need to change!
    start = len(values) - 1

    print "Coins used:",
    while start != 0:
        coin = coins[values[start]]
        output.write(str(coin))
        output.write(" ")
        print "%d " % coin,
        start = start - coin


def minCoins(arr, m, v):
  coins = [v + 1] #stores minimum number of coins for i value
  values = [v + 1] #stores denominations of coins
  coins[0] = 0 #base case
  for x in xrange(1, v+1):
    coins.append(x) #set all values to infinite
    x = float("inf")
    values.append(x) #set all values to -1
    x = -1
  for x in xrange(1, v+1):
    for y in xrange(0, m):  #finding the least amount of coins needed
      if(arr[y] <= x):
        sub_res = coins[x - arr[y]]
        if(sub_res != float("inf") and sub_res + 1 < coins[x]):
          coins[x] = sub_res + 1
          values[x] = y;

  print_coins(values, arr)
  return coins[-1]  #returns the minimum number of coins needed


import string
output = open ("change.txt", "w") #open output file
data = open ("amount.txt", "r")   #open input file
with open("amount.txt") as data:
  for line in data:               #parse out line one
    arr = [int(i) for i in line.split(' ')]
    print arr
    m = len(arr)              
    output.write("\n")
    for line in arr: 
      output.write(str(line) + " ") #print line to output file (array)
    nextline = data.next()          #parse line two (value)
    print nextline
    output.write("\n")
    output.write(str(nextline))     #print line two to output file
    v = int(nextline)               #set v to value
    result = minCoins(arr, m, v)
    print ("\n")
    print result
    output.write("\n")
    output.write(str(result))

data.close() #close files!
output.close()

