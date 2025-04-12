# Based on Divide and Conquor Technique


def MergeSort(arr):
    if len(arr) > 1:
        r = len(arr)//2
        firstPart = arr[:r]
        LastPart = arr[r:]
    
        MergeSort(firstPart)
        MergeSort(LastPart)
        i = j = k = 0
        
        while i < len(firstPart) and j < len(LastPart):
            if(firstPart[i] <= LastPart[j]):
                arr[k] = firstPart[i]
                i+=1
                k+=1
            else:
                arr[k] = LastPart[j]
                k+=1
                j+=1
        
        while(i < len(firstPart)):
            arr[k] = firstPart[i]
            i+=1
            k+=1
        while(j < len(LastPart)):
            arr[k] = LastPart[j]
            j+=1
            k+=1

data = [1,0,23,2,46]  ##O(nlogn)
MergeSort(data)
print(data)
        