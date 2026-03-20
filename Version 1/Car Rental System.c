#include <stdio.h>
#include <string.h>

#define MAX_CARS 5

typedef struct {
    char name[30];
    float rentalRate;
    int available;
} Car;

Car cars[MAX_CARS] = {
    {"Toyota Camry", 50.0, 1},
    {"Honda Accord", 55.0, 1},
    {"Ford Mustang", 70.0, 1},
    {"Chevrolet Malibu", 60.0, 1},
    {"Nissan Altima", 65.0, 1}
};

void displayAvailableCars() {
    printf("Available Cars:\n");
    for (int i = 0; i < MAX_CARS; i++) {
        if (cars[i].available) {
            printf("%d. %s - $%.2f per day\n", i + 1, cars[i].name, cars[i].rentalRate);
        }
    }
}

void rentCar(int index, int days) {
    if (cars[index].available) {
        cars[index].available = 0;
        printf("Rented %s for %d days. Total cost: $%.2f\n", cars[index].name, days, cars[index].rentalRate * days);
    } else {
        printf("%s is not available.\n", cars[index].name);
    }
}

void returnCar(int index) {
    if (!cars[index].available) {
        cars[index].available = 1;
        printf("Returned %s. Thank you!\n", cars[index].name);
    } else {
        printf("%s was not rented.\n", cars[index].name);
    }
}

int main() {
    char name[40];
    int choice, days, carIndex;
  printf("Enter your name:");
  fgets(name,40,stdin);
    while (1) {
        printf("\n1. Display Cars\n2. Rent a Car\n3. Return a Car\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableCars();
                break;
            case 2:
                displayAvailableCars();
                printf("Select a car (1-%d): ", MAX_CARS);
                scanf("%d", &carIndex);
                if (carIndex >= 1 && carIndex <= MAX_CARS) {
                    printf("Days to rent: ");
                    scanf("%d", &days);
                    rentCar(carIndex - 1, days);
                } else {
                    printf("Invalid selection.\n");
                }
                break;
            case 3:
                displayAvailableCars();
                printf("Select a car to return (1-%d): ", MAX_CARS);
                scanf("%d", &carIndex);
                if (carIndex >= 1 && carIndex <= MAX_CARS) {
                    returnCar(carIndex - 1);
                } else {
                    printf("Invalid selection.\n");
                }
                break;
            case 4:
                printf("Goodbye! %s\n",name);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}