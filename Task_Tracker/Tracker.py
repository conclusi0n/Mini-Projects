tasks = []

def add_task():
    task = input("Enter new task: ")
    tasks.append({"task": task, "done": False})
    print("Task added!")

def view_tasks():
    if not tasks:
        print("No tasks yet.")
    else:
        for idx, task in enumerate(tasks, 1):
            status = "✔" if task["done"] else "✗"
            print(f"{idx}. [{status}] {task['task']}")

def mark_done():
    view_tasks()
    try:
        task_num = int(input("Enter task number to mark as done: "))
        if 0 < task_num <= len(tasks):
            tasks[task_num - 1]["done"] = True
            print("Task marked as done!")
        else:
            print("Invalid task number.")
    except:
        print("Please enter a valid number.")

def main():
    while True:
        print("\n--- Task Tracker ---")
        print("1. Add Task")
        print("2. View Tasks")
        print("3. Mark Task as Done")
        print("4. Exit")
        choice = input("Choose an option: ")

        if choice == '1':
            add_task()
        elif choice == '2':
            view_tasks()
        elif choice == '3':
            mark_done()
        elif choice == '4':
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()
