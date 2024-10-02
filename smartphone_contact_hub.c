/*
1.Create a program that allows users to manage their contacts on a smartphone.
2.Read contact information from a CSV file named "phone_contacts.csv".
3.Store the contact information in arrays for efficient access and manipulation.
4.Implement a main menu that provides options to list contacts, select a contact, and exit the application.
5.When the user chooses to list contacts, display a numbered list of all contacts with their name, phone number, and email address.
6.When the user chooses to select a contact, prompt them to enter the contact index and display the selected contact's information.
7.After displaying the selected contact, provide options to call or send an email to that contact.
8.If the user chooses to call, display a message indicating that the call is being made to the selected contact.
9.If the user chooses to send an email, display a message indicating that an email is being sent to the selected contact's email address.
10.If the user enters an invalid contact index or an invalid choice, display an appropriate error message.
11.Include appropriate error handling for file I/O operations, such as checking if the file was successfully opened.
12.Use meaningful variable names, function names, and comments to enhance code readability and maintainability.
13.Implement the program in a modular way by creating separate functions for displaying contacts, displaying the selected contact, and performing contact actions.
14.Use appropriate data structures and data types to store and manipulate contact information efficiently.
15.Ensure that the program handles user input validation and provides appropriate feedback to the user.
*/

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