#include <stdio.h>

int main() {
   
    const int price_per_bolt = 5; 
    const int price_per_nut = 3;  
    const int price_per_washer = 1; 

    int bolts, nuts, washers;

    printf("Enter the number of bolts: ");
    scanf("%d", &bolts);

    printf("Enter the number of nuts: ");
    scanf("%d", &nuts);

    printf("Enter the number of washers: ");
    scanf("%d", &washers);

    int error = 0;

    if (nuts < bolts) {
        printf("Check the Order: too few nuts\n");
        error = 1;
    }

    if (washers < 2 * bolts) {
        printf("Check the Order: too few washers\n");
        error = 1;
    }

    if (error == 0) {
        int total_cost = (bolts * price_per_bolt) + (nuts * price_per_nut) + (washers * price_per_washer);
        printf("Order is OK.\n");
        printf("Total cost: %d cents.\n", total_cost);
    }

    return 0;
}
