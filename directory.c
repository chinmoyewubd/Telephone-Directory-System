#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "directory.h"

#define FILENAME "data.txt"

void loadFromFile(Contact contacts[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No existing file found.\n");
        return;
    }

    *count = 0;
    while (fscanf(file, "%d,%99[^,],%d,%19[^,],%199[^\n]\n",
                  &contacts[*count].serial,
                  contacts[*count].name,
                  &contacts[*count].areaCode,
                  contacts[*count].phone,
                  contacts[*count].address) == 5) {
        (*count)++;
    }

    fclose(file);
    printf("Data loaded successfully!\n");
}

void saveToFile(Contact contacts[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d,%s,%s\n",
                contacts[i].serial,
                contacts[i].name,
                contacts[i].areaCode,
                contacts[i].phone,
                contacts[i].address);
    }

    fclose(file);
    printf("Data saved successfully!\n");
}

void insertContact(Contact contacts[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Directory is full!\n");
        return;
    }

    Contact newContact;
    newContact.serial = *count + 1;

    printf("Enter Name: ");
    getchar();
    fgets(newContact.name, MAX_NAME, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;

    printf("Enter Area Code: ");
    scanf("%d", &newContact.areaCode);

    printf("Enter Phone: ");
    scanf("%s", newContact.phone);

    printf("Enter Address: ");
    getchar();
    fgets(newContact.address, MAX_ADDRESS, stdin);
    newContact.address[strcspn(newContact.address, "\n")] = 0;

    contacts[*count] = newContact;
    (*count)++;

    printf("Contact inserted successfully!\n");
}

void deleteContact(Contact contacts[], int *count) {
    int serial;
    printf("Enter Serial No to delete: ");
    scanf("%d", &serial);

    if (serial < 1 || serial > *count) {
        printf("Invalid serial number!\n");
        return;
    }

    for (int i = serial - 1; i < *count - 1; i++) {
        contacts[i] = contacts[i + 1];
        contacts[i].serial = i + 1;
    }

    (*count)--;
    printf("Contact deleted successfully!\n");
}

void editContact(Contact contacts[], int count) {
    int serial;
    printf("Enter Serial No to edit: ");
    scanf("%d", &serial);

    if (serial < 1 || serial > count) {
        printf("Invalid serial number!\n");
        return;
    }

    Contact *c = &contacts[serial - 1];

    printf("Editing %s\n", c->name);

    printf("New Name: ");
    getchar();
    fgets(c->name, MAX_NAME, stdin);
    c->name[strcspn(c->name, "\n")] = 0;

    printf("New Area Code: ");
    scanf("%d", &c->areaCode);

    printf("New Phone: ");
    scanf("%s", c->phone);

    printf("New Address: ");
    getchar();
    fgets(c->address, MAX_ADDRESS, stdin);
    c->address[strcspn(c->address, "\n")] = 0;

    printf("Contact updated successfully!\n");
}

void searchContact(Contact contacts[], int count) {
    char searchName[MAX_NAME];
    int found = 0;

    printf("Enter name to search: ");
    getchar();
    fgets(searchName, MAX_NAME, stdin);
    searchName[strcspn(searchName, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(contacts[i].name, searchName)) {
            printf("\nSerial: %d\nName: %s\nArea Code: %d\nPhone: %s\nAddress: %s\n",
                   contacts[i].serial,
                   contacts[i].name,
                   contacts[i].areaCode,
                   contacts[i].phone,
                   contacts[i].address);
            found = 1;
        }
    }

    if (!found)
        printf("No matching contact found.\n");
}

void showAllContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("Directory is empty.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nSerial: %d\nName: %s\nArea Code: %d\nPhone: %s\nAddress: %s\n",
               contacts[i].serial,
               contacts[i].name,
               contacts[i].areaCode,
               contacts[i].phone,
               contacts[i].address);
    }
}

void sortContacts(Contact contacts[], int count) {
    Contact temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
    printf("Contacts sorted by name.\n");
}
