# Hash function (same as yours)
def hash_function(value):
    sum_of_chars = 0
    for char in value:
        sum_of_chars += ord(char)
    return sum_of_chars % 10


# Create a hash table (size 10, initially empty)
hash_table = [[] for _ in range(10)]   # Each index has a list (to handle collisions)


# Insert function
def insert(hash_table, key):
    index = hash_function(key)  # Find hash index
    hash_table[index].append(key)  # Insert key into that bucket
    print(f"Inserted '{key}' at index {index}")


# Search function
def search(hash_table, key):
    index = hash_function(key)  # Find bucket index
    if key in hash_table[index]:  # Check if key is inside that bucket
        print(f"'{key}' found at index {index}")
        return True
    else:
        print(f"'{key}' not found in hash table")
        return False


# Example usage
names = ["Bob", "Alice", "Tom", "John", "Mike", "Sara", "Anna", "Eva", "David", "Carol"]

for name in names:
    insert(hash_table, name)

print("\nFinal Hash Table:")
for i, bucket in enumerate(hash_table):
    print(f"Index {i}: {bucket}")


print("\nSearch Results:")
search(hash_table, "Bob")     # Should be found
search(hash_table, "Alice")   # Should be found
search(hash_table, "Chris")   # Not in table
search(hash_table, "Eva")  