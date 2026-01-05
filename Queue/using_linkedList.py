class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.length = 0

    def enqueue(self,element):
        newNode = Node(element)
        if self.rear is None:
            self.front = self.rear = newNode
            self.length += 1
            return
        self.rear.next = newNode
        self.rear = newNode
        self.length += 1

    def dequeue(self):
        if self.isEmpty():
            return "Queue is Empty."
        self.front = self.front.next

        self.length -= 1
        if self.front is None:
            self.rear = None
        return self.front.data
    
    def peek(self):
        if self.isEmpty():
            return "Queue is Empty."
        return self.front.data
    
    def isEmpty(self):
        return self.length == 0

    def size(self):
        return self.length

    def printQueue(self):
        temp = self.front
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print()


myQueue = Queue()

myQueue.enqueue('A')
myQueue.enqueue('B')
myQueue.enqueue('C')

print("Queue: ", end="")
myQueue.printQueue()
print("Peek: ", myQueue.peek())
print("Dequeue: ", myQueue.dequeue())
print("Queue after Dequeue: ", end="")
myQueue.printQueue()
print("isEmpty: ", myQueue.isEmpty())
print("Size: ", myQueue.size())