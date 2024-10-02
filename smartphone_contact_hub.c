#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

//int contact_count = 0;

//allow use of Constact w/o struct type and referencing
typedef struct
{
char name[MAX_CONTACT_NAME_LENGTH];
char phone[MAX_PHONE_NUMBER_LENGTH];
char email[MAX_EMAIL_ADDRESS_LENGTH];
} Contact;

int main() {
    int userInput;
    //int userInput2;

    FILE *file = fopen("phone_contacts.csv", "r");
    if (file == NULL) {
    printf("Error opening phone contacts file.\n");
    return 1;
    }

    Contact contacts[MAX_CONTACTS];
    int count = 0;
    //declare space allocation by multiple of 8
    char line[256];

    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) && count < MAX_CONTACTS) {
        char *token = strtok(line, ",");
    //if token is valid, copy contents into tokens of current line, minus a space for the null byte
    if (token != NULL) {
        strncpy(contacts[count].name, token, sizeof(contacts[count].name) - 1);
        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(contacts[count].phone, token, sizeof(contacts[count].phone) - 1);
            token = strtok(NULL, ",");
            if (token != NULL) {
                strncpy(contacts[count].email, token, sizeof(contacts[count].email) - 1);
                contacts[count].email[strcspn(contacts[count].email, "\n")] = 0;
                count++;
                }
            }
        }
    }
      
    do {
        printf("Smartphone Contact Hub\n1. List Contacts\n2. Select Contact\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userInput);

        switch (userInput)
        {
        case 1:{
            for (int i = 0;  i < count; i++){
            printf("Phone Contacts:\n1.\tName: %s\n\tPhone: %s\n\tEmail: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            }
            break;
            }

        /*case 2:{
            printf("Enter the contact index: \n");
            scanf("%d", userInput);
            printf("Selected Contact: Name: Phone: Email: ");

            printf("What would you like to do? \n1. Call\n2. Send Email\n");
            printf("Enter your choice: \n");
            scanf("%d", userInput2);
            if (userInput2 == 1){
                printf("Calling %s...\n", contacts[].name);
                }
            else if (userInput2 == 2){
                printf("Sending email to %s...\n", contacts[].email);
            }
            else
            printf("Invalid choice. Please try again.\n");
            break;
            }*/

        case 3:{
            printf("Exiting the Smartphone Contact Hub.\n");
            break;
            }

        default:{
            printf("Invalid choice. Please try again.\n");
            break;
            }
        }
    }
    while (userInput != 3);

    fclose(file);
    file = NULL;
    return 1;

    return 0;
}