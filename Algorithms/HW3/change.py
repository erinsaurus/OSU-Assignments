#Name: Erin Alltop
#Date: 10/13/17 - Fall 2017
#Assignment: HW3 - Make Change

def changedp(coinArray, change):
  min_coins_used = [0] * (change + 1)
  min_coins_count = [0] * (change + 1)

  for c in range(change + 1):
    coin_count = c
    latest_coin = 1
    for i in [coin_val for coin_val in coinArray if coin_val <= c]:
      if min_coins_count[c - i] + 1 < coin_count:
        coin_count = min_coins_count[c - i] + 1
        latest_coin = i
    min_coins_count[c] = coin_count
    min_coins_used[c] = latest_coin

  min_count = min_coins_count[change]
  min_used = []
  for each in coinArray:
    min_used.append(0)
  change_iter = change
  while change_iter > 0:
    coin = min_coins_used[change_iter]
    k = 0
    for j in coinArray:
      if coin == j:
        min_used[k] += 1
      k += 1

    change_iter = change_iter - coin

  return min_used, min_count

import string
output = open ("change.txt", "w")
data = open ("amount.txt", "r")
with open("amount.txt") as data:
	for line in data:
		arr = [int(i) for i in line.split(' ')]
		print arr