class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Linked List class
class LinkedList:
    def __init__(self):
        self.head = None

    # Insert at the beginning
    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Insert at the end
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:  # If list is empty
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    # Insert at a given position (1-based index)
    def insert_at_position(self, data, position):
        if position < 1:
            print("Invalid position!")
            return
        new_node = Node(data)
        if position == 1:  # Beginning
            new_node.next = self.head
            self.head = new_node
            return
        temp = self.head
        count = 1
        while temp is not None and count < position - 1:
            temp = temp.next
            count += 1
        if temp is None:
            print("Position out of range!")
            return
        new_node.next = temp.next
        temp.next = new_node

    # Display the linked list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")


# Example usage
ll = LinkedList()
ll.insert_at_beginning(10)   # Insert at beginning
ll.insert_at_end(20)         # Insert at end
ll.insert_at_end(30)         # Insert at end
ll.insert_at_position(15, 2) # Insert at position 2
ll.insert_at_position(5, 1)  # Insert at beginning via position
ll.insert_at_position(100, 10)  # Invalid case
ll.display()
