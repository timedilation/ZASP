# 파이썬으로 링크드 리스트 짜보기
# 쉬운 문제지만... 헷갈렸다...
# 파이썬 내장 list 사용하면 시간초과
# (insert, delete 시에 배열처럼 앞, 뒤로 싹 밀기 때문)

import sys

class Node():
    def __init__(self, data):
        self.prev = None
        self.next = None
        self.data = data

class MyList():
    def __init__(self, stringdata):
        self.tail = Node('tail')
        self.cursor = self.tail
        for x in stringdata:
            self.insert_cursor_left(x)
    def move_cursor_left(self):
        if self.cursor.prev:
            self.cursor = self.cursor.prev
    def move_cursor_right(self):
        if self.cursor != self.tail:
            self.cursor = self.cursor.next
    def delete_cursor_left(self):
        if self.cursor.prev:
            if self.cursor.prev.prev:
                self.cursor.prev.prev.next = self.cursor
            self.cursor.prev = self.cursor.prev.prev

    def insert_cursor_left(self, data):
        if self.cursor:
            new_node = Node(data)
            if self.cursor.prev:
                new_node.prev = self.cursor.prev
                self.cursor.prev.next = new_node
            new_node.next = self.cursor
            self.cursor.prev = new_node
    
    def to_string(self):
        result = ''
        temp_cursor = self.tail.prev
        while temp_cursor:
            result += temp_cursor.data
            temp_cursor = temp_cursor.prev
        return result

string = sys.stdin.readline()[:-1]
mylist = MyList(string)
n = int(sys.stdin.readline())
cnt = 0

for line in sys.stdin:
    if line[0] == 'L':
        mylist.move_cursor_left()       
    elif line[0] == 'D':
        mylist.move_cursor_right()
    elif line[0] == 'B':
        mylist.delete_cursor_left()
    elif line[0] == 'P':
        mylist.insert_cursor_left(line[2])
    cnt += 1
    if cnt >= n: break

sys.stdout.write(mylist.to_string()[::-1])