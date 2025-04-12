# In Bubble sort elements are swapped even if they are sorted to solve this we introduce flag

def BubbleSort(array):
    for i in range(len(array)):
        swapflag = False
        for j in range(0,len(array) - 1 - i):
            if(array[j] > array[j+1]):
                # swap(array[j],array[j+1]);  no built in swap in Python
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
                swapflag = True
        if not swapflag:
            break

data = [2,4,1,5,3]

BubbleSort(data)

print('Bubble sort optimized ->')
print(data)
        
        

