def distance_conversion():
    print("Enter the distance value:")
    distance = float(input())

    print("\nChoose conversion type:")
    print("1. Meters to Kilometers")
    print("2. Kilometers to Meters")
    print("3. Feet to Meters")
    print("4. Meters to Feet")
    choice = int(input("Enter your choice (1-4): "))

    if choice == 1:
        print(f"{distance} meters = {distance / 1000} kilometers")
    elif choice == 2:
        print(f"{distance} kilometers = {distance * 1000} meters")
    elif choice == 3:
        print(f"{distance} feet = {distance * 0.3048} meters")
    elif choice == 4:
        print(f"{distance} meters = {distance / 0.3048} feet")
    else:
        print("Invalid choice. Please select between 1 and 4.")

if __name__ == "__main__":
    distance_conversion()
