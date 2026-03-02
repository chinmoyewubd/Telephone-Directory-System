#ifndef DIRECTORY_H
#define DIRECTORY_H

#define MAX_ENTRIES 1000
#define MAX_NAME 100
#define MAX_PHONE 20
#define MAX_ADDRESS 200

typedef struct {
    int serial;
    char name[MAX_NAME];
    int areaCode;
    char phone[MAX_PHONE];
    char address[MAX_ADDRESS];
} Contact;

void loadFromFile(Contact contacts[], int *count);
void saveToFile(Contact contacts[], int count);
void insertContact(Contact contacts[], int *count);
void deleteContact(Contact contacts[], int *count);
void editContact(Contact contacts[], int count);
void searchContact(Contact contacts[], int count);
void showAllContacts(Contact contacts[], int count);
void sortContacts(Contact contacts[], int count);

#endif
