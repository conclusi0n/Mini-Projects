import time

def simple_timer():
    seconds = int(input("Enter time in seconds: "))
    print(f"Timer set for {seconds} seconds. Starting now...")

    while seconds:
        mins, secs = divmod(seconds, 60)
        timer_display = f"{mins:02d}:{secs:02d}"
        print(timer_display, end="\r")
        time.sleep(1)
        seconds -= 1

    print("\n⏰ Time's up!")

if __name__ == "__main__":
    simple_timer()
