class Queue:
    def __init__(self):
        self.queue = []
    
    def enqueue(self,element):
        self.queue.append(element)
    
    def dequeue(self):
        if self.isEmpty():
            return "Queue is already Empty."
        return self.queue.pop(0)
    
    def peek(self):
        if self.isEmpty():
            return "Queue is Empty."
        return self.queue[0]
    
    def isEmpty(self):
        return len(self.queue) == 0
    
    def size(self):
        return len(self.queue)
    
myQueue = Queue()

myQueue.enqueue("You")
myQueue.enqueue("were")
myQueue.enqueue("never")
myQueue.enqueue("my")
myQueue.enqueue("friend")

print("Queue: ",myQueue.queue)
print("Peek: ", myQueue.peek())
print("Dequeue: ", myQueue.dequeue())
print("Queue after Dequeue: ", myQueue.queue)
print("isEmpty: ", myQueue.isEmpty())
print("Size: ", myQueue.size())