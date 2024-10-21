#include <stdio.h>
#include "file_handler.h"  
#include "dyno_array.h"    

int main() {
    int choice, id;
    char name[50], work[50];


    DynoArray* array = initArray(2);


    const char* filepath = "database.dat";


    loadFromFile(array, filepath);

    while (1) {
        printf("\n Mini-Database System\n");
        printf("1. Add Record\n");
        printf("2. Remove Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Work: ");
                scanf("%s", work);
                addRecord(array, id, name, work);  
                saveToFile(array, filepath);      
                break;
            case 2:
                printf("Enter ID to remove: ");
                scanf("%d", &id);
                removeRecord(array, id);          
                saveToFile(array, filepath);       
                break;
            case 3:
                displayRecords(array);             
                break;
            case 4:
                printf("Exiting...\n");
                saveToFile(array, filepath);      
                freeArray(array);                  
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
