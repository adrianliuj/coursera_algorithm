# -*- coding: utf-8 -*-

filename = 'array.txt'
ht = {}
arr = [None]*1000000
i = 0
count =0

def deleteDuplicatedElementFromList(list):
        list.sort();
        print("sorted list:%s" % list)
        length = len(list)
        lastItem = list[length - 1]
        for i in range(length - 2,-1,-1):
                currentItem = list[i]
                if currentItem == lastItem:
                        list.remove(currentItem)
                else:
                        lastItem = currentItem
        return list

f = open(filename)
while True:
    line = f.readline()
    if line:
        ht[int(line)] = i
        arr[i] = int(line)
        i+=1
    else:
        break    
arr = deleteDuplicatedElementFromList(arr)

for target in range(-10000,10000):
    for num in arr:
        if target - num in ht:
            count+=1
            print(count,target,num)
            break
    