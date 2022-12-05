import array

# Bubble Sort Algorithm
def bubbleSort(arr, n):
    for i in range(0, n):
        for j in range(0, n - 1):
            if arr[j] > arr[j + 1]:
                # swaping if the number is greater than the next one
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    # printing the sorted array
    print("Sorted array: ")
    for i in arr:
         print(i)
            
# Array
# i is the iterating variable for the array
arr = array.array("i")

# inputing the size of array
n = int(input("Enter the size of the array: "))

print("\n")

# inputing the array
print("Enter the array elements: ")
for i in range(0, n):
    element = int(input())
 
    arr.append(element)

print("\n")
bubbleSort(arr, n)



                
            
    