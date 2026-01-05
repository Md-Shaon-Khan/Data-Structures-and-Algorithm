# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Linked List class
class LinkedList:
    def __init__(self):
        self.head = None

    # Insert at the end
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:   # If list is empty
            self.head = new_node
            return
        temp = self.head
        while temp.next:  # Traverse till last node
            temp = temp.next
        temp.next = new_node

    # Find minimum value
    def find_min(self):
        if self.head is None:
            print("List is empty!")
            return None
        temp = self.head
        minimum = temp.data
        while temp:
            if temp.data < minimum:
                minimum = temp.data
            temp = temp.next
        return minimum

    # Find maximum value
    def find_max(self):
        if self.head is None:
            print("List is empty!")
            return None
        temp = self.head
        maximum = temp.data
        while temp:
            if temp.data > maximum:
                maximum = temp.data
            temp = temp.next
        return maximum

    # Display the linked list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")


# Example usage
ll = LinkedList()
ll.insert_at_end(25)
ll.insert_at_end(10)
ll.insert_at_end(50)
ll.insert_at_end(5)
ll.insert_at_end(30)

print("Linked List:")
ll.display()

print("Minimum Value:", ll.find_min())
print("Maximum Value:", ll.find_max())