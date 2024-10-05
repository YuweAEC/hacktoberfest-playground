class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def print_list(self):
        current = self.head
        if current is None:
            print("The list is empty.")
            return
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    def delete_node(self, key):
        current = self.head
        
        # If head node itself holds the key
        if current is not None:
            if current.data == key:
                self.head = current.next  # Changed head
                current = None
                return

        # Search for the key to be deleted
        prev = None
        while current is not None:
            if current.data == key:
                break
            prev = current
            current = current.next

        # If key was not present in linked list
        if current is None:
            print(f"Node with data {key} not found.")
            return

        # Unlink the node from linked list
        prev.next = current.next
        current = None

def main():
    ll = LinkedList()
    while True:
        print("\n<----Linked List operations---->:")
        print("1. Append a node")
        print("2. Print the list")
        print("3. Delete a node")
        print("4. Exit")

        choice = input("Hey User! Please Enter your choice (1-4): ")
        
        if choice == '1':
            data = int(input("Enter data to append: "))
            ll.append(data)
            print(f"Node with data {data} appended.")
        elif choice == '2':
            print("Linked List:")
            ll.print_list()
        elif choice == '3':
            key = int(input("Enter data of the node to delete: "))
            ll.delete_node(key)
        elif choice == '4':
            print("Exiting the program.")
            break
        else:
            print("Oops! Wrong Choice...Please try again!")

if __name__ == "__main__":
    main()