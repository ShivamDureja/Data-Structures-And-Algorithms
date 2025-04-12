 # Insertion SOrt - sort the left hand side first like cards in hand
 
def InsertionSort(arr):
    for i in range(1,len(arr)):
        curr = arr[i]
        j = i-1
        while arr[j] > curr and j >= 0:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = curr
        
data = [9,5,1,4,3]
InsertionSort(data)
print(data)