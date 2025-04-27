# Function to load accounts from the file
def load_accounts(filename='accounts.txt'):
    accounts = {}
    try:
        with open(filename, 'r') as file:
            for line in file:
                name, balance = line.strip().split(',')
                accounts[name] = float(balance)
    except FileNotFoundError:
        print("Accounts file not found!")
    return accounts

# Function to save accounts back to the file
def save_accounts(accounts, filename='accounts.txt'):
    with open(filename, 'w') as file:
        for name, balance in accounts.items():
            file.write(f"{name},{balance}\n")

def check_balance(name, accounts):
    """Check the balance of the account"""
    if name in accounts:
        print(f"\nHello, {name}! Your current balance is: ${accounts[name]}")
    else:
        print("Account not found!")

def withdraw_cash(name, accounts):
    """Withdraw cash from the account"""
    if name not in accounts:
        print("Account not found!")
        return
    
    try:
        amount = float(input("Enter the amount to withdraw: $"))
        
        # Check if the user has enough balance
        if amount > accounts[name]:
            print("Insufficient balance!")
        elif amount <= 0:
            print("Invalid amount! Please enter a positive number.")
        else:
            accounts[name] -= amount
            save_accounts(accounts)  # Save the updated account details back to the file
            print(f"Withdrawal successful! Your new balance is: ${accounts[name]}")
    
    except ValueError:
        print("Please enter a valid number.")

def atm_simulation():
    """Main ATM simulation program"""
    print("Welcome to the ATM!\n")

    # Load account data from the file
    accounts = load_accounts()

    # Insert card (input person's name)
    name = input("Please insert your card by typing your name: ")

    # Check if the name exists in the accounts
    if name in accounts:
        print(f"\nWelcome back, {name}!\n")

        while True:
            # ATM menu
            print("\nPlease choose an option:")
            print("1. Check Balance")
            print("2. Withdraw Cash")
            print("3. Exit")
            
            choice = input("Enter your choice (1/2/3): ")
            
            if choice == '1':
                check_balance(name, accounts)
            elif choice == '2':
                withdraw_cash(name, accounts)
            elif choice == '3':
                print("Thank you for using the ATM. Goodbye!")
                break
            else:
                print("Invalid choice. Please select again.")
    else:
        print("Sorry, the account name is not found. Please try again.")

# Run the ATM simulation
if __name__ == "__main__":
    atm_simulation()
