#Name: Erin Alltop
#Date: 10/2/17 - Fall 2017
#Assignment: HW2 - STOOGESORT

def stoogeSort(arr, low, high):
		if arr[high] < arr[low]:
			arr[low], arr[high] = arr[high], arr[low]
		if high - low > 1:
			t = (high - low + 1) // 3
			stoogeSort(arr, low, high-t)
			stoogeSort(arr, low+t, high)
			stoogeSort(arr, low, high-t)
		return arr

def stooge(arr): return stoogeSort(arr, 0, len(arr) - 1)

import string
output = open ("stooge.out", "w")
data = open ("data.txt", "r")
with open("data.txt") as data:
	for line in data:
		arr = [int(i) for i in line.split(' ')]
		del arr[0]
		print arr
		stooge(arr)
		print arr
		output.write("\n")
		for line in arr:
			output.write(str(line) + " ")

data.close()
output.close()



