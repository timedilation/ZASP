strs=["flower","fly","flii"]
check=len(min(strs,key=len))
res=0
print(check)
for i in range(check):
    samplelist=[]
    for j in range(len(strs)):
        samplelist.append(strs[j][i])
    print(samplelist)
    if samplelist.count(strs[0][i]) == len(strs):
        res+=1
print(res)
print(strs[0][:res])
