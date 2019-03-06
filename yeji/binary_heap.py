class bheap:
    def __init__(self,array):
        self.array=array
        self.num=len(array)-1
    def create_heap(self):
        for i in range(self.num//2-1,0,-1):
            self.downheap(i)
    def insert(self,key_value):
        self.num +=1
        self.array.append(key_value)
        self.upheap(self.N)
    def delete_min(self):
        if self.num==0:
            print("None")
            return None
        minv=self.array[1]
        self.array[1],self.array[-1]=self.array[-1],self.array[1]
        del self.array[-1]
        self.num -=1
        self.downheap(1)
        return minv
    def downheap(self,i):
        while 2*i <= self.num:
            if 2*i+1<=self.num:
                winner=min(self.array[2*i],self.array[2*i+1])
                if self.array[i] > self.array.index(winner):
                    self.array[i],winner=winner, self.array[i]
                    i=self.array.index(winner)
                else : break
            else:
                if self.array[2*i] < self.array[i]:
                    self.array[2*i], self.array[i] = self.array[i],self.array[2*i]
                else: break

            #자식이 2개가 아니면? 여기서 i의 값의 기준을 잘 맞춰야...?
    def upheap(self,j):
        while j>1 and self.array[j//2] > self.array[j]:
            self.array[j], self.array[j//2] = self.array[j//2],self.array[j]
            j=j//2
