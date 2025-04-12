# Selection Sort pickes min element and store in front


def SelectionSort(arr):
    for i in range(len(arr)):
        minEle = i
        for j in range(i+1,len(arr)):
            if arr[j] < arr[minEle]:
                minEle = j
        (arr[i],arr[minEle]) = (arr[minEle],arr[i])
        
data = [2,12,10,15,20]
SelectionSort(data)
print(data)
        