#A binary tree that takes user specified node calues and implement binary tree operations.
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.value = key

class BinaryTree:
    def __init__(self):
        self.root = None

    # Insert a node into the binary tree
    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)

    def _insert(self, current_node, key):
        if key < current_node.value:
            if current_node.left is None:
                current_node.left = Node(key)
            else:
                self._insert(current_node.left, key)
        else:
            if current_node.right is None:
                current_node.right = Node(key)
            else:
                self._insert(current_node.right, key)

    # In-order traversal (Left, Root, Right)
    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            print(node.value, end=' ')
            self.inorder_traversal(node.right)

    # Pre-order traversal (Root, Left, Right)
    def preorder_traversal(self, node):
        if node:
            print(node.value, end=' ')
            self.preorder_traversal(node.left)
            self.preorder_traversal(node.right)

    # Post-order traversal (Left, Right, Root)
    def postorder_traversal(self, node):
        if node:
            self.postorder_traversal(node.left)
            self.postorder_traversal(node.right)
            print(node.value, end=' ')

    # Search for a value in the binary tree
    def search(self, key):
        return self._search(self.root, key)

    def _search(self, node, key):
        if node is None or node.value == key:
            return node
        if key < node.value:
            return self._search(node.left, key)
        return self._search(node.right, key)

    # Find the minimum value in the binary tree
    def find_min(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    # Delete a node from the binary tree
    def delete(self, key):
        self.root = self._delete(self.root, key)

    def _delete(self, node, key):
        if node is None:
            return node

        if key < node.value:
            node.left = self._delete(node.left, key)
        elif key > node.value:
            node.right = self._delete(node.right, key)
        else:
            if node.left is None:
                return node.right
            elif node.right is None:
                return node.left

            temp = self.find_min(node.right)
            node.value = temp.value
            node.right = self._delete(node.right, temp.value)

        return node

    # Find the height of the binary tree
    def height(self, node):
        if node is None:
            return 0
        else:
            left_height = self.height(node.left)
            right_height = self.height(node.right)
            return max(left_height, right_height) + 1

# Function to take user input
def take_input():
    bt = BinaryTree()
    
    # Insert values into the tree
    values = input("Enter the values to insert into the binary tree (space-separated): ").split()
    values = list(map(int, values))
    for value in values:
        bt.insert(value)

    while True:
        print("\nChoose an operation:")
        print("1. In-order Traversal")
        print("2. Pre-order Traversal")
        print("3. Post-order Traversal")
        print("4. Search for a value")
        print("5. Delete a value")
        print("6. Get tree height")
        print("7. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            print("In-order traversal:")
            bt.inorder_traversal(bt.root)
            print()

        elif choice == 2:
            print("Pre-order traversal:")
            bt.preorder_traversal(bt.root)
            print()

        elif choice == 3:
            print("Post-order traversal:")
            bt.postorder_traversal(bt.root)
            print()

        elif choice == 4:
            key = int(input("Enter the value to search: "))
            result = bt.search(key)
            print("Search result for {}: {}".format(key, "Found" if result else "Not Found"))

        elif choice == 5:
            key = int(input("Enter the value to delete: "))
            bt.delete(key)
            print("In-order traversal after deletion:")
            bt.inorder_traversal(bt.root)
            print()

        elif choice == 6:
            print("Height of the tree:", bt.height(bt.root))

        elif choice == 7:
            break

        else:
            print("Invalid choice. Please try again.")

# Run the program
take_input()
