#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
void saveContactsToFile(AddressBook *addressBook)
{
   FILE *ptr1=fopen("file.csv","w");
   for(int i=0;i<addressBook->contactCount;i++)
   {
      // printf("%s\n",addressBook->contacts[i].name);
       fprintf(ptr1,"%s,",addressBook->contacts[i].name);
       fprintf(ptr1,"%s,",addressBook->contacts[i].phone);
       fprintf(ptr1,"%s",addressBook->contacts[i].email);
       putc('\n',ptr1);
   }
   fclose(ptr1);
}

void listContacts(AddressBook *addressBook)
{
    /* Define the logic for print the contacts */
    printf("Total number of contacts:%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
         printf(" %s,%s,%s,\n", addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount=0;
    loadContactsFromFile(addressBook);
}


// void saveAndExit(AddressBook *addressBook)
// {
//    FILE *ptr1=fopen("contacts.txt","w");
//    for(int i=0;i<addressBook->contactCount;i++)
//    {
//        fprintf(ptr1,"%s,",addressBook->contacts[i].name);
//        fprintf(ptr1,"%s,",addressBook->contacts[i].phone);
//        fprintf(ptr1,"%s",addressBook->contacts[i].email);
//        putc('\n',ptr1);


//    }
//    fclose(ptr1);
// }

void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */
    if (addressBook->contactCount >= 100)
    {
        printf("Address book is full!\n");
        return;
    }

    char name[100], phone[20], email[50];
    printf("%d",addressBook->contactCount);
    printf("Enter Name: ");
    
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
    //printf("%s",addressBook->contacts[addressBook->contactCount].name);
    
    int flag = 0;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(name, addressBook->contacts[i].name) == 0)
        {
            printf("Name already Exist, please try again");
            return;
        }
    }

    printf("Enter Phone number: ");
    scanf(" %[^\n]", phone);
    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (phone[i] >= '0' && phone[i] <= '9')
        {
            continue;
        }
        else
        {
            printf("Invalid Input");
            return;
        }
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            printf("Phone number already exists, please try again.\n");
            return;
        }
    }

    if (strlen(phone) != 10)
    {
        printf("Invalid phone number, please try again.\n");
        return;
    }

    printf("Enter Email: ");
    scanf(" %[^\n]", email);

    if (strstr(email, "@") == NULL || strstr(email, ".com") == NULL)
    {
        printf("Invalid email, please try again.\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(email, addressBook->contacts[i].email) == 0)
        {
            printf("Email already exists, please try again.\n");
            return;
        }
    }

    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);
    addressBook->contactCount++;

    printf("Contact created successfully.\n");
    //saveContactsToFile(addressBook);
}
void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */
    int choice;
    printf("Search Contact by:\n1. Name\n2. Email\n3.Phone\nEnter choice: ");
    scanf("%d", &choice);

    char searchTerm[50];
    int found = 0;

    switch (choice)
    {
    case 1:
        printf("Enter name: ");
        scanf(" %[^\n]", searchTerm);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(searchTerm, addressBook->contacts[i].name) == 0)
            {
                printf("Found: %s,  %s, %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                found = 1;
                break;
            }
        }
        break;
    case 2:
        printf("Enter email: ");
        scanf(" %[^\n]", searchTerm);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(searchTerm, addressBook->contacts[i].email) == 0)
            {
                printf("Found: %s, %s, %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                found = 1;
                break;
            }
        }
    case 3:
        printf("Enter phone: ");
        scanf(" %[^\n]", searchTerm);
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(searchTerm, addressBook->contacts[i].phone) == 0)
            {
                printf("Found: %s, %s, %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                found = 1;
                break;
            }
        }
        break;
    default:
        printf("Invalid choice.\n");
        return;
    }

    if (!found)
    {
        printf("No contact found.\n");
    }
}
void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    int e;
    printf("What do you want to edit ?\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Select Option No: ");
    scanf("%d", &e);

    switch (e)
    {
    case 1:
    {
        while (1)
        {
            char ename[50];
            printf("Enter Name: ");
            scanf(" %[^\n]", ename);
            int flag = 0;
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(ename, addressBook->contacts[i].name) == 0)
                {
                    printf("Your Entered Name is: %s\n", ename);
                    char new_name[50];
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", new_name);
                    strcpy(addressBook->contacts[i].name, new_name);
                    flag = 1;
                    printf("Edited Successfully.\n");
                    return;
                }
            }
            if (flag == 0)
            {
                printf("Name Not Found.\n");
            }
        }
        break;
    }
    case 2:
    {
        while (1)
        {
            char ephone[20];
            printf("Enter Phone No: ");
            scanf(" %[^\n]", ephone);
            int flag = 0;
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(ephone, addressBook->contacts[i].phone) == 0)
                {
                    printf("Your Entered Phone No is: %s\n", ephone);
                    char new_phone[20];
                    printf("Enter New Phone No: ");
                    scanf(" %[^\n]", new_phone);
                    strcpy(addressBook->contacts[i].phone, new_phone);
                    flag = 1;
                    printf("Edited Successfully.\n");
                    return;
                }
            }
            if (flag == 0)
            {
                printf("Phone No. Not Found.\n");
            }
        }
        break;
    }
    case 3:
    {
        while (1)
        {
            char eemail[50];
            printf("Enter Email: ");
            scanf(" %[^\n]", eemail);
            int flag = 0;
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(eemail, addressBook->contacts[i].email) == 0)
                {
                    printf("Your Entered Email is: %s\n", eemail);
                    char new_email[50];
                    printf("Enter New Email: ");
                    scanf(" %[^\n]", new_email);
                    strcpy(addressBook->contacts[i].email, new_email);
                    flag = 1;
                    printf("Edited Successfully.\n");
                    return;
                }
            }
            if (flag == 0)
            {
                printf("Email Not Found.\n");

            }
        }
    }

    break;
    default:
        printf("Please Enter Valid Option.\n");
        break;
    }
}

void deleteContact(AddressBook *addressBook)
{
        /* Define the logic for deletecontact */
    int n;
    printf("Delete Contact By\n1. Name\n2. Phone number\n3. Email\nSelect Option: ");
    scanf("%d", &n);
    char input[50];
    int flag = 0;

    switch(n) {
        case 1:
            printf("Enter name to delete contact: ");
            scanf(" %[^\n]", input);
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(input, addressBook->contacts[i].name) == 0)
                {
                    for (int j = i; j < addressBook->contactCount - 1; j++)
                    {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--;
                    flag = 1;
                    printf("Deleted Contact Successfully.\n");
                    break;
                }
            }
            if (!flag) {
                printf("Contact Not Found.\n");
            }
            break;
        case 2:
            printf("Enter phone number to delete contact: ");
            scanf(" %[^\n]", input);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(input, addressBook->contacts[i].phone) == 0) {
                    for (int j = i; j < addressBook->contactCount - 1; j++) {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--;
                    flag = 1;
                    printf("Deleted Contact Successfully.\n");
                    break;
                }
            }
            if (!flag) {
                printf("Contact Not Found.\n");
            }
            break;
        case 3:
            printf("Enter email to delete contact: ");
            scanf(" %[^\n]", input);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(input, addressBook->contacts[i].email) == 0) {
                    for (int j = i; j < addressBook->contactCount - 1; j++) {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--;
                    flag = 1;
                    printf("Deleted Contact Successfully.\n");
                    break;
                }
            }
            if (!flag) {
                printf("Contact Not Found.\n");
            }
            break;
        default:
            printf("Invalid Option.\n");
            break;
    }
    
saveContactsToFile(addressBook);
}