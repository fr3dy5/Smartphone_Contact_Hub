#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

//allow use of Contact w/o struct type and referencing
typedef struct
{
char name[MAX_CONTACT_NAME_LENGTH];
char phone[MAX_PHONE_NUMBER_LENGTH];
char email[MAX_EMAIL_ADDRESS_LENGTH];
} Contact;

int main() {
    int userInput;
    int contactindex;
    int choice;

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
                    //removes newline character(causes segmentation fault if omitted)
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
                printf("Phone Contacts:\n%d.\tName: %s\n\tPhone: %s\n\tEmail: %s\n", ((i) + 1), contacts[i].name, contacts[i].phone, contacts[i].email);
                }
            break;
            }

        case 2:{
            printf("Enter the contact index: \n");
            scanf("%d", &contactindex);

            for (int i = 0;  i < count; i++){
                if (contactindex >= 0 && contactindex < count) {
                    printf("Selected Contact: Name: %s\nPhone: %s\nEmail: %s\n",
                    contacts[contactindex].name,
                    contacts[contactindex].phone,
                    contacts[contactindex].email);
                    
                    printf("What would you like to do? \n1. Call\n2. Send Email\n");
                    printf("Enter your choice: \n");
                    scanf("%d", &choice);
                    if (choice == 1){
                        printf("Calling %s...\n", contacts[contactindex].name);
                    break;
                        }
                    else if (choice == 2){
                        printf("Sending email to %s...\n", contacts[contactindex].email);
                    break;
                        }
                    else {
                        printf("Invalid choice. Please try again.\n");
                        }
                }
                else {
                    printf("Invalid choice. Please try again.\n");
                    }
                }
            break;
        }

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