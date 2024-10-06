class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop() if not self.is_empty() else None

    def peek(self):
        return self.items[-1] if not self.is_empty() else None

    def is_empty(self):
        return len(self.items) == 0

def main():
    stack = Stack()
    while True:
        print("\n<---Stack Operations--->:")
        print("1. Push an item onto the stack")
        print("2. Pop an item from the stack")
        print("3. Peek at the top item of the stack")
        print("4. Check if the stack is empty")
        print("5. Exit")

        choice = input("Hey User! Enter your choice (1-5): ")
        
        if choice == '1':
            item = input("Enter item to push: ")
            stack.push(item)
            print(f"Item '{item}' pushed onto the stack.")
        elif choice == '2':
            popped_item = stack.pop()
            if popped_item is not None:
                print(f"Item '{popped_item}' popped from the stack.")
            else:
                print("Stack is empty. No item to pop.")
        elif choice == '3':
            top_item = stack.peek()
            if top_item is not None:
                print(f"Top item of the stack: '{top_item}'.")
            else:
                print("Stack is empty. No top item.")
        elif choice == '4':
            if stack.is_empty():
                print("The stack is empty.")
            else:
                print("The stack is not empty.")
        elif choice == '5':
            print("Exiting the program....")
            break
        else:
            print("Oops! Wrong choice..Please try again!")

if __name__ == "__main__":
    main()
