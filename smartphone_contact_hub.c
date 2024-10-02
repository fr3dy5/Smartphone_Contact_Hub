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

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

struct Contact {
    char name[MAX_CONTACT_NAME_LENGTH];
    char phone[MAX_PHONE_NUMBER_LENGTH];
    char email[MAX_EMAIL_ADDRESS_LENGTH];
};

/*
incorperate csv file on exe c file
Output: with no existing phone_contacts.csv
$ ./smartphone_contact_hub 
Error opening phone contacts file.
*/

int main(void) {
    int userInput;
    int userInput2;

    FILE *file = fopen("phone_contacts.csv", "r");
    if (file == NULL) {
    printf("Error opening phone contacts file.\n");
    return 1;
    }

    do {
        printf("Smartphone Contact Hub\n1. List Contacts\n2. Select Contact\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", userInput);

        switch (userInput)
        {
        case 1:{
            /* code */
            break;
            }

        case 2:{
            printf("Enter the contact index: \n");
            scanf("%s", userInput);
            printf("Enter the contact index: \n");
            scanf("%s", userInput2);
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

//list and select contacts
/*
xxxx1. List Contacts
xxxx2. Select Contact
xxxx3. Exit
xxxxEnter your choice: 2
Enter the contact index: 4
Selected Contact:
Name: Sarah Taylor
Phone: 713-555-4321
Email: sarah@example.com
What would you like to do?
1. Call
2. Send Email
Enter your choice: 1
Calling Sarah Taylor...
xxxxxExiting the Smartphone Contact Hub.
*/

//call or email selected contact
/*
Smartphone Contact Hub
1. List Contacts
2. Select Contact
3. Exit
Enter your choice: 2
Enter the contact index: 1
Selected Contact:
Name: Michael Brown
Phone: 619-555-0123
Email: michael@example.com
What would you like to do?
1. Call
2. Send Email
Enter your choice: 2
Sending email to michael@example.com...
*/
    fclose(file);
    file = NULL;
    return 1;

    return 0;
}