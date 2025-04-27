def calculator():
    print("Enter first number:")
    num1 = float(input())

    print("Enter second number:")
    num2 = float(input())

    print("\nChoose operation:")
    print("1. Addition (+)")
    print("2. Subtraction (-)")
    print("3. Multiplication (*)")
    print("4. Division (/)")
    choice = int(input("Enter your choice (1-4): "))

    if choice == 1:
        print(f"Result: {num1} + {num2} = {num1 + num2}")
    elif choice == 2:
        print(f"Result: {num1} - {num2} = {num1 - num2}")
    elif choice == 3:
        print(f"Result: {num1} * {num2} = {num1 * num2}")
    elif choice == 4:
        if num2 == 0:
            print("Error: Cannot divide by zero.")
        else:
            print(f"Result: {num1} / {num2} = {num1 / num2}")
    else:
        print("Invalid choice. Please select between 1 and 4.")

if __name__ == "__main__":
    calculator()
