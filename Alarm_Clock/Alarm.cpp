#include <stdio.h>
#include <unistd.h>  // for sleep()

int main() {
    int seconds;
    printf("Enter time in seconds: ");
    scanf("%d", &seconds);

    printf("Timer set for %d seconds. Starting now...\n", seconds);

    while (seconds > 0) {
        int minutes = seconds / 60;
        int secs = seconds % 60;
        printf("\r%02d:%02d", minutes, secs);
        fflush(stdout);  // force print immediately
        sleep(1);
        seconds--;
    }

    printf("\n⏰ Time's up!\n");

    return 0;
}
