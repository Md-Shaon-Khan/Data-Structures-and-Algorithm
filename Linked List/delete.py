# Node class
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
        if self.head is None:
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
        if position == 1:
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

    # Delete from the beginning
    def delete_from_beginning(self):
        if self.head is None:
            print("List is empty!")
            return
        self.head = self.head.next

    # Delete from the end
    def delete_from_end(self):
        if self.head is None:
            print("List is empty!")
            return
        if self.head.next is None:  # Only one node
            self.head = None
            return
        temp = self.head
        while temp.next.next:  # Go till 2nd last node
            temp = temp.next
        temp.next = None

    # Delete from a given position (1-based index)
    def delete_from_position(self, position):
        if self.head is None:
            print("List is empty!")
            return
        if position == 1:  # Beginning
            self.head = self.head.next
            return
        temp = self.head
        count = 1
        while temp is not None and count < position - 1:
            temp = temp.next
            count += 1
        if temp is None or temp.next is None:
            print("Position out of range!")
            return
        temp.next = temp.next.next

    # Display the linked list
    def display(self):
        temp = self.head
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")


# Example usage
ll = LinkedList()
ll.insert_at_end(10)
ll.insert_at_end(20)
ll.insert_at_end(30)
ll.insert_at_end(40)
ll.insert_at_end(50)

print("Initial List:")
ll.display()

ll.delete_from_beginning()
print("After deleting from beginning:")
ll.display()

ll.delete_from_end()
print("After deleting from end:")
ll.display()

ll.delete_from_position(2)
print("After deleting from position 2:")
ll.display()

ll.delete_from_position(10)  # Invalid case
