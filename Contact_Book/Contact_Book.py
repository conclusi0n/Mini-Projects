import os
import json

FILENAME = "contacts.json"

def load_contacts():
    if os.path.exists(FILENAME):
        with open(FILENAME, "r") as file:
            return json.load(file)
    else:
        return []

def save_contacts(contacts):
    with open(FILENAME, "w") as file:
        json.dump(contacts, file, indent=4)

def add_contact(contacts):
    name = input("Enter name: ")
    phone = input("Enter phone: ")
    contacts.append({"name": name, "phone": phone})
    save_contacts(contacts)
    print("Contact saved!")

def view_contacts(contacts):
    if not contacts:
        print("No contacts found.")
    else:
        for idx, contact in enumerate(contacts, 1):
            print(f"{idx}. {contact['name']} - {contact['phone']}")

def search_contact(contacts):
    keyword = input("Enter name to search: ").lower()
    found = False
    for contact in contacts:
        if keyword in contact['name'].lower():
            print(f"{contact['name']} - {contact['phone']}")
            found = True
    if not found:
        print("No contact found.")

def main():
    contacts = load_contacts()

    while True:
        print("\n--- Contact Book ---")
        print("1. Add Contact")
        print("2. View Contacts")
        print("3. Search Contact")
        print("4. Exit")
        choice = input("Choose an option: ")

        if choice == '1':
            add_contact(contacts)
        elif choice == '2':
            view_contacts(contacts)
        elif choice == '3':
            search_contact(contacts)
        elif choice == '4':
            print("Goodbye!")
            break
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()
