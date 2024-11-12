#include <stdio.h>
#include <string.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    float price;
    float mileage;
};

void addCar(struct Car cars[], int *count) {
    struct Car newCar;
    
    printf("Enter make: ");
    scanf("%49s", newCar.make); 
    printf("Enter model: ");
    scanf("%49s", newCar.model);
    printf("Enter year: ");
    scanf("%d", &newCar.year);
    printf("Enter price: ");
    scanf("%f", &newCar.price);
    printf("Enter mileage: ");
    scanf("%f", &newCar.mileage);
    
    cars[*count] = newCar;
    (*count)++;  
}

void displayCars(struct Car cars[], int count) {
    if (count == 0) {
        printf("No cars available.\n");
    } else {
        printf("\nAvailable Cars:\n");
        for (int i = 0; i < count; i++) {
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: %.2f\n", cars[i].price);
            printf("Mileage: %.2f\n", cars[i].mileage);
            printf("------------------------\n");
        }
    }
}

void searchCars(struct Car cars[], int count) {
    char searchTerm[50];
    int found = 0;
    
    printf("Enter make or model to search: ");
    scanf("%49s", searchTerm);
    
    printf("\nSearch Results:\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].make, searchTerm) == 0 || strcmp(cars[i].model, searchTerm) == 0) {
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: %.2f\n", cars[i].price);
            printf("Mileage: %.2f\n", cars[i].mileage);
            printf("------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No cars found matching your search.\n");
    }
}

int main() {
    struct Car cars[100]; 
    int count = 0;         
    int choice;
    
    while (1) {
        printf("\nCar Dealership Menu:\n");
        printf("1. Add a new car\n");
        printf("2. Display available cars\n");
        printf("3. Search for cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar(cars, &count);
                break;
            case 2:
                displayCars(cars, count);
                break;
            case 3:
                searchCars(cars, count);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
