#!/usr/bin/python
# Program to perform selection sort

def selectionSort(array):
    l = len(array)
    for start in range(0,int(l)):
        min = start
        # Locate position of minimum element in current segment
        for i in range(min + 1,int(l)):
            if array[i] < array[min]:
                min = i
        # Move element to the beginning of the current segment
        array[start], array[min] = array[min], array[start]

print("Enter the array to sort:")
array = [int(i) for i in input().split()]

selectionSort(array)

print("The sorted array is:")
print(array)
