# Quick SOrt 

def QuickSort(arr,low,high):
    if(low < high):
        pIndex = partition(arr,low,high)
        QuickSort(arr,low,pIndex - 1)
        QuickSort(arr,pIndex + 1,high)

def partition(arr,low,high):
    
    i = low
    j = high
    pivot = arr[high]
    print("pivot:",pivot)
    while(i < j):
        while(arr[i] <= pivot and i < high):
            i += 1
        while(arr[j] > pivot and j > low):
            j -= 1
        if(i < j):
            arr[i], arr[j] = arr[j], arr[i]
    arr[high], arr[i] = arr[i], arr[high]
    return i
        
data = [4,2,6,5,7,1,9,3]
QuickSort(data,0,len(data) - 1)
print("Sorted arr:", data)