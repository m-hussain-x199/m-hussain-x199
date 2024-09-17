#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Menu display
void displayMenu(const char menu[][2][30], int size) {
    printf("----- Menu -----\n");
    for (int i = 0; i < size; ++i) {
        printf("%d. %s - $%s\n", i + 1, menu[i][0], menu[i][1]);
    }
    printf("----------------\n");
}

// Taking Order
void takeOrder(const char menu[][2][30], int size, char order[][2][30], int *orderCount) {
    while (1) {
        char choice[10];
        printf("Enter the number of the item you want to order (or 'done' to finish): ");
        scanf("%9s", choice); // limit input to 9 characters to prevent overflow
        if (strcmp(choice, "done") == 0) {
            break;
        }
        int index = atoi(choice) - 1;
        if (index >= 0 && index < size) {
            strcpy(order[*orderCount][0], menu[index][0]);
            strcpy(order[*orderCount][1], menu[index][1]);
            (*orderCount)++;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

// Calculate the total cost:
double calculateTotal(char order[][2][30], int orderCount) {
    double total = 0.0;
    for (int i = 0; i < orderCount; ++i) {
        total += atof(order[i][1]);
    }
    return total;
}

int main() {
    const int MENU_SIZE = 6;
    const char menu[MENU_SIZE][2][30] = {
        {"Pizza", "8.99"},
        {"Burger", "5.49"},
        {"Pasta", "7.99"},
        {"Salad", "4.99"},
        {"Soda", "1.99"},
        {"Coffee", "2.49"}
    };

    char order[100][2][30];
    int orderCount = 0;

    char action[10];
    printf("Would you like to see the menu or order directly? (menu/order): ");
    scanf("%9s", action);  // limit input to 9 characters
    
    if (strcmp(action, "menu") == 0) {
        displayMenu(menu, MENU_SIZE);
    }
    
    takeOrder(menu, MENU_SIZE, order, &orderCount);
    
    if (orderCount == 0) {
        printf("No items ordered.\n");
    } else {
        char calculate[10];
        printf("Do you want to calculate the total cost? (yes/no): ");
        scanf("%9s", calculate);  // limit input to 9 characters
        
        if (strcmp(calculate, "yes") == 0) {
            double total = calculateTotal(order, orderCount);
            printf("The total cost of your order is: $%.2f\n", total);
        }
        
        // For delivery:
        char name[50], address[100];
        printf("Please enter your name: ");
        scanf(" %[^\n]49s", name);  // limit input to 49 characters
        printf("Please enter your delivery address: ");
        scanf(" %[^\n]99s", address);  // limit input to 99 characters
        printf("Thank you, %s. Your order will be delivered to %s.\n", name, address);
    }

    return 0;
}
