a = [1,5,6,7,3]
s = max(a)
for i in range(len(a)-1):
    if a[i] < s:
        s = a[i]
print(s)