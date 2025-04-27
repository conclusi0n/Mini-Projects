#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "contacts.txt"

void add_contact() {
    FILE *fp = fopen(FILENAME, "a"); // append mode
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    char name[100], phone[20];
    printf("Enter name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = 0; // remove newline
    printf("Enter phone: ");
    fgets(phone, 20, stdin);
    phone[strcspn(phone, "\n")] = 0;

    fprintf(fp, "%s,%s\n", name, phone);
    fclose(fp);
    printf("Contact saved!\n");
}

void view_contacts() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }
    char line[150];
    printf("\n--- Contacts List ---\n");
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, "\n");
        if (name && phone) {
            printf("%s - %s\n", name, phone);
        }
    }
    fclose(fp);
}

void search_contact() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        printf("No contacts found.\n");
        return;
    }
    char search[100];
    printf("Enter name to search: ");
    fgets(search, 100, stdin);
    search[strcspn(search, "\n")] = 0;

    char line[150];
    int found = 0;
    while (fgets(line, sizeof(line), fp)) {
        char *name = strtok(line, ",");
        char *phone = strtok(NULL, "\n");
        if (name && phone && strstr(name, search)) {
            printf("%s - %s\n", name, phone);
            found = 1;
        }
    }
    if (!found) {
        printf("No contact found.\n");
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Contact Book ---\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline after scanf

        if (choice == 1)
            add_contact();
        else if (choice == 2)
            view_contacts();
        else if (choice == 3)
            search_contact();
        else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        }
        else
            printf("Invalid choice.\n");
    }
    return 0;
}


// DIdn't did on own , Use AI to generate most of the code and then added some of my own code to make it work