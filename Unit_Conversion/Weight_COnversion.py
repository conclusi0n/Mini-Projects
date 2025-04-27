def weight_conversion():
    print("Enter the weight value:")
    weight = float(input())

    print("\nChoose conversion type:")
    print("1. Kilograms to Grams")
    print("2. Grams to Kilograms")
    print("3. Pounds to Kilograms")
    print("4. Kilograms to Pounds")
    choice = int(input("Enter your choice (1-4): "))

    if choice == 1:
        print(f"{weight} kilograms = {weight * 1000} grams")
    elif choice == 2:
        print(f"{weight} grams = {weight / 1000} kilograms")
    elif choice == 3:
        print(f"{weight} pounds = {weight * 0.453592} kilograms")
    elif choice == 4:
        print(f"{weight} kilograms = {weight / 0.453592} pounds")
    else:
        print("Invalid choice. Please select between 1 and 4.")

if __name__ == "__main__":
    weight_conversion()
