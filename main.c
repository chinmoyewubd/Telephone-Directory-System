#include <stdio.h>
#include "directory.h"

int main() {
    Contact contacts[MAX_ENTRIES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n====== TELEPHONE DIRECTORY ======\n");
        printf("1. Load\n");
        printf("2. Store\n");
        printf("3. Insert\n");
        printf("4. Delete\n");
        printf("5. Edit\n");
        printf("6. Search\n");
        printf("7. Show All\n");
        printf("8. Sort by Name\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: loadFromFile(contacts, &count); break;
            case 2: saveToFile(contacts, count); break;
            case 3: insertContact(contacts, &count); break;
            case 4: deleteContact(contacts, &count); break;
            case 5: editContact(contacts, count); break;
            case 6: searchContact(contacts, count); break;
            case 7: showAllContacts(contacts, count); break;
            case 8: sortContacts(contacts, count); break;
            case 9: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
