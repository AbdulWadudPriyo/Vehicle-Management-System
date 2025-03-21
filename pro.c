

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Vehicle {
    char type[20];
    char model[20];
    char number[20];
    char entryTime[20];
    struct Vehicle* next;
};


struct Vehicle* createVehicle(char* type, char* model, char* number, char* entryTime) {
    struct Vehicle* newVehicle = (struct Vehicle*)malloc(sizeof(struct Vehicle));
    strcpy(newVehicle->type, type);
    strcpy(newVehicle->model, model);
    strcpy(newVehicle->number, number);
    strcpy(newVehicle->entryTime, entryTime);
    newVehicle->next = NULL;
    return newVehicle;
}


void addVehicle(struct Vehicle** head, char* type, char* model, char* number, char* entryTime) {
    struct Vehicle* newVehicle = createVehicle(type, model, number, entryTime);
    if (*head == NULL) {
        *head = newVehicle;
    } else {
        struct Vehicle* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newVehicle;
    }
    printf("Vehicle with number %s added successfully!\n", number);
}


void displayVehicles(struct Vehicle* head) {
    if (head == NULL) {
        printf("No vehicles parked.\n");
        return;
    }

    printf("\nParked Vehicles:\n");
    printf("Type\t\tModel\t\tNumber\t\tEntryTime\n");
    printf("------------------------------------------------------------\n");

    struct Vehicle* temp = head;
    while (temp != NULL) {
        printf("%s\t\t%s\t\t%s\t\t%s\n", temp->type, temp->model, temp->number, temp->entryTime);
        temp = temp->next;
    }
}


void removeVehicle(struct Vehicle** head, char* number) {
    if (*head == NULL) {
        printf("No vehicles parked.\n");
        return;
    }

    struct Vehicle* temp = *head;
    struct Vehicle* prev = NULL;

    while (temp != NULL && strcmp(temp->number, number) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Vehicle with number %s not found.\n", number);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Vehicle with number %s removed successfully!\n", number);
}


void searchVehicle(struct Vehicle* head, char* number) {
    if (head == NULL) {
        printf("No vehicles parked.\n");
        return;
    }

    struct Vehicle* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->number, number) == 0) {
            printf("\nVehicle Found:\n");
            printf("Type: %s\n", temp->type);
            printf("Model: %s\n", temp->model);
            printf("Number: %s\n", temp->number);
            printf("Entry Time: %s\n", temp->entryTime);
            return;
        }
        temp = temp->next;
    }

    printf("Vehicle with number %s not found.\n", number);
}

int main() {
    struct Vehicle* head = NULL;
    int choice;
    char type[20], model[20], number[20], entryTime[20];


    printf("\t\t\t\t<Welcome to Vehicle Parking System>\n");

    while (choice != 5){
        printf("\nChoices are:\n");
        printf("1. Add Vehicle\n");
        printf("2. Display Parked Vehicles\n");
        printf("3. Remove Vehicle\n");
        printf("4. Search Vehicle\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter vehicle type: ");
                scanf("%s", type);
                printf("Enter vehicle model: ");
                scanf("%s", model);
                printf("Enter vehicle number: ");
                scanf("%s", number);
                printf("Enter entry time: ");
                scanf("%s", entryTime);
                addVehicle(&head, type, model, number, entryTime);
                break;

            case 2:
                displayVehicles(head);
                break;

            case 3:
                printf("Enter vehicle number to remove: ");
                scanf("%s", number);
                removeVehicle(&head, number);
                break;

            case 4:
                printf("Enter vehicle number to search: ");
                scanf("%s", number);
                searchVehicle(head, number);
                break;

            case 5:
                printf("Exiting the system.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
