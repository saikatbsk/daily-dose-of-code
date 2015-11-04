#!/usr/bin/python
# Program to perform selection sort (recursive)

def selectionSort(array, start, items):
    if(start >= items - 1):
        return;

    min = start;

    for i in range(start, items):
        if(array[i] < array[min]):
            min = i

    if(min != start):
        array[start], array[min] = array[min], array[start]

    selectionSort(array, start + 1, items)

print("Enter the array to sort:")
array = [int(i) for i in input().split()]

selectionSort(array, 0 , len(array))

print("The sorted array is:")
print(array)
