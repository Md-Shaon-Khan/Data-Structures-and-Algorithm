queue = []

queue.append('Shaon')
queue.append('Raunaq')
queue.append('Ahad')
queue.append('Kuasha')

print("Queue: ",queue)

frontElement = queue[0]
print("Peek: ",frontElement)

poppedElement = queue.pop(0)
print("Dequeue: ",poppedElement)

print("After dequeue queue: ",queue)

isEmpty = not bool(queue)
print("isEmpty: ",isEmpty)

print("Size",len(queue))