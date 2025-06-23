#include <stdio.h>
#include "file.h"

// void saveContactsToFile(AddressBook *addressBook) {
  
// }

void loadContactsFromFile(AddressBook *addressBook) {
     FILE *fptr;
    fptr=fopen("file.csv","r");
    if(fptr==NULL)
    {
        printf("Error while opening file.\n");
        return;
    }
    addressBook->contactCount=0;
    while (fscanf(fptr,"%[^,],%[^,],%[^\n]\n",
    addressBook->contacts[addressBook->contactCount].name,
    addressBook->contacts[addressBook->contactCount].phone,
    addressBook->contacts[addressBook->contactCount].email)!=EOF)
    {
        addressBook->contactCount++;
    }
   
    
}
