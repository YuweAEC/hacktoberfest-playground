class Queue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        return self.items.pop(0) if not self.is_empty() else None

    def is_empty(self):
        return len(self.items) == 0

    def print_queue(self):
        if self.is_empty():
            print("The queue is empty.")
        else:
            print("Queue:", " -> ".join(map(str, self.items)))

def main():
    queue = Queue()
    while True:
        print("\nMenu:")
        print("1. Enqueue an item into the queue")
        print("2. Dequeue an item from the queue")
        print("3. Check if the queue is empty")
        print("4. Print the queue")
        print("5. Exit")

        choice = input("Hey User! Please Enter your choice (1-5): ")
        
        if choice == '1':
            item = input("Enter item to enqueue: ")
            queue.enqueue(item)
            print(f"Item '{item}' enqueued into the queue.")
        elif choice == '2':
            dequeued_item = queue.dequeue()
            if dequeued_item is not None:
                print(f"Item '{dequeued_item}' dequeued from the queue.")
            else:
                print("Queue is empty. No item to dequeue.")
        elif choice == '3':
            if queue.is_empty():
                print("The queue is empty.")
            else:
                print("The queue is not empty.")
        elif choice == '4':
            queue.print_queue()
        elif choice == '5':
            print("Exiting the program...")
            break
        else:
            print("Oops! Wrong Choice...please try again!")

if __name__ == "__main__":
    main()

